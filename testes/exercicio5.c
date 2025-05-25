#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *inverte(char *texto, int N) {
    char *invertido = (char*)malloc((N+1)*sizeof(char));
    for (int i = 0; i < N; i++) *(invertido + i) = *(texto + N - 1 - i);
    invertido[N] = '\0';
    return invertido;
}

int main () {
    char *texto = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", texto);
    int tam = strlen(texto);
    char *invertido = inverte(texto, tam);
    printf("%s - %s", texto, invertido);
}