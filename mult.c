#include <stdio.h>
#include <stdlib.h>

void multiplicarMatrices(int **matriz1, int **matriz2, int **matrizResultado, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizResultado[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Ingresa el tamaño de la matriz: ");
    scanf("%d", &n);

    int **matriz1 = malloc(n * sizeof(int *));
    int **matriz2 = malloc(n * sizeof(int *));
    int **matrizResultado = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        matriz1[i] = malloc(n * sizeof(int));
        matriz2[i] = malloc(n * sizeof(int));
        matrizResultado[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz1[i][j] = rand() % 10 + 1 ;
            matriz2[i][j] = rand() % 10 +1;
        }
    }

    multiplicarMatrices(matriz1, matriz2, matrizResultado, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrizResultado[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(matrizResultado[i]);
    }

    free(matriz1);
    free(matriz2);
    free(matrizResultado);
}