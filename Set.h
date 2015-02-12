#ifndef SET_H
#define SET_H

#include <cstdlib>
#include "LRUAlgorithmFactory.h"
#include "LRUAlgorithm.h"

using namespace std;

class Set {
  public:
    Set();
    ~Set();
    void setup(int setCap, int blockCap);
    bool findTag(long int address, bool replace);

    void setAlgorithm(LRUAlgorithmFactory * algFactory);
    int blockCount;
    int blockCap;
    struct Block {
      long int address;
      bool valid_bit;
      bool LRU_bit;
    };
    struct Block* blocks;
  private:
    LRUAlgorithm * alg;
};

#endif
