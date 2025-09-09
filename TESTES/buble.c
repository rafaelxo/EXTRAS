#include <stdio.h>

void swap (int vet[], int i, int j) {
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void bolha (int vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (vet[j] > vet[j + 1]) swap (vet, j, j + 1);
        }
    }
}

void bolha(int vet[], int n) {
    int trocou = 1;
    for (int i = 0; i < n -1 && trocou == 1; i++) {
        trocou = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (vet[j] > vet[j + 1]) {
                swap(vet, j, j + 1);
                trocou = 1;
            }
        }
    }
}
