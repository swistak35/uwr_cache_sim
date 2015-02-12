#include <array>
#include "StructReader.h"

using namespace std;

class Set
{
  public:
    void setup(int setCap, int blockCap);
    bool findTag(long int address);
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

class Cache {
  public:
    Cache(int cacheCap, int setCap, int blockCap, StructReader * reader);
    ~Cache();
    void start();
  private:
    StructReader * reader;
    Set* sets;
    int setCount;
    int cacheCap;
    int blockCap;

    bool read(long int address);
    bool write(long int address);
    int find_best_index();

    struct row * rows;
};


