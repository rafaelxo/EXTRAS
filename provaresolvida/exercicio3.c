#include <stdio.h>
#include <stdlib.h>

void preenche (float *mat) {
    char *nomeArq = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nomeArq);
    FILE *Arq = fopen(nomeArq, "r");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) fscanf(Arq, "%f", (mat + i*15 + j));
    }
}

float *maior (float *mat) {
    float *valores = (float*)malloc(15*sizeof(float));
    for (int i = 0; i < 15; i++) {
        *(valores + i) = 0;
        for (int j = 0; j < 15; j++) {
            if (*(mat + i*15 + j) > *(valores + i)) *(valores + i) = *(mat +i*15 + j);
        }
    }
    return valores;
}

void multiplica (float *mat, float *vet) {
    for (int i = 0; i < 15; i++) *(mat + i*15 + i) *= *(vet + i);
}

void exibeMat (float *mat) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) printf("%f ", *(mat + i*15 + j));
        printf("\n");
    }
}

int main () {
    float *matriz = (float*)malloc(15*15*sizeof(float));
    preenche(matriz);
    float *vetor = (float*)malloc(15*sizeof(float));
    vetor = maior(matriz);
    for (int i = 0; i < 15; i++) printf("%f ", *(vetor + i));
    multiplica(matriz, vetor);
    exibeMat(matriz);
}