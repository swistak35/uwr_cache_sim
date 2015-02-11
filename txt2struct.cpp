#include <cstdlib>
#include <tracestruct.h>
#include <iostream>
#include <fstream>

#define DEBUG true

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

    txtfile >> hex >> ins;
    txtfile >> is_write_chr;
    txtfile >> hex >> address;
    txtfile >> size;

    if (txtfile.eof()) {
      cout << "EOF" << endl;
      break;
    }

    tmp.address = address;
    tmp.size = size;

    if (is_write_chr == 1) {
      tmp.is_write = true;
    } else {
      tmp.is_write = false;
    }


    binfile.write((char *) &tmp, sizeof(mtrace_t));
    
    counter++;

    if (DEBUG) {
      cout << "Pobrano: " << tmp.address << " " << tmp.is_write << " " << +tmp.size << endl;
    }
  } while (txtfile.good());

  cout << "Zapisano " << counter << " rekordów." << endl;

  txtfile.close();
  binfile.close();

  return 0;
}
