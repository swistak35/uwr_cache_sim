#ifndef BLOCK_H
#define BLOCK_H

struct Block {
  long int address;
  bool valid_bit;
  bool LRU_bit;
  bool dirty_bit;
};

#endif
