#include <stdio.h>
#include<stdlib.h>

int obtenerPromedio(int *arreglo) {
    int pos = 0;
    int promedio = 0;

    do
    {
        promedio += arreglo[pos];
        pos += 1;
    } while (arreglo[(pos - 1)] != -1);
    
    return (promedio+1)/(pos-1);
}

void main() {
    int *numeros = (int*) malloc (0);
    
    int pos = 0;
    int n = 0;
    do
    {
        int *temp = (int*) realloc(numeros, (pos + 1) * sizeof(int));
        numeros = temp;
        printf("Ingresa el %d numero del arreglo (ingresa '-1' para terminar)\n", pos);
        scanf(" %d", &n);
        numeros[pos] = n;
        pos += 1;
    } while (numeros[(pos -1)] != -1);

    printf("El promedio es: %d", obtenerPromedio(numeros));

    free(numeros);
    
}