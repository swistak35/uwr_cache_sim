#ifndef CACHE_H
#define CACHE_H

#include <iostream>
#include "StructReader.h"
#include "LRUAlgorithmFactory.h"
#include "Set.h"

using namespace std;

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


    Cache(int cacheCap, int setCap, int blockCap, StructReader * reader, LRUAlgorithmFactory * algFactory);
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
		WriteThroughCache(int cacheCap, int setCap, int blockCap, StructReader * reader, LRUAlgorithmFactory * algFactory): Cache(cacheCap, setCap, blockCap, reader, algFactory)
	 	{};
	private:
		void read(long int address);
		void write(long int adress);
};

#endif
