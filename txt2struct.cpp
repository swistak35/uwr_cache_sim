#include <cstdlib>
#include <tracestruct.h>
#include <iostream>
#include <fstream>

#define DEBUG false

using namespace std;

int main() {
  mtrace_t tmp;

  long int address, ins;
  short int is_write_chr, size;

  int counter = 0;

  ifstream txtfile;
  txtfile.open("test.trace", ios::in);

  ofstream binfile;
  binfile.open("test.bin", ios::out | ios::binary);

  do {
    counter++;

    txtfile >> hex >> ins;
    txtfile >> is_write_chr;
    txtfile >> hex >> address;
    txtfile >> size;

    tmp.address = address;
    tmp.size = size;

    if (is_write_chr == 1) {
      tmp.is_write = true;
    } else {
      tmp.is_write = false;
    }

    binfile.write((char *) &tmp, sizeof(mtrace_t));

    if (DEBUG) {
      cout << "Pobrano: " << tmp.address << " " << tmp.is_write << " " << +tmp.size << endl;
    }
  } while (txtfile.good());

  txtfile.close();
  binfile.close();

  return 0;
}
