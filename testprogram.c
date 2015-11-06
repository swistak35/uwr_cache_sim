#include <stdio.h>

#define CACHE_BITS 10
#define BLOCK_BITS 8
#define LOOPS 1000

int main(void) {
  int size = 1 << CACHE_BITS;
  int jump = 1 << BLOCK_BITS;

  long int tab[size];
  long int suma;

  for (int i = 0; i < size; i++) {
    tab[i] = 0;
  }

  for (int j = 0; j < LOOPS; j++) {
    for (int k = 0; k < jump; k++) {
      for (int i = k; i < size; i += jump) {
        tab[i] = tab[i] + i;
        suma += tab[i];
      }
    }
  }

  printf("Wynik: %d\n", suma);
}
