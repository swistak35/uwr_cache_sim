#include "tracestruct.h"
#include <iostream>
#include <fstream>

using namespace std;

#ifndef STRUCT_READER_H
#define STRUCT_READER_H

class StructReader {
public:
  StructReader();
  ~StructReader();
  int get(mtrace_t * tmp);
private:
  ifstream binfile;
};

#endif
