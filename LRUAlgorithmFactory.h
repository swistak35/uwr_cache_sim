#ifndef LRU_ALGORITHM_FACTORY_H
#define LRU_ALGORITHM_FACTORY_H

#include "LRUAlgorithm.h"

using namespace std;

class LRUAlgorithmFactory {
  public:
    LRUAlgorithmFactory();
    ~LRUAlgorithmFactory();
    LRUAlgorithm * getInstance();
};

#endif
