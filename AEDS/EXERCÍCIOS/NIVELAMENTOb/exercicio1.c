#include <stdlib.h>
#include <stdio.h>

int comparar(int vet[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (vet[i] == x) return 1;
    }
    return 0;
}

int main () {
    int N; scanf("%d", &N);
    int vet[N]; for (int i = 0; i < N; i++) scanf("%d", &vet[i]);
    int x; scanf("%d", &x);
    int comp = comparar(vet, N, x);
    if (comp == 1) printf("SIM\n");
    else printf("NAO\n");
}
