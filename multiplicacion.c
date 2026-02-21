#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b) {

    if (b == 0)
        return b;
    
    return mult(a, b - 1) + a;
}

int main() {
    int a, b;
    printf("Ingresa el numero a: ");
    scanf(" %d", &a);
    printf("Ingresa el numero b: ");
    scanf(" %d", &b);
    printf("\nSu multiplicacion es: %d", mult(a,b));
}