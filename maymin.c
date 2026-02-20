#include <stdio.h>
#include <stdlib.h>

void convertirMayus2Minus(char* c) {
    *c += 32;
}

void convertirMinus2Mayus(char* c) {
    *c -= 32;
}

int main() {

    char c;
    printf("Ingresa el caracter: ");
    scanf("%c", &c);

    if ((int)c <= 90 && (int)c >= 65) // Mayusculas
    {
        convertirMayus2Minus(&c);
    } else if ((int)c <= 122 && (int)c >= 97) // Minusculas
    {
        convertirMinus2Mayus(&c);
    }
    
    printf("%c", c);
}
