#include <stdio.h>

void swap (int vet[], int i, int j) {
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void construir (int vet[], int tam) {
    for (int i = tam; i > 1 && vet[i] > vet[i / 2]; i /= 2) swap(vet, i, i / 2);
}

void reconstruir (int vet[], int tam) {
    int i = 1;
    while (i <= tam / 2) {
        int filho = 2 * i;
        if (filho < tam && vet[filho] < vet[filho + 1]) filho++;
        if (vet[i] < vet[filho]) {
            swap(vet, i, filho);
            i = filho;
        } else i = tam;
    }
}

void heapsort (int vet[], int n) {
    int tmp[n + 1];
    for (int i = 0; i < n; i++) tmp[i + 1] = vet[i];
    for (int tam = 2; tam <= n; tam++) construir(tmp, tam);
    int tam = n;
    while (tam > 1) {
        swap(tmp, 1, tam--);
        reconstruir(tmp, tam);
    }
    for (int i = 0; i < n; i++) vet[i] = tmp[i + 1];
}
