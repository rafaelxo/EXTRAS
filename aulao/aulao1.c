#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void menorValor (int n1, int n2, int n3, int n4) {
    int menor = n1;
    if (n2 < menor) menor = n2;
    if (n3 < menor) menor = n3;
    if (n4 < menor) menor = n4;
    printf("\nO menor valor e %d!\n", menor);
}

float porcentagemImpares(int n1, int n2, int n3, int n4) {
    float porc;
    if (n1%2 != 0) porc++;
    else if (n2%2 != 0) porc++;
    else if (n3%2 != 0) porc++;
    else if (n4%2 != 0) porc++;
    return ((porc*100.0)/4);
}

float media (int n1, int n2, int n3, int n4) {
    return ((n1 + n2 + n3 + n4)*1.0/4);
}

int main () {
    int n1, n2, n3, n4, opcao;
    do {
        printf("Menu de opcoes:\n\n1. Menor valor\n2. Porcentagem de impares\n3. Media\n4. Sair\n\nInsira a opcao desejada:\n");
        scanf("%d", &opcao);
        printf("Insira quatro valores inteiros:\n");
        scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
        if (opcao == 1) menorValor(n1, n2, n3, n4);
        if (opcao == 2) printf("\nA porcentagem de impares entre os nuneros digitados e de %.2f%%!", porcentagemImpares(n1, n2, n3, n4));
        if (opcao == 3) printf("\nA media dos valores inseridos e de %.2f!", media(n1, n2, n3, n4));
        if (opcao == 4) printf("\nPrograma finalizado!\n");
    } while (opcao >= 1 && opcao < 4);
}
