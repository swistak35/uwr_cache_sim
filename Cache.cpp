#include "FullyAssociativeCache.h"


Cache::Cache(int cacheCap, int blockCap, int setCap, StructReader * reader) {
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
  int op_result = 0;
  int ops = 0;
  int hits = 0;
  mtrace_t tmp;

  while (get_result == 0) {
    get_result = reader->get(&tmp);

    if (!get_result) {
      ops++;

      if (tmp.is_write) {
	op_result = write(tmp.address);
      } else {
	op_result = read(tmp.address);
      }

      hits+=op_result;
    }
  }
  /* cout << "Pobrano: " << tmp.address << " " << tmp.is_write << " " << +tmp.size << endl; */

  float ratio = float(hits) * 100 / ops;
  cout << "Udalo sie " << hits << "/" << ops << " (" << ratio << "%)"<< endl;
}

bool Cache::read(long int address) {
  int set = (address>>this->blockCap)%setCount;
  long int tag = address>>(blockCap+setCount);

  return this->sets[set].findTag(tag);
}

bool Cache::write(long int address) {
  return read(address);
}

void Set::setup(int setCap, int blockCap)
{
  this->blockCount = 1<<setCap-blockCap;
  this->blockCap = blockCap;
  blocks = (struct Block*) malloc(sizeof(struct Block) * blockCount);
}


bool Set::findTag(long int tag)
{
  for(int i = 0; i < this->blockCount; i++)
    if(this->blocks[i].address == tag)
    {
      LRU_algorithm(i);
      return true;
    }
  int index = this->findBestIndex();
  LRU_algorithm(index);
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
    for(int i = 0; i < blockCount; i++)
      blocks[i].LRU_bit = false;

  blocks[index].LRU_bit = true;	
}
