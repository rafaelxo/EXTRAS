#include <stdlib.h>
#include <stdio.h>

void explorarChamadas (int N) {
    if (N <= 0) return;
    printf(">>Entrando em N = %d\n", N);
    explorarChamadas(N - 1);
    explorarChamadas(N - 2);
    explorarChamadas(N / 2);
    printf("<<Saindo de N = %d\n", N);
}

int main () {
    int N;
    scanf("%d", &N);
    explorarChamadas(N);
}