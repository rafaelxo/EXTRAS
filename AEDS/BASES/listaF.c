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

typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

Lista *newLista() {
    Lista *x = (Lista *)malloc(sizeof(Lista));
    x->primeiro = NULL;
    x->ultimo = NULL;
    return x;
}

int tamanho() {
    int tamanho = 0;
    Celula *i;
    for (i = lista->primeiro; i != NULL; i = i->prox, tamanho++);
    return tamanho;
}

void inserirInicio (int x) {
    Celula *tmp = newCelula(x);
    tmp->prox = lista->primeiro;
    primeiro = tmp;
    if (Lista->primeiro == lista->ultimo) lista->ultimo = tmp;
    free(tmp);
    tmp = NULL;
}

void inserirFim (int x) {
    Celula *tmp = newCelula(x);
    lista->ultimo->prox = tmp;
    lista->ultimo = tmp;
    free(tmp);
    tmp = NULL;
}

void inserirPos (int x, int pos) {
    Celula *i;
    Celula *tmp = newCelula(x);
    for (i = lista->primeiro; i )
}

int removerInicio () {
    if (lista->primeiro == lista->ultimo) exit(1);
    Celula *tmp = lista->primeiro;
    lista->primeiro = tmp->prox;
    int resp = primeiro->elemento;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

int removerFim () {
    if (Lista->primeiro == Lista->ultimo) exit(1);
    Celula *i;
    for (i = Lista->primeiro; i->prox != Lista->ultimo; i = i->prox);
    int resp = Lista->ultimo->elemento;
    ultimo = i;
    ultimo->prox = NULL;
    free(i);
    i = NULL;
    return resp;
}

int removerPos (int pos) {
    if (Lista->primeiro == Lista->ultimo) exit(1);
    int resp;
    if (pos == 0) resp = removerInicio();
    else if (pos == tamanho()-1) resp = removerFim();
    else
    return resp;
}
