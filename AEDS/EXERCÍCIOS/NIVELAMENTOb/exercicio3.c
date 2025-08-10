#include <stdlib.h>
#include <stdio.h>

void elementos(int vet[], int N) {
    int maior = vet[0]; int menor = vet[0];
    for (int i = 0; i < N; i++) {
        if (vet[i] > maior) maior = vet[i];
        if (vet[i] < menor) menor = vet[i];
    }
    printf("Menor: %d\nMaior: %d\n", menor, maior);
}

int main() {
    int N; scanf("%d", &N);
    int vet[N]; for (int i = 0; i < N; i++) scanf("%d", &vet[i]);
    elementos(vet, N);
}
