#include <stdio.h>

void swap(int vet[], int i, int j) {
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int mediana (int vet[], int esq, int dir) {
    int meio = (esq + dir) / 2;
    if (vet[esq] > vet[meio]) swap(vet, esq, meio);
    if (vet[esq] > vet[dir]) swap(vet, esq, dir);
    if (vet[meio] > vet[dir]) swap(vet, meio, dir);
    return vet[meio];
}

void quicksort (int vet[], int esq, int dir) {
    while (esq < dir) {
        int i = esq, j = dir;
        int pivo = mediana(vet, esq, dir);
        while (i <= j) {
            while (vet[i] < pivo) i++;
            while (vet[j] > pivo) j--;
            if (i <= j) {
                swap(vet, i, j);
                i++; j--;
            }
        }
        if (j - esq < dir - i) {
            quicksort(vet, esq, j);
            esq = i;
        } else {
            quicksort(vet, i, dir);
            dir = j;
        }
    }
}
