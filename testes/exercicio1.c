#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    scanf(" %[^\n]", &nome);
    for (int i = strlen(nome) - 1; i >= 0; i--) printf("%c", nome[i]);
}