#ifndef LRU_ALGORITHM_FACTORY_H
#define LRU_ALGORITHM_FACTORY_H

#include "Block.h"
#include "AbstractAlgorithmFactory.h"
#include "LRUAlgorithm.h"

using namespace std;

class LRUAlgorithmFactory: public AbstractAlgorithmFactory {
  public:
    LRUAlgorithmFactory();
    ~LRUAlgorithmFactory();
    LRUAlgorithm * getInstance(int blockCount, Block * blocks);
};

#endif
