#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

Celula *newCelula (int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

Celula *topo;

void Pilha () {
    topo = NULL;
}

void inserir (int x) {
    Celula *tmp = newCelula(x);
    tmp->prox = topo;
    topo = tmp;
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

void mostrar () {
    printf("[ ");
    for (Celula *i = topo; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}

int tamanho () {
    int tamanho = 0;
    for (Celula *i = topo; i != NULL; i = i->prox) tamanho++;
    return tamanho;
}

int somar () {
    int soma = 0;
    for (Celula *i = topo; i != NULL; i = i->prox) soma += i->elemento;
    return soma;
}

int somarRec (Celula *i) {
    if (i == NULL) return 0;
    else return i->elemento + somarRec(i->prox);
}

int maior () {
    if (topo == NULL) exit(1);
    int resp = topo->elemento;
    for (Celula *i = topo->prox; i != NULL; i = i->prox) {
        if (i->elemento > resp) resp = i->elemento;
    }
    return resp;
}

int maiorRec (Celula *i) {
    if (i == NULL) return 0;
    else return (i->elemento > maiorRec(i->prox)) ? i->elemento : maiorRec(i->prox);
}

void mostrarInv (Celula *i) {
    if (i != NULL) {
        mostrarInv(i->prox);
        printf("%d ", i->elemento);
    }
}
