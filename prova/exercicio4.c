#include <stdlib.h>
#include <stdio.h>

void preenche (float *mat) {
    char *nomeArq = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", nomeArq);
    FILE *arquivo = fopen(nomeArq, "r");
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) fscanf(arquivo, "%f", (mat +i*50 + j));
    }
    fclose(arquivo); free(nomeArq);
}

void calculaMedia (float *mat, float *vet) {
    for (int j = 0; j < 50; j++) {
        *(vet + j) = 0;
        for (int i = 0; i < 50; i++) *(vet + j) += *(mat + i*50 + j);
    }
    for (int i = 0; i < 50; i++) *(vet + i) /= 50;
}

void exibeMatriz (float *mat) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) printf("%f ", *(mat +i*50 + j));
    }
}

void exibeVetor (float *vet) {
    for (int i = 0; i < 50; i++) printf("%f ", *(vet + i));
}

int main () {
    float *matriz = (float*)malloc(50*50*sizeof(float));
    preenche(matriz); exibeMatriz(matriz);
    float *vetor = (float*)malloc(50*sizeof(float));
    calculaMedia(matriz, vetor); exibeVetor(vetor);
    free(matriz); free(vetor);
}