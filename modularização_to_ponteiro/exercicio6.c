#include <stdio.h>
#include <stdlib.h>

int multiplicacao (int *num) {
    printf("\nSequencia de %d:\n", *num);
    for (int cont1 = 1; cont1 <= *num; cont1++) {
        for (int cont2 = 1; cont2 <= cont1; cont2++) printf("%d ", cont1*cont2);
        printf("\n");
    }
}

int main() {
   int *num = (int*) malloc(sizeof(int));
   do {
        printf("Insira um numero (1 a 9) para realizar a sequencia:\n");
        scanf("%d", num);
   } while (*num <= 1 || *num >= 9);
   multiplicacao(num);
}