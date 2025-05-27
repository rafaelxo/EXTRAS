#include <stdlib.h>
#include <stdio.h>

int main () {
    int matriz[3][5];
    int vetor[3];
    int maior;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &matriz[i][j]);
    }
    for (int i = 0; i < 3; i++) {
        vetor[i] = matriz[i][0];
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > vetor[i]) vetor[i] = matriz[i][j];
        }
    }
    for (int i = 0; i < 3; i++) printf("Maior da linha %d: %d!\n", i + 1, vetor[i]);
}