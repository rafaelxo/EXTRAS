#include <stdlib.h>
#include <stdio.h>

int somatorioPA (double a, double b, int n) { return (n*(2*a + (n - 1)*b))/2; }

int main () {
    int termos;
    double inicial, razao;
    scanf("%lf%lf%d", &inicial, &razao, &termos);
    printf("%d\n", somatorioPA(inicial, razao, termos));
}
