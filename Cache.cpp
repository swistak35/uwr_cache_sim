#include "Cache.h"

Cache::Cache(int cacheCap, int setCap, int blockCap, StructReader * reader, LRUAlgorithmFactory * algFactory) {
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
