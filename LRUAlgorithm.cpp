#include "LRUAlgorithm.h"

LRUAlgorithm::LRUAlgorithm(int blockCount, Block * blocks) {
  this->recentlyUsedCount = 0;
  this->blockCount = blockCount;
  this->blocks = blocks;
}

LRUAlgorithm::~LRUAlgorithm() {
}

int LRUAlgorithm::findBest() {  
  for (int i = 0; i < this->blockCount; i++) {
    // Nigdy nie będzie tak zeby pewna uzywana komorka miala LRU_bit = 0 a nie wszystkie bylyby uzywane.
    if (!this->blocks[i].valid_bit || !this->blocks[i].LRU_bit) {
      return i;
    }
  }
  return -1;
}

void LRUAlgorithm::use(int index) {
  this->recentlyUsedCount += (this->blocks[index].LRU_bit ? 0 : 1);

  if (this->recentlyUsedCount >= this->blockCount) {
    for (int i = 0; i < this->blockCount; i++) {
      this->blocks[i].LRU_bit = false;
    }
    this->recentlyUsedCount = 1;
  }

  this->blocks[index].LRU_bit = true;	
}
