void mergesortBase  (int vet[], int n) {
    mergesort(vet, 0, n - 1);
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
    int nEsq = meio - esq + 1;
    int nDir = dir - meio;
    int vetEsq[nEsq + 1];
    int vetDir[nDir + 1];
    for (int i = 0; i < nEsq; i++) vetEsq[i] = vet[esq + i];
    for (int j = 0; j < nDir; j++) vetDir[j] = vet[meio + j + 1];
    vetEsq[nEsq] = vetDir[nDir] = 0x7FFFFFFF;
    int i = 0, j = 0;
    for (int k = esq; k <= dir; k++) {
        if (vetEsq[i] <= vetDir[j]) vet[k] = vetEsq[i++];
        else vet[k] = vetDir[j++];
    }
}
