#include <iostream>
#include "StructReader.h"
#include "LRUAlgorithmFactory.h"
#include "RandomAlgorithmFactory.h"
#include "Cache.h"

using namespace std;

int main() {
  StructReader odczyt("testprogram.trace.bin");
  LRUAlgorithmFactory algo;
  
  Cache* cache = new Cache(12, 10, 8, &odczyt, &algo);
  cache->start();

  StructReader odczyt2("testprogram2.trace.bin");
  LRUAlgorithmFactory algo2;
  
  Cache* cache2 = new Cache(12, 10, 8, &odczyt2, &algo2);
  cache2->start();

  /* StructReader odczyt2; */
  /* RandomAlgorithmFactory algo2; */
  
  /* Cache* cache2 = new Cache(12, 10, 6, &odczyt2, &algo2); */
  /* cache2->start(); */

  return 0;
}
