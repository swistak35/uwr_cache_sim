#ifndef LRU_ALGORITHM_H
#define LRU_ALGORITHM_H

#include "Block.h"
#include "AbstractAlgorithm.h"

using namespace std;

class LRUAlgorithm: public AbstractAlgorithm {
  public:
    LRUAlgorithm(int blockCount, Block * blocks);
    ~LRUAlgorithm();
    void use(int index);
    int findBest();
    int blockCount;
    Block * blocks;
  private:
    int recentlyUsedCount;
};

#endif
