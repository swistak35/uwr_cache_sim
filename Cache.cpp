#include "Cache.h"

Cache::Cache(int cacheCap, int setCap, int blockCap, StructReader * reader, AbstractAlgorithmFactory * algFactory) {
  this->reader = reader;
  this->setCount = 1<<(cacheCap-setCap);
  sets = new Set[setCount];
  for(int i = 0; i< setCount; i++) {
    sets[i].setup(setCap, blockCap);
    sets[i].setAlgorithm(algFactory);
  }
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
	if (cacheReference(address, true).first)
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
pair<bool,int> Cache::cacheReference(long int address, bool replace)
{
	int set = (address>>this->blockCap)%setCount;
	long int tag = address>>(blockCap+setCount);
	cacheRef++;
		
	return this->sets[set].findTag(tag, replace);
}
void WriteThroughCache::read(long int address)
{
		if(this->cacheReference(address, false).first) // odwolanie do cache i znalezienie bloku do wymiany
			hits++;
		else
		{
			ramReference(); // sciagniecie danych z ramu
			cacheReference(address, true); //zapisanie do cache
		}
}

void WriteThroughCache::write(long int address)
{
	if(this->cacheReference(address, false).first) // zapisanie do cache jesli w nim jest
		hits++;
	ramReference(); //zapis do pamieci
}

pair<bool, int> WriteBackCache::cacheReference(long int address, bool replace)
{
	int set = (address>>this->blockCap)%setCount;
	long int tag = address>>(blockCap+setCount);
	cacheRef++;
		
	pair<bool, int> p = this->sets[set].findTag(tag, replace);
	return p;
}

void WriteBackCache::read(long int address)
{
	int set = (address>>this->blockCap)%setCount;
	pair<bool, int> p = cacheReference(address, false);
	if(!p.first)
	{
		if(this->sets[set].blocks[p.second].dirty_bit)
			ramReference();
		ramReference();
		cacheReference(address, true);
		this->sets[set].blocks[p.second].dirty_bit = false;
	}
}
void WriteBackCache::write(long int address)
{
	int set = (address>>this->blockCap)%setCount;
	pair<bool, int> p = this->cacheReference(address, false); 
	if(p.first)
		hits++;
	else
	{
		if(p.second)
			ramReference(); // zapisuje stary
		ramReference(); //wczytuje nowy
		this->cacheReference(address, true); // zapisuje
	}
	this->sets[set].blocks[p.second].dirty_bit = true;
	
}

