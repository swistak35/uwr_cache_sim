#include "LRUAlgorithmFactory.h"

LRUAlgorithmFactory::LRUAlgorithmFactory() {
}

LRUAlgorithmFactory::~LRUAlgorithmFactory() {
}

LRUAlgorithm * LRUAlgorithmFactory::getInstance() {
  LRUAlgorithm * alg = new LRUAlgorithm();
  return alg;
}
