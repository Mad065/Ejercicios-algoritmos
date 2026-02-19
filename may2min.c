#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void may2min(char *string, int cantidad) {
  for (int i = 0; i < cantidad; i++) {
    if (isupper(string[i])) {
      string[i] = tolower(string[i]);
    } else if (islower(string[i])) {
      string[i] = toupper(string[i]);
    }
  }
}

int main() {

  int cantidad;
  printf("Ingrese la cantidad de caracteres: ");
  scanf(" %d", &cantidad);

  char string[cantidad];

  for (int i = 0; i < cantidad; i++) {
    printf("Ingrese el caracter %d: ", i + 1);
    scanf(" %c", &string[i]);
  }

  for (int i = 0; i < cantidad; i++) {
    printf(" %c", string[i]);
  }

  may2min(string, cantidad);

  printf("\n\n");
  for (int i = 0; i < cantidad; i++) {
    printf(" %c", string[i]);
  }
}