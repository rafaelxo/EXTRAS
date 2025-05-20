#include <stdlib.h>
#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);
    int *vet = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", (vet + i));
    for (int i = 0; i < N; i++) {
        int divisores = 0;
        for (int j = 1; j <= *(vet + i); j++) {
            if (*(vet + i)%j == 0) divisores++;
        }
        if (divisores == 2) printf("%d e primo!\n", *(vet + i));
        else printf("%d nao e primo!\n", *(vet + i));
    }
}