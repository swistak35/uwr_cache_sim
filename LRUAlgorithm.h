#ifndef LRU_ALGORITHM_H
#define LRU_ALGORITHM_H

#include "Block.h"

using namespace std;

class LRUAlgorithm {
  public:
    LRUAlgorithm(int blockCount, Block * blocks);
    ~LRUAlgorithm();
    void use(int index);
    int findBest();
  private:
    int recentlyUsedCount;
    int blockCount;
    Block * blocks;
};

#endif
