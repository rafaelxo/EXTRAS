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

void inverter () {
    if (primeiro == ultimo) exit(1);
    Celula *prev = NULL;
    Celula *next = NULL;
    Celula *atual = primeiro->prox;
    while (atual != NULL) {
        next = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = next;
    }
    ultimo = primeiro->prox;
    primeiro->prox = prev;
}

int maior () {
    int maior = primeiro->prox->elemento;
    for (Celula *i = primeiro->prox->prox; i != NULL; i = i->prox) {
        if (i->elemento > maior) maior = i->elemento;
    }
    return maior;
}

int soma () {
    int soma = 0;
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) soma += i->elemento;
    return soma;
}

void mostrar() {
    printf("[ ");
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}
