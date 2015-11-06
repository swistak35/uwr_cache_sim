#ifndef STRUCT_READER_H
#define STRUCT_READER_H

#include <fstream>
#include <string>
#include "tracestruct.h"

using namespace std;

class StructReader {
public:
  StructReader(string filepath);
  ~StructReader();
  int get(mtrace_t * tmp);
private:
  ifstream binfile;
};

#endif
