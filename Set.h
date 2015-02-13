#ifndef SET_H
#define SET_H

#include <utility>
#include <cstdlib>
#include "Block.h"
#include "AbstractAlgorithmFactory.h"
#include "AbstractAlgorithm.h"

using namespace std;


class Set {
  public:
    Set();
    ~Set();
    void setup(int setCap, int blockCap);
    pair<bool,int> findTag(long int address, bool replace);

    void setAlgorithm(AbstractAlgorithmFactory * algFactory);
    int blockCount;
    int blockCap;
    struct Block* blocks;
  private:
    AbstractAlgorithm * alg;
};

#endif
