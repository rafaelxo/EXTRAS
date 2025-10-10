#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    Celula* prox;
} Celula;

Celula *newCelula (int x) {
    Celula *tmp = (Celula *) malloc (sizeof(Celula));
    tmp->elemento = x;
    tmp->prox = NULL;
    return tmp;
}

typedef struct Pilha {
    Celula* topo;
} Pilha;

Pilha *newPilha () {
    Pilha *tmp = (Pilha *) malloc (sizeof(Pilha));
    tmp->topo = NULL;
    return tmp;
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
