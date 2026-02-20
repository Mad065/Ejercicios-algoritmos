#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void invertirMatriz(int n, int A[n][n], double inv[n][n]) {
    double aug[n][2*n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = A[i][j];
            aug[i][j+n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        double pivote = aug[i][i];
        if (fabs(pivote) < 1e-9) exit(1);

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
}

void potenciaMatriz(int n, int m, int matriz[n][n], double result[n][n]) {
    double temp[n][n], base[n][n];

    if (m == 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                result[i][j] = (i == j) ? 1.0 : 0.0;
        return;
    }

    if (m < 0) {
        invertirMatriz(n, matriz, base);
        m = -m;
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                base[i][j] = matriz[i][j];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = base[i][j];

    for (int p = 1; p < m; p++) {
        double mult[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mult[i][j] = 0;
                for (int k = 0; k < n; k++)
                    mult[i][j] += temp[i][k] * base[k][j];
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] = mult[i][j];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = temp[i][j];
}

int main() {
    int n, m;
    printf("Ingresa el tamaño de la matriz: ");
    scanf("%d", &n);

    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand() % 10 + 1;

    printf("Ingresa la potencia: ");
    scanf("%d", &m);

    double result[n][n];

    potenciaMatriz(n, m, matriz, result);

    printf("\nMatriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    printf("\nResultado:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2f ", result[i][j]);
        printf("\n");
    }

    return 0;
}
