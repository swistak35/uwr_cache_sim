#include <iostream>
#include "StructReader.h"
#include "FullyAssociativeCache.h"

using namespace std;

int main() {
  StructReader odczyt;

  FullyAssociativeCache cache_model(&odczyt);
  cache_model.start();

  return 0;
}
