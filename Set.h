#ifndef SET_H
#define SET_H

#include <cstdlib>

using namespace std;

  class Set 
  {
		public:
			void setup(int setCap, int blockCap);
			bool findTag(long int address, bool replace);
			Set(){recentlyUsedCount = 0;};
		private:
			int recentlyUsedCount;
			int blockCount;
			int blockCap;
			int findBestIndex();
			void LRU_algorithm(int i);
			struct  Block {
				long int address;
				bool valid_bit;
				bool LRU_bit;
			};
			struct Block* blocks;
  };

#endif
