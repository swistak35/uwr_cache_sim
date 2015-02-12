#ifndef CACHE_H
#define CACHE_H

#include <iostream>
#include "StructReader.h"
#include "Set.h"


using namespace std;

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

#endif
