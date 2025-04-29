#include <stdio.h>
#include <stdlib.h>

int soma (N) {
    if (N == 1) return 1;
    else return N + soma(N-1);
}

int main () {
    int N;
    scanf("%d", &N);
    printf("%d\n", soma(N));
}
