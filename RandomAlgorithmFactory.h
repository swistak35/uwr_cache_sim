#ifndef RANDOM_ALGORITHM_FACTORY_H
#define RANDOM_ALGORITHM_FACTORY_H

#include "Block.h"
#include "AbstractAlgorithmFactory.h"
#include "RandomAlgorithm.h"

using namespace std;

class RandomAlgorithmFactory: public AbstractAlgorithmFactory {
  public:
    RandomAlgorithmFactory();
    ~RandomAlgorithmFactory();
    RandomAlgorithm * getInstance(int blockCount, Block * blocks);
};

#endif
