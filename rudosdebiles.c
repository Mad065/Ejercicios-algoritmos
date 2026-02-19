#include <stdio.h>
#include <stdlib.h>

int main() {
  char array[100];
  char formacion[10];

  printf("Ingrese la formacion 'R' o 'd'\n");
  for (int i = 0; i < 10; i++) {
    scanf(" %c", &formacion[i]);
  }

  for (int i = 0; i < 100; i++) {
    array[i] = formacion[i % 10];
  }

  for (int i = 0; i < 100; i++) {
    printf("%c ", array[i]);
  }

  return 0;
}