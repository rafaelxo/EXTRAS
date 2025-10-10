#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    Celula* prox;
} Celula;

Celula *newCelula (int x) {
    Celula *x = (Celula *) malloc (sizeof(Celula));
    x->elemento = x;
    x->prox = NULL;
    return x;
}

typedef struct Pilha {
    Celula* topo;
} Pilha;

Pilha *newPilha () {
    Pilha *x = (Pilha *) malloc (sizeof(Pilha));
    x->topo = NULL;
    return x;
}

void inserir (int x) {
    Celula *nova = newCelula(x);
    nova->prox = pilha->topo;
    pilha->topo = nova;
    free(nova);
    nova = NULL;
}

int remover () {
    if (pilha-> topo == NULL) exit(1);
    Celula *tmp = pilha->topo;
    int resp = tmp->elemento;
    pilha->topo = tmp->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

void mostrar () {
    Celula *i;
    printf("[ ");
    for (i = pilha->topo; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}
