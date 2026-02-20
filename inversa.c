#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int invertirMatriz(int n, double A[n][n], double inv[n][n]) {
    double aug[n][2*n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = A[i][j];
            aug[i][j+n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (fabs(aug[i][i]) < 1e-9) {
            int swap = -1;
            for (int k = i + 1; k < n; k++) {
                if (fabs(aug[k][i]) > 1e-9) {
                    swap = k;
                    break;
                }
            }
            if (swap == -1) return 0;
            for (int j = 0; j < 2*n; j++) {
                double aux = aug[i][j];
                aug[i][j] = aug[swap][j];
                aug[swap][j] = aux;
            }
        }

        double pivote = aug[i][i];
        for (int j = 0; j < 2*n; j++)
            aug[i][j] /= pivote;

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aug[k][i];
                for (int j = 0; j < 2*n; j++)
                    aug[k][j] -= factor * aug[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = aug[i][j+n];

    return 1;
}

int main() {
    int n;
    printf("Ingresa el tamaño de la matriz: ");
    scanf("%d", &n);

    double A[n][n], inv[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10 + 1;

    printf("\nMatriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }

    if (invertirMatriz(n, A, inv)) {
        printf("\nMatriz Inversa:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%.4f ", inv[i][j]);
            printf("\n");
        }
    } else {
        printf("\nLa matriz no es invertible\n");
    }

    return 0;
}
