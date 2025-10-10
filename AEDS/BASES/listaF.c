#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    Celula *prox;
} Celulua;

Celula *newCelula(int x) {
    Celula *x = (Celula *)malloc(sizeof(Celula));
    x->elemento = x;
    x->prox = NULL;
    return x;
}

typedef struct Fila {
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Fila *newFila() {
    Fila *x = (Fila *)malloc(sizeof(Fila));
    x->primeiro = NULL;
    x->ultimo = NULL;
    return x;
}
