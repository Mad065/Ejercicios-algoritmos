#include <stdio.h>
#include <stdlib.h>

int main() {

  int cantidad = 100;
  char string[cantidad];
  int contadorA = 0;
  int contadorE = 0;
  int contadorI = 0;
  int contadorO = 0;
  int contadorU = 0;

  printf("Ingrese la cadena: ");
  fgets(string, cantidad, stdin);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == 'a') {
      contadorA++;
    } else if (string[i] == 'e') {
      contadorE++;
    } else if (string[i] == 'i') {
      contadorI++;
    } else if (string[i] == 'o') {
      contadorO++;
    } else if (string[i] == 'u') {
      contadorU++;
    }
  }

  printf("La letra a se repite %d veces\n", contadorA);
  printf("La letra e se repite %d veces\n", contadorE);
  printf("La letra i se repite %d veces\n", contadorI);
  printf("La letra o se repite %d veces\n", contadorO);
  printf("La letra u se repite %d veces\n", contadorU);
}