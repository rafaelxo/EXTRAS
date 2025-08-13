#include <stdio.h>
#include <stdlib.h>

int conversao (int n) {
    if (n == 0) return 0;
    else return (n % 2) + 10 * conversao(n / 2);
}

int main () {
    int N;
    printf("Decimal: "); scanf("%d", &N);
    while (N != 0) {
        int binario = conversao(N);
        printf("Binario de %d: %d\n", N, binario);
        printf("Decimal: "); scanf("%d", &N);
    }
}
