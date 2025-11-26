#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

Celula *newCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

Celula *primeiro, *ultimo;

void Lista () {
    primeiro = newCelula(0);
    ultimo = primeiro;
}

void inserir (int x) {
    ultimo->prox = newCelula(x);
    ultimo = ultimo->prox;
}

int remover (int x) {
    if (primeiro == ultimo) exit(1);
    else {
        Celula *tmp = primeiro;
        Celula *i = primeiro->prox;
        int pos = 0;
        while (i != NULL && i->elemento != x) {
            tmp = i;
            i = i->prox;
            pos++;
        }
        if (i != NULL) {
            tmp->prox = i->prox;
            i->prox = NULL;
            if (i == ultimo) ultimo = tmp;
            return pos;
        }
    }
}

int pesquisar (int x) {
    int pos = 0;
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox, pos++) {
        if (i->elemento == x) return pos;
    }
    return -1;
}

int tamanho () {
    int tamanho = 0;
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) tamanho++;
    return tamanho;
}

void mostrar () {
    printf("[ ");
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}
