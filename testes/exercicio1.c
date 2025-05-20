#include <stdlib.h>
#include <stdio.h>

int main () {
    float salario[12], gastos[12], soma_gastos = 0, soma_salarios = 0, maior_gasto, maior_salario;
    for (int i = 0; i < 12; i ++) {
        scanf("%f%f", &salario[i], &gastos[i]);
        if (i == 0) {
            maior_gasto = gastos[i];
            maior_salario = salario[i];
        }
        else {
            if (gastos[i] > maior_gasto) maior_gasto = gastos[i];
            else if (salario[i] > maior_salario) maior_salario = salario[i];
        }
        soma_gastos += gastos[i];
        soma_salarios += salario[i];
    }
    printf("Soma salario: %.2f reais!\n", soma_salarios);
    printf("Soma gastos: %.2f reais!\n", soma_gastos);
    printf("Receita anual: %.2f reais!\n", soma_salarios - soma_gastos);
    printf("Maior salario: %.2f reais!\n", maior_gasto);
    printf("Maior gasto: %.2f reais!\n", maior_gasto);
}