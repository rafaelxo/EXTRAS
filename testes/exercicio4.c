#include <stdlib.h>
#include <stdio.h>

struct Aluno {
    char nome[50];
    float notas[3];
};

int main () {
    int N;
    scanf("%d", &N);
    struct Aluno a[N];
    FILE *arquivo = fopen("alunos.txt", "w");
    for (int i = 0; i < N; i++) {
        scanf(" %[^\n]", a[i].nome);
        fprintf(arquivo, "%s ", a[i].nome);
        for (int j = 0; j < 3; j++) {
            scanf("%f", &a[i].notas[j]);
            fprintf(arquivo, "%f ", a[i].notas[j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    arquivo = fopen("alunos.txt", "r");
    for (int i = 0; i < N; i++) {
        fscanf(arquivo, "%s %f %f %f", a[i].nome, &a[i].notas[0], &a[i].notas[1], &a[i].notas[2]);
        float soma = 0;
        for (int j = 0; j < 3; j++) soma += a[i].notas[j];
        float media = soma/3;
        if (media >= 7) printf("Aluno %s aprovado com media de %.2f pontos!\n", a[i].nome, media);
    }
}