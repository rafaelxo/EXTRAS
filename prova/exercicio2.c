#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
    srand((unsigned)time(NULL));
    char *nomeArq = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nomeArq);
    FILE *arquivo = fopen(nomeArq, "w");
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int num = 0;
        num = rand()%100 + 1;
        fprintf(arquivo, "%d ", num);
    }
}