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

Celula *topo;

void Pilha () {
    topo = NULL;
}

void inserir (int x) {
    Celula *tmp = newCelula(x);
    tmp->prox = topo;
    topo = tmp;
    free(tmp);
    tmp = NULL;
}

int remover () {
    if (topo == NULL) exit(1);
    int resp = topo->elemento;
    Celula *tmp = topo;
    topo = topo->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

int tamanho () {
    int tamanho = 0;
    for (Celula *i = topo; i != NULL; i = i->prox, tamanho++);
    return tamanho;
}

int soma () {
    int soma = 0;
    for (Celula *i = topo; i != NULL; i = i->prox) soma += i->elemento;
    return soma;
}

void mostrar () {
    printf("[ ");
    for (Celula *i = topo; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}
