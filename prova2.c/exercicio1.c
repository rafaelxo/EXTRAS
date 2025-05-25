#include <stdio.h>
#include <stdlib.h>

void moduloA (int *matriz, int M, int N) {
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j++) scanf("%d", (matriz + i*N + j));
    }
}

void moduloB (int *matriz, int M, int N) {
    for (int col = 0; col < N; col++) {
        for (int ln = 0; ln < M; ln++) printf("%d ", *(matriz + col*M + ln));
    }
}

int main () {
    int *valores = (int*)malloc(10*5*sizeof(int));
    moduloA(valores, 10, 5);
    moduloB(valores, 10, 5);
    return 0;
}