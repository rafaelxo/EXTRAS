#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    Celula *prox;
} Celulua;

Celula *newCelula (int x) {
    Celula *x = (Celula *) malloc (sizeof(Celula));
    x->elemento = x;
    x->prox = NULL;
    return x;
}

typedef struct Fila {
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Fila *newFila () {
    Fila *x = (Fila *) malloc (sizeof(Fila));
    x->primeiro = NULL;
    x->ultimo = NULL;
    return x;
}

void inserir (int x) {
    Celula *nova = newCelula(x);
    ultimo->prox = nova;
    ultimo = nova;
}

int remover () {
    if (Fila->primeiro == Fila->ultimo) exit(1);
    Celula *tmp = Fila->primeiro->prox;
    int resp = tmp->elemento;
    Fila->primeiro->prox = tmp->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}
