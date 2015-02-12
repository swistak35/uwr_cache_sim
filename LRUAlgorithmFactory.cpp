#include "LRUAlgorithmFactory.h"

LRUAlgorithmFactory::LRUAlgorithmFactory() {
}

LRUAlgorithmFactory::~LRUAlgorithmFactory() {
}

LRUAlgorithm * LRUAlgorithmFactory::getInstance(int blockCount, Block * blocks) {
  LRUAlgorithm * alg = new LRUAlgorithm(blockCount, blocks);
  return alg;
}
