#include "RandomAlgorithmFactory.h"

RandomAlgorithmFactory::RandomAlgorithmFactory() {
}

RandomAlgorithmFactory::~RandomAlgorithmFactory() {
}

RandomAlgorithm * RandomAlgorithmFactory::getInstance(int blockCount, Block * blocks) {
  RandomAlgorithm * alg = new RandomAlgorithm(blockCount, blocks);
  return alg;
}
