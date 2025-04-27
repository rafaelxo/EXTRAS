#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int multiplicacao (int n1, int n2) {
    int resultado = 0;
    if (n2 - 1 > 0) resultado = n1;
    else resultado += multiplicacao(n1, n2-1)
    return resultado;
}

int main () {
    int n1, n2;
    printf("Insira dois valores para multiplica-los:\n");
    scanf("%d%d", &n1, &n2);
    printf("\n%d\n", multiplicacao(n1, n2));
}