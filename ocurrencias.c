#include <stdio.h>
#include <stdlib.h>

int main() {

  int cantidad = 100;
  char letra;
  char string[cantidad];
  int contador = 0;

  printf("Ingrese la cadena: ");
  fgets(string, cantidad, stdin);

  printf("Ingrese la letra a buscar: ");
  scanf(" %c", &letra);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == letra) {
      contador++;
    }
  }

  printf("La letra %c se repite %d veces\n", letra, contador);
}