#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tracestruct.h"

#define DEBUG false

using namespace std;

int main(int argc, char * argv[]) {
  if (argc < 2) {
    cout << "Nie podałeś ścieżki do pliku .trace" << endl;
    exit(EXIT_FAILURE);
  }
  string txt_filepath(argv[1]);
  string bin_filepath(txt_filepath);
  bin_filepath.append(".bin");

  mtrace_t tmp;

  long int address, ins;
  short int is_write_chr, size;

  int counter = 0;

  ifstream txtfile;
  txtfile.open(txt_filepath, ios::in);
  if (txtfile.fail()) {
    cout << "Nie udało się otworzyć pliku. Na pewno istnieje?" << endl;
    exit(EXIT_FAILURE);
  }

  ofstream binfile;
  binfile.open(bin_filepath, ios::out | ios::binary);

  do {

    txtfile >> hex >> ins;
    txtfile >> is_write_chr;
    txtfile >> hex >> address;
    txtfile >> size;

    if (txtfile.eof()) {
      if (DEBUG) {
        cout << "EOF" << endl;
      }
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
