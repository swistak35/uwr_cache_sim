#include <array>
#include "StructReader.h"

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

class Cache 
{
public:
	StructReader * reader;
	Set* sets;
	int setCount;
	int cacheCap;
  int blockCap;
  int cacheRef = 0;
  int ramRef = 0;
  int memRef = 0;
  int hits = 0;
  
  
  Cache(int cacheCap, int setCap, int blockCap, StructReader * reader);
  ~Cache();
  void start();
  bool cacheReference(long int address, bool replace);
  void ramReference();
  
private:
  virtual void read(long int address);
  virtual void write(long int address);
};

class WriteThroughCache : public Cache
{
	public:
		WriteThroughCache(int cacheCap, int setCap, int blockCap, StructReader * reader): Cache(cacheCap, setCap, blockCap, reader)
	 	{};
	private:
		void read(long int address);
		void write(long int adress);
};


