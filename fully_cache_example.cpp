#include <iostream>
#include "StructReader.h"
#include "FullyAssociativeCache.h"

using namespace std;

int main() {
  StructReader odczyt;

  Cache* cache = new Cache(12, 10, 6, &odczyt);
  cache->start();

  return 0;
}
