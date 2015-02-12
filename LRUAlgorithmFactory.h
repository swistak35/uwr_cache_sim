#ifndef LRU_ALGORITHM_FACTORY_H
#define LRU_ALGORITHM_FACTORY_H

#include "Block.h"
#include "LRUAlgorithm.h"

using namespace std;

class LRUAlgorithmFactory {
  public:
    LRUAlgorithmFactory();
    ~LRUAlgorithmFactory();
    LRUAlgorithm * getInstance(int blockCount, Block * blocks);
};

#endif
