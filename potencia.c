#include <stdio.h>
#include <stdlib.h>

int esPotencia(int n, int b) {
  while (n / b >= 1) {
    n = n / b;
  }

  return n == 1;
}

int main() {
  int n, b;

  printf("ingresa el numero n\n");
  scanf("%d", &n);

  printf("ingresa el numero b\n");
  scanf("%d", &b);

  if (esPotencia(n, b)) {
    printf("%d es potencia de %d\n", n, b);
  } else {
    printf("%d no es potencia de %d\n", n, b);
  }

  return 0;
}