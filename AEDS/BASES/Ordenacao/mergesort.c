#include <stdio.h>
#include <stdlib.h>

void intercalar (int vet[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1, n2 = dir - meio;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++) a1[i] = vet[esq + i];
    for (int i = 0; i < n2; i++) a2[i] = vet[meio + i + 1];
    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) vet[k++] = a1[i++];
        else vet[k++] = a2[j++];
    }
    while (i < n1) vet[k++] = a1[i++];
    while (j < n2) vet[k++] = a2[j++];
}

void mergesort (int vet[], int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(vet, esq, meio);
        mergesort(vet, meio + 1, dir);
        intercalar(vet, esq, meio, dir);
    }
}
