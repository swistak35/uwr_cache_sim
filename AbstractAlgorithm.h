#ifndef ABSTRACT_ALGORITHM_H
#define ABSTRACT_ALGORITHM_H

#include "Block.h"

using namespace std;

class AbstractAlgorithm {
  public:
    virtual void use(int index) = 0;
    virtual int findBest() = 0;
    int blockCount;
    Block * blocks;
};

#endif
