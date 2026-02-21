#include <stdio.h>
#include <stdlib.h>

int pot(int a, int b) {

    if (b == 0)
        return 1;
    
    return pot(a, b-1) * a ;
}

int main() {
   int a, b;
    printf("Ingresa el numero a: ");
    scanf(" %d", &a);
    printf("Ingresa el numero b: ");
    scanf(" %d", &b);
    printf("\nSu multiplicacion es: %d", pot(a,b));
}