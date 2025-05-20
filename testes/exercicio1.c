#include <stdio.h>
#include <string.h>

int main() {
    char *nome = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nome);
    for (int i = strlen(nome) - 1; i >= 0; i--) printf("%c", *(nome + i));
}