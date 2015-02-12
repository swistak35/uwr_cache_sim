#include "Set.h"

void Set::setup(int setCap, int blockCap)
{
	this->blockCount = 1<<setCap-blockCap;
	this->blockCap = blockCap;
	blocks = (struct Block*) malloc(sizeof(struct Block) * blockCount);
}


bool Set::findTag(long int tag, bool replace)
{
	for(int i = 0; i < this->blockCount; i++)
		if(this->blocks[i].address == tag)
		{
			LRU_algorithm(i);
			return true;
		}
		if( replace )
		{
			int index = this->findBestIndex();
			LRU_algorithm(index);
			this->blocks[index].valid_bit = true;
			this->blocks[index].address = tag;
		}
		return false;
}


int Set::findBestIndex()
{  
  for (int i = 0; i < this->blockCount; i++)
  	// Nigdy nie będzie tak zeby pewna uzywana komorka miala LRU_bit = 0 a nie wszystkie bylyby uzywane.
    if (!this->blocks[i].valid_bit || !this->blocks[i].LRU_bit) 
    	return i;
}

void Set::LRU_algorithm(int index)
{
	recentlyUsedCount += (blocks[index].LRU_bit) ? 0 : 1;
	if(recentlyUsedCount == blockCount)
	{
		for(int i = 0; i < blockCount; i++)
			blocks[i].LRU_bit = false;
		recentlyUsedCount = 1;
	}
	
	blocks[index].LRU_bit = true;	
}
