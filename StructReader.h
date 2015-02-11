#include "tracestruct.h"
#include <iostream>
#include <fstream>

using namespace std;

class StructReader {
public:
  StructReader();
  ~StructReader();
  int get(mtrace_t * tmp);
private:
  ifstream binfile;
};
