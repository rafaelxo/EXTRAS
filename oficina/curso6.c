#include <stdlib.h>
#include <stdio.h>

void mostrarHastePreenchida(int n, char destino) {
    printf("Haste %c preenchida com discos empilhados", destino);
    for (int i = n; i >= 1; i--) printf(" %d", i);
    printf("\n");
}

void hanoi (int n, char origem, char destino, char auxiliar) {
    if (n == 1) printf("Move disco de %c para %c\n", origem, destino);
    else {
        hanoi(n - 1, origem, auxiliar, destino);
        printf("Move disco de %c para %c\n", origem, destino);
        hanoi(n - 1, auxiliar, destino, origem);
    }
}

int main () {
    int n = 6;
    char origem = 'A';
    char destino = 'C';
    char auxiliar = 'B';
    hanoi(n, origem, destino, auxiliar);
    mostrarHastePreenchida(n, destino);
}