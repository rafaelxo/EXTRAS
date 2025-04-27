#include <stdio.h>
#include <stdlib.h>

int potencia (int base, int exp) {
    if (base == 1 || exp == 0) return 1;
    else return base * potencia(base, exp - 1);
}

int main () {
    int base, exp;
    do {
        scanf("%d%d", &base, &exp);
        printf("%d\n", potencia(base, exp));
    } while (base < 1 && exp < 0);
}
