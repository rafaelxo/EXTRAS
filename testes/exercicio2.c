#include <stdlib.h>
#include <stdio.h>

int main () {
    int matriz[3][5];
    int vetor[5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &matriz[i][j]);
    }
    for (int i = 0; i < 5; i++) vetor[i] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j]%2 == 0) vetor[j] += matriz[i][j];
        }
    }
    for (int i = 0; i < 5; i++) printf("Soma dos pares da coluna %d: %d!\n", i + 1, vetor[i]);
}