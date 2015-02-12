#include <iostream>
#include "StructReader.h"
#include "LRUAlgorithmFactory.h"
#include "Cache.h"

using namespace std;

int main() {
  StructReader odczyt;
  LRUAlgorithmFactory algo;
  
  Cache* cache = new Cache(12, 10, 6, &odczyt, &algo);
  cache->start();

  return 0;
}
