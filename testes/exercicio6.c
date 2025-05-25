#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *criarArq () {
    char *nomeArq = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nomeArq);
    FILE *arq = fopen(nomeArq, "w");
    char *nome = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nome);
    int idade;
    scanf("%d", &idade);
    float notas[3];
    for (int i = 0; i < 3; i++) scanf("%f", &notas[i]);
    fprintf(arq, "%s\n%d\n%f %f %f\n", nome, idade, notas[0], notas[1], notas[2]);
    fclose(arq);
    free(nome);
    return nomeArq;
}

int contalinhas (char *nomeArq) {
    FILE *arq = fopen(nomeArq, "r");
    int linhas = 0;
    char carac;
    while (fscanf(arq, "%c", &carac) != EOF) {
        if (carac == '\n') linhas++;
    }
    fclose(arq);
    return linhas;
}

int main () {
    char *nomeArq = criarArq();
    printf("%d linhas!", contalinhas(nomeArq));
    free(nomeArq);
}