#include <stdio.h>
#include <stdlib.h>

int main() {
  char string[100];
  int longitud = 0;

  printf("Ingrese una palabra: ");
  fgets(string, 100, stdin);

  for (int i = 0; string[i]; i++) {
    longitud++;
  }
  // elimina el \n
  longitud--;

  for (int i = 0; i <= longitud / 2; i++) {
    if (string[i] == string[longitud - i - 1]) {
      printf("letra %c es igual a %c\n", string[i], string[longitud - i - 1]);
    } else {
      printf("No es un palindromo\n");
      return 0;
    }
  }

  printf("Es un palindromo\n");
}