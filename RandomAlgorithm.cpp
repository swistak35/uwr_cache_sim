#include "RandomAlgorithm.h"

RandomAlgorithm::RandomAlgorithm(int blockCount, Block * blocks) {
  this->blockCount = blockCount;
  this->blocks = blocks;
  srand(time(NULL));
}

RandomAlgorithm::~RandomAlgorithm() {
}

int RandomAlgorithm::findBest() {  
  return (rand() % this->blockCount);
}

void RandomAlgorithm::use(int index) {
}
