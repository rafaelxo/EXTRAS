#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificacao (int N) {
    int q_divisores = 0;
    for (int cont1 = 1; cont1 <= N; cont1++) if (N%cont1 == 0) q_divisores++;
    if (q_divisores == 2) return N > 0;
    else return N < 0;
}

int main () {
    int N;
    scanf("%d", &N);
    if (verificacao(N)) printf("Primo\n");
    else printf("Nao primo\n");
}
