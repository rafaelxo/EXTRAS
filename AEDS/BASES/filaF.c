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

Celula *primeiro;
Celula *ultimo;

void Fila() {
    primeiro = newCelula(-1);
    ultimo = primeiro;
}

void inserir (int x) {
    ultimo->prox = newCelula(x);
    ultimo = ultimo->prox;
}

int remover () {
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
