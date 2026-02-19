#include <stdio.h>
#include <stdlib.h>

int elegirCamino() {
  int camino = rand() % 3 + 1;

  return camino;
}

int main() {
  int tiempo = 0;
  int salio = 0;

  int camino = elegirCamino();
  while (!salio) {
    switch (camino) {
    case 1:
      tiempo += 3;
      break;
    case 2:
      tiempo += 5;
      break;
    case 3:
      tiempo += 7;
      salio = 1;
      break;
    }
    printf("Camino: %d\n", camino);
    camino = elegirCamino();
  }

  printf("Tiempo total: %d\n", tiempo);

  return 0;
}