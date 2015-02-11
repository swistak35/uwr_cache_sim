#include "tracestruct.h"
#include <iostream>
#include <fstream>

using namespace std;

class StructReader {
public:
  StructReader();
  ~StructReader();
  void get(mtrace_t * tmp);
private:
  ifstream binfile;
};
