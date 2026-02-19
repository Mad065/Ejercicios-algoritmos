#include <stdio.h>
#include <stdlib.h>

int main() {
  int original[100];
  int sinRepeticiones[100];
  int pos = 0;
  int noEsRepetido = 0;

  for (int i = 0; i < 100; i++) {
    original[i] = rand() % 1000 + 1;
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (original[i] == original[j]) {
        if (i != j) {
          noEsRepetido = 0;
          break;
        }
      } else {
        noEsRepetido = 1;
      }
    }
    if (noEsRepetido) {
      sinRepeticiones[pos] = original[i];
      pos++;
    }
    noEsRepetido = 0;
  }

  printf("Sin repeticiones\n");
  for (int i = 0; i < pos; i++) {
    printf("%d ", sinRepeticiones[i]);
  }

  printf("\n\n\n");

  printf("Original\n");
  for (int i = 0; i < 100; i++) {
    printf("%d ", original[i]);
  }

  return 0;
}