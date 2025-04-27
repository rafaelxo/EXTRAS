#include <stdlib.h>
#include <stdio.h>

int soma (int *num1,int *num2) {
    return (*num1 + *num2);
}

int main (void) {
    int val1=5, val2=4;
    printf("A soma %d e resultado de %d com %d", soma(&val1,&val2),val1,val2);
}
