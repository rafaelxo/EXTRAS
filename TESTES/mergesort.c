void mergesortBase  (int vet[], int n) {
    mergesortRec(vet, 0, n - 1);
}

void mergesort (int vet[], int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(vet, esq, meio);
        mergesort(vet, meio + 1, dir);
        intercalar(vet, esq, meio, dir);
    }
}

void intercalar (int vet[], int esq, int meio, int dir) {
    int n1, n2, i, j, k;
    n1 = meio - esq + 1;
    n2 = dir - meio;
    int *a1 = (int *)malloc((n1 + 1) * sizeof(int));
    int *a2 = (int *)malloc((n2 + 1) * sizeof(int));
    for (i = 0; i < n1; i++) a1[i] = vet[esq + i];
    for (j = 0; j < n2; j++) a2[j] = vet[meio + j + 1];
    a1[i] = a2[j] = 0x7FFFFFFF;
    for (i = j = 0, k = esq; k <= dir; k++) vet[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
}
