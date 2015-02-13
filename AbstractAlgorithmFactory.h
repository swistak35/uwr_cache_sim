#ifndef ABSTRACT_ALGORITHM_FACTORY_H
#define ABSTRACT_ALGORITHM_FACTORY_H

#include "Block.h"
#include "AbstractAlgorithm.h"

using namespace std;

class AbstractAlgorithmFactory {
  public:
    AbstractAlgorithmFactory() {};
    ~AbstractAlgorithmFactory() {};
    virtual AbstractAlgorithm * getInstance(int blockCount, Block * blocks) = 0;
};

#endif
