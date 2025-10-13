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

Celula *primeiro;
Celula *ultimo;

void Fila () {
    primeiro = newCelula(0);
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

void mostrar () {
    printf("[ ");
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}

int somar () {
    int soma = 0;
    for (Celula *i = primeiro->prox; i != NULL; i = i->prox) soma += i->elemento;
    return soma;
}

int somarRec (Celula *i) {
    if (i == NULL) return 0;
    else return i->elemento + somarRec(i->prox);
}

int maior () {
    if (primeiro == ultimo) exit(1);
    int maior = primeiro->prox->elemento;
    for (Celula *i = primeiro->prox->prox; i != NULL; i = i->prox) {
        if (i->elemento > maior) maior = i->elemento;
    }
    return maior;
}

int maiorRec (Celula *i) {
    if (i == NULL) return 0;
    else return (i->elemento > maiorRec(i->prox)) ? i->elemento : maiorRec(i->prox);
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
