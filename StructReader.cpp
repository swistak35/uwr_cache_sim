#include "StructReader.h"

using namespace std;

StructReader::StructReader() {
  this->binfile;
  this->binfile.open("test.bin", ios::in | ios::binary);
}

StructReader::~StructReader() {
  this->binfile.close();
}

void StructReader::get(mtrace_t *data) {
  this->binfile.read((char *) data, sizeof(mtrace_t));
}
