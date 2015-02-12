#include "LRUAlgorithm.h"

LRUAlgorithm::LRUAlgorithm() {
  /* this->set = set; */
  this->recentlyUsedCount = 0;
}

LRUAlgorithm::~LRUAlgorithm() {
}

int LRUAlgorithm::findBest() {  
  /* for (int i = 0; i < this->set->blockCount; i++) { */
  /*   // Nigdy nie będzie tak zeby pewna uzywana komorka miala LRU_bit = 0 a nie wszystkie bylyby uzywane. */
  /*   if (!this->set->blocks[i].valid_bit || !this->set->blocks[i].LRU_bit) { */
  /*     return i; */
  /*   } */
  /* } */
  /* return -1; */
  return 0;
}

void LRUAlgorithm::use(int index) {
  /* this->recentlyUsedCount += (this->set->blocks[index].LRU_bit) ? 0 : 1; */

  /* if (this->recentlyUsedCount == this->set->blockCount) { */
  /*   for (int i = 0; i < this->set->blockCount; i++) { */
  /*     this->set->blocks[i].LRU_bit = false; */
  /*   } */
  /* } */

  /* this->set->blocks[index].LRU_bit = true; */	
}
