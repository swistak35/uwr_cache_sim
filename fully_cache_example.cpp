#include <iostream>
#include "StructReader.h"
#include "Cache.h"

using namespace std;

int main() {
  StructReader odczyt;

  Cache cache_model(13, 11, 3, &odczyt);
  cache_model.start();

  return 0;
}
