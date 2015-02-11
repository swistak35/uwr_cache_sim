#include <array>
#include "StructReader.h"

using namespace std;

class FullyAssociativeCache {
public:
  FullyAssociativeCache(StructReader * reader);
  ~FullyAssociativeCache();
  void start();
private:
  StructReader * reader;
  int rows_count;
  int current_timestamp;

  struct row {
    long int address;
    bool valid_bit;
    int timestamp;
  };
  bool read(long int address);
  bool write(long int address);
  int find_best_index();
  int find_address(long int address);

  struct row * rows;
};
