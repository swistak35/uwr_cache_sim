#include "FullyAssociativeCache.h"


Cache::Cache(int cacheCap, int setCap, int blockCap, StructReader * reader) {
  this->reader = reader;
	this->setCount = 1<<(cacheCap-setCap);
  sets = new Set[setCount];
  for(int i = 0; i< setCount; i++)
  	sets[i].setup(setCap, blockCap);
	this->cacheCap = cacheCap;
	this->blockCap = blockCap;
	
}

Cache::~Cache() {
}

void Cache::start() {
  int get_result = 0;
  mtrace_t tmp;

  while (true) {
    get_result = reader->get(&tmp);
    if (get_result)
      break;
		
		this->memRef++;
    if (tmp.is_write) 
      write(tmp.address);
    else
     	read(tmp.address);
  }
    /* cout << "Pobrano: " << tmp.address << " " << tmp.is_write << " " << +tmp.size << endl; */

  float ratio = float(hits) * 100 / memRef;
  cout << cacheRef << " odwołan do cache" << endl;
  cout << ramRef << " odwołan do ram" << endl;
  cout << "Udalo sie " << hits << "/" << memRef << " (" << ratio << "%)"<< endl;
}

void Cache::read(long int address) 
{
	if (cacheReference(address, true))
		hits++;
	else
		ramReference();
}

void Cache::write(long int address) {
  read(address);
}
void Cache::ramReference()
{
	ramRef++;
}
bool Cache::cacheReference(long int address, bool replace)
{
	int set = (address>>this->blockCap)%setCount;
	long int tag = address>>(blockCap+setCount);
	cacheRef++;
		
	return this->sets[set].findTag(tag, replace);
}
void WriteThroughCache::read(long int address)
{
		if(this->cacheReference(address, false)) // odwolanie do cache i znalezienie bloku do wymiany
			hits++;
		else
		{
			ramReference(); // sciagniecie danych z ramu
			cacheReference(address, true); //zapisanie do cache
		}
}
void WriteThroughCache::write(long int address)
{
	if(this->cacheReference(address, false)) // zapisanie do cache jesli w nim jest
		hits++;
	ramReference(); //zapis do pamieci
}

void Set::setup(int setCap, int blockCap)
{
	this->blockCount = 1<<setCap-blockCap;
	this->blockCap = blockCap;
	blocks = (struct Block*) malloc(sizeof(struct Block) * blockCount);
}


bool Set::findTag(long int tag, bool replace)
{
	for(int i = 0; i < this->blockCount; i++)
		if(this->blocks[i].address == tag)
		{
			LRU_algorithm(i);
			return true;
		}
		if( replace )
		{
			int index = this->findBestIndex();
			LRU_algorithm(index);
			this->blocks[index].valid_bit = true;
			this->blocks[index].address = tag;
		}
		return false;
}


int Set::findBestIndex()
{  
  for (int i = 0; i < this->blockCount; i++)
  	// Nigdy nie będzie tak zeby pewna uzywana komorka miala LRU_bit = 0 a nie wszystkie bylyby uzywane.
    if (!this->blocks[i].valid_bit || !this->blocks[i].LRU_bit) 
    	return i;
}

void Set::LRU_algorithm(int index)
{
	recentlyUsedCount += (blocks[index].LRU_bit) ? 0 : 1;
	if(recentlyUsedCount == blockCount)
	{
		for(int i = 0; i < blockCount; i++)
			blocks[i].LRU_bit = false;
		recentlyUsedCount = 1;
	}
	
	blocks[index].LRU_bit = true;	
}
