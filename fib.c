#include <stdio.h>
#include <stdlib.h>

int fib(int n) {

    if (n <= 1)
        return n;
    
    return fib(n - 2) + fib(n - 1);
}

int main() {
    int n;
    printf("Ingresa un numero: ");
    scanf(" %d", &n);
    printf("\nSu fibonacci es: %d", fib(n));
}