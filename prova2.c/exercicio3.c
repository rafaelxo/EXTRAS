#include <stdlib.h>
#include <stdio.h>

int conta (char *texto, char c) {
    int quant = 0;
    int i = 0;
    while (*(texto + i) != '\0') {
        if (*(texto + i) == c) quant++;
        i++;
    }
    return quant;
}

int main () {
    char *frase = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", frase);
    char carac;
    scanf(" %c", &carac);
    printf("%d\n", conta(frase, carac));
    free(frase);
}