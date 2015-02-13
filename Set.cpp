#include "Set.h"

Set::Set() {
}

Set::~Set() {
}

void Set::setup(int setCap, int blockCap)
{
  this->blockCount = 1<<setCap-blockCap;
  this->blockCap = blockCap;
  this->blocks = (struct Block*) malloc(sizeof(struct Block) * blockCount);
  for (int i = 0; i < this->blockCount; i++) {
    blocks[i].valid_bit = false;
    blocks[i].LRU_bit = false;
  }
}

void Set::setAlgorithm(AbstractAlgorithmFactory * algFactory) {
  this->alg = algFactory->getInstance(this->blockCount, this->blocks);
}

pair<bool, int> Set::findTag(long int tag, bool replace) 
{
	pair<bool, int> p;
  for(int i = 0; i < this->blockCount; i++) 
  {
    if (this->blocks[i].valid_bit && (this->blocks[i].address == tag)) 
    {
      alg->use(i);
      return pair<bool, int>(true, i);
    }
  }
  if (replace) {
    int index = loadTag(tag);
    return pair<bool, int>(false, index);
  }
}

int Set::loadTag(long int tag) {
  int index = alg->findBest();
  alg->use(index);
  this->blocks[index].valid_bit = true;
  this->blocks[index].address = tag;
  return index;
}
