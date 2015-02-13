#ifndef SET_H
#define SET_H

#include <utility>
#include <cstdlib>
#include "Block.h"
#include "LRUAlgorithmFactory.h"
#include "LRUAlgorithm.h"

using namespace std;


class Set {
  public:
    Set();
    ~Set();
    void setup(int setCap, int blockCap);
    pair<bool,int> findTag(long int address, bool replace);

    void setAlgorithm(LRUAlgorithmFactory * algFactory);
    int blockCount;
    int blockCap;
    struct Block* blocks;
  private:
    LRUAlgorithm * alg;
};

#endif
