#ifndef RANDOM_ALGORITHM_H
#define RANDOM_ALGORITHM_H

#include <cstdlib>
#include <ctime>
#include "Block.h"
#include "AbstractAlgorithm.h"

using namespace std;

class RandomAlgorithm: public AbstractAlgorithm {
  public:
    RandomAlgorithm(int blockCount, Block * blocks);
    ~RandomAlgorithm();
    void use(int index);
    int findBest();
    int blockCount;
    Block * blocks;
};

#endif
