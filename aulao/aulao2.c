#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int fatorial (int N) {
    int fat = 1;
    if (N == 0) return 0;
    else if (N == 1) return 1;
    else if (N > 1) fat = N*fatorial(N-1);
    return fat;
}

int main () {
    int N;
    printf("Insira um valor inteiro:\n");
    scanf("%d", &N);
    printf("\nO fatorial de %d e %d!\n", N, fatorial(N));
}
