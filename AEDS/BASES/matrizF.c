#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *esq, *dir, *cima, *baixo;
} Celula;

Celula *newCelula(int x) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

typedef struct Matriz {
    Celula inicio;
    int linhas, colunas;
} Matriz;

Matriz *newMatriz (int l, int c) {
    
}


