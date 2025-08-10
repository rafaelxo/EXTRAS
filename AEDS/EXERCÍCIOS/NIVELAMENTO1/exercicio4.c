#include <stdlib.h>
#include <stdio.h>

void elementosOtim(int vet[], int N) {
    int maior = vet[0]; int menor = vet[0];
    for (int i = 1; i < N - 1; i += 2) {
        if (vet[i] > vet[i + 1]) {
            if (vet[i] > maior) maior = vet[i];
            if (vet[i + 1] < menor) menor = vet[i + 1];
        } else {
            if (vet[i + 1] > maior) maior = vet[i + 1];
            if (vet[i] < menor) menor = vet[i];
        }
    }
    printf("Menor: %d\nMaior: %d\n", menor, maior);
}

int main() {
    int N; scanf("%d", &N);
    int vet[N]; for (int i = 0; i < N; i++) scanf("%d", &vet[i]);
    elementosOtim(vet, N);
}
