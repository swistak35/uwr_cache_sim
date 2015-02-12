#include "Cache.h"

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

      if (op_result) {
	hits++;
      }
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
