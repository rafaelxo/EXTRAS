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

Celula *primeiro;
Celula *ultimo;

void Lista () {
    primeiro = newCelula(-1);
    ultimo = primeiro;
}

int tamanho() {
    int tamanho = 0;
    Celula *i;
    for (i = primeiro; i != NULL; i = i->prox, tamanho++);
    return tamanho;
}
