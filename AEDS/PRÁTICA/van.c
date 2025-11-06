#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct Aluno {
    char nome[MAX];
    char regiao;
    int distancia;
} Aluno;

bool primeiro (Aluno *a1, Aluno *a2) {
    if (a1->distancia != a2->distancia) return a1->distancia < a2->distancia;
    if (a1->regiao != a2->regiao) return a1->regiao < a2->regiao;
    return strcmp(a1->nome, a2->nome) < 0;
}

void ordenarAlunos(Aluno *alunos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (deveVirAntes(&alunos[j], &alunos[i])) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        Aluno *alunos = (Aluno*)malloc(n*sizeof(Aluno));
        for (int i = 0; i < n; i++) scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].distancia);
        ordenarAlunos(alunos, n);
        for (int i = 0; i < n; i++) printf("%s\n", alunos[i].nome);
        free(alunos);
    }
    return 0;
}
