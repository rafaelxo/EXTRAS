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

Celula *primeiro;
Celula *ultimo;

void Lista () {
    primeiro = newCelula(0);
    ultimo = primeiro;
}

void inserirInicio (int x) {
    Celula *tmp = newCelula(x);
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo) ultimo = tmp;
}
void inserirFim (int x) {
    ultimo->prox = newCelula(x);
    ultimo = ultimo->prox;
}
void inserirPos (int x, int pos) {
    if (pos < 0 || pos > tamanho()) exit(1);
    if (pos == 0) inserirInicio(x);
    else if (pos == tamanho()) inserirFim(x);
    else {
        Celula *i = primeiro;
        for (int j = 0; j < pos; i = i->prox) j++;
        Celula *tmp = newCelula(x);
        tmp->prox = i->prox;
        i->prox = tmp;
    }
}

int removerInicio () {
    if (primeiro == ultimo) exit(1);
    Celula *tmp = primeiro->prox;
    int resp = tmp->elemento;
    primeiro->prox = tmp->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    if (primeiro->prox == NULL) ultimo = primeiro;
    return resp;
}
int removerFim () {
    if (primeiro == ultimo) exit(1);
    Celula *i = primeiro;
    while (i->prox != ultimo) i = i->prox;
    int resp = ultimo->elemento;
    free(ultimo);
    ultimo = i;
    ultimo->prox = NULL;
    return resp;
}
int removerPos (int pos) {
    if (primeiro == ultimo) exit(1);
    if (pos == 0) return removerInicio();
    else if (pos == tamanho() - 1) return removerFim();
    else {
        Celula *i = primeiro;
        for (int j = 0; j < pos; i = i->prox) j++;
        Celula *tmp = i->prox;
        int resp = tmp->elemento;
        i->prox = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        tmp = NULL;
        return resp;
    }
}

void inserirOrd (int x) {
    if (primeiro == ultimo || x >= ultimo->elemento) inserirFim(x);
    else if (x <= primeiro->prox->elemento) inserirInicio(x);
    else {
        Celula *i = primeiro;
        while (i->prox != NULL && i->prox->elemento < x) i = i->prox;
        Celula *tmp = newCelula(x);
        tmp->prox = i->prox;
        i->prox = tmp;
        if (tmp->prox == NULL) ultimo = tmp;
    }
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
