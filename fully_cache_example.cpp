#include <iostream>
#include "StructReader.h"
#include "LRUAlgorithmFactory.h"
#include "RandomAlgorithmFactory.h"
#include "Cache.h"

using namespace std;

int main() {
  StructReader odczyt;
  LRUAlgorithmFactory algo;
  
  Cache* cache = new Cache(12, 10, 8, &odczyt, &algo);
  cache->start();

  StructReader odczyt2;
  LRUAlgorithmFactory algo2;
  
  Cache* cache2 = new Cache(12, 10, 8, &odczyt2, &algo2);
  cache2->optionPrefetching = true;
  cache2->start();

  /* StructReader odczyt2; */
  /* RandomAlgorithmFactory algo2; */
  
  /* Cache* cache2 = new Cache(12, 10, 6, &odczyt2, &algo2); */
  /* cache2->start(); */

  return 0;
}
