#include <stdio.h>
#include <stdlib.h>

int main() {
  int array[100];
  int suma = 0;

  for (int i = 0; i < 100; i++) {
    array[i] = rand() % 100 + 1;
  }

  for (int i = 0; i < 100; i++) {
    if (array[i] % 2 == 0) {
      printf("%d\n", array[i]);
      suma += array[i];
    }
  }

  printf("Suma: %d\n", suma);

  return 0;
}