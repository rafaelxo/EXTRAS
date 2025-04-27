#include <stdio.h>
#include <stdlib.h>

int somaDigitos (int N) {
    int exp = 1;
    if (N == 0) return 0;
    else return (N%10 
}

int main () {
    int N;
    printf("Insira um numero para somar quantas casas ele possui:\n");
    scanf("%d", &N);
    printf("\nEsse numero possui %d digitos!", somaDigitos(N));
}