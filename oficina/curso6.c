#include <stdlib.h>
#include <stdio.h>

voi haroi (int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Move disco de %c para %c\n", origem, destino);
    } else {
        haroi(n - 1, origem, auxiliar, destino);
        printf("Move disco de %c para %c\n", origem, destino);
        haroi(n - 1, auxiliar, destino, origem);
    }
}

int main () {
    int n = 6;
    char origem = 'A';
    char destino = 'C';
    char auxiliar = 'B';
    haroi(n, origem, destino, auxiliar);
}

void mostrarHastePreenchida(int n, char destino) {
    printf("Haste %c preenchida com discos empilhados", destino);
    for (int i = n; i >= 1; i--) {
        printf(" %d", i);
    }
}