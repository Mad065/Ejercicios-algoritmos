#include <stdio.h>
#include <stdlib.h>

double determinante(int n, double A[n][n]) {
    double temp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = A[i][j];

    double det = 1.0;

    for (int i = 0; i < n; i++) {
        if (temp[i][i] == 0) {
            int cambio = -1;
            for (int k = i + 1; k < n; k++) {
                if (temp[k][i] != 0) {
                    cambio = k;
                    break;
                }
            }
            if (cambio == -1) return 0;
            for (int j = 0; j < n; j++) {
                double aux = temp[i][j];
                temp[i][j] = temp[cambio][j];
                temp[cambio][j] = aux;
            }
            det *= -1;
        }

        det *= temp[i][i];
        for (int k = i + 1; k < n; k++) {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++)
                temp[k][j] -= factor * temp[i][j];
        }
    }

    return det;
}

int main() {
    int n;
    printf("Ingresa el tamaño de la matriz: ");
    scanf("%d", &n);

    double A[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10 + 1;

    printf("\nMatriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }

    double det = determinante(n, A);
    printf("\nDeterminante: %.2f\n", det);

    return 0;
}
