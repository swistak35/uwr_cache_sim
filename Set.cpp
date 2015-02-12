#include "Set.h"

Set::Set() {
}

Set::~Set() {
}

void Set::setup(int setCap, int blockCap)
{
  this->blockCount = 1<<setCap-blockCap;
  this->blockCap = blockCap;
  blocks = (struct Block*) malloc(sizeof(struct Block) * blockCount);
}

void Set::setAlgorithm(LRUAlgorithmFactory * algFactory) {
  this->alg = algFactory->getInstance();
}

bool Set::findTag(long int tag, bool replace)
  for(int i = 0; i < this->blockCount; i++) {
    if(this->blocks[i].address == tag) {
      alg->use(i);
      return true;
    }
  }
  int index = alg->findBest();
  alg->use(index);
  this->blocks[index].valid_bit = true;
  this->blocks[index].address = tag;
  return false;
}
