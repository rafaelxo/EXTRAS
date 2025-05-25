#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    int N;
    scanf("%d", &N);
    char *texto = (char*)malloc(N*sizeof(char));
    scanf(" %[^\n]", texto);
    char palavra[2] = "oi";
    int quant = 0;
    int i = 0;
    while (*(texto + i) != '\0') {
        if (*(texto + i) == palavra) quant++;
        i++;
    }
    printf("%d", quant);
}