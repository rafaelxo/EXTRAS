#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *esq, *dir, *cima, *baixo;
} Celula;

Celula *newCelula(int x) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->esq = nova->dir = nova->cima = nova->baixo = NULL;
    return nova;
}

typedef struct Matriz {
    Celula *inicio;
    int linhas, colunas;
} Matriz;

Matriz *newMatriz (int l, int c) {
    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    m->linhas = l;
    m->colunas = c;
    m->inicio = newCelula(0);
    Celula *atual = m->inicio;
    for (int j = 1; j < c; j++) {
        Celula *col = newCelula(0);
        atual->dir = col;
        col->esq = atual;
        atual = col;
    }
    Celula *base = m->inicio;
    for (int i = 1; i < l; i++) {
        Celula *prevLin = base;
        Celula *prox = newCelula(0);
        prox->cima = prevLin;
        prevLin->baixo = prox;
        atual = prox;
        Celula *aux = prevLin->dir;
        for (int j = 1; j < c; j++) {
            Celula *nova = newCelula(0);
            atual->dir = nova;
            nova->esq = atual;
            nova->cima = aux;
            aux->baixo = nova;
            atual = nova;
            aux = aux->dir;
        }
    }
}
