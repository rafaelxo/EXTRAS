#include <stdlib.h>
#include <stdio.h>

int compararOrd(int vet[], int N, int x) {
    int esq = 0; int dir = N - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (vet[meio] < x) esq = meio + 1;
        else if (vet[meio] > x) dir = meio - 1;
        else return 1;
    }
    return 0;
}

int main() {
    int N; scanf("%d", &N);
    int vet[N]; for (int i = 0; i < N; i++) scanf("%d", &vet[i]);
    int x; scanf("%d", &x);
    int comp = compararOrd(vet, N, x);
    if (comp == 1) printf("SIM\n");
    else printf("NAO\n");
}
