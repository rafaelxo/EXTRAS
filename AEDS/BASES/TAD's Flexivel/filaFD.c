#include <stdio.h>
#include <stdlib.h>

typedef struct CelulaDupla {
    int elemento;
    struct CelulaDupla *ant, *prox;
} CelulaDupla;

CelulaDupla *newCelula (int x) {
    CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    nova->elemento = x;
    nova->ant = nova->prox = NULL;
    return nova;
}

CelulaDupla *primeiro;
CelulaDupla *ultimo;

void Lista () {
    primeiro = newCelula(-1);
    ultimo = primeiro;
}

void inserirInicio (int x) {
    CelulaDupla *tmp = newCelula(x);
    tmp->ant = primeiro;
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo) ultimo = tmp;
    else tmp->prox->ant = tmp;
    free(tmp);
    tmp = NULL;
}
void inserirFim (int x) {
    ultimo->prox = newCelula(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;
}
void inserirPos (int x, int pos) {
    if (pos < 0 || pos > tamanho()) exit(1);
    if (pos == 0) inserirInicio(x);
    else if (pos == tamanho()) inserirFim(x);
    else {
        CelulaDupla *i = primeiro;
        for (int j = 0; j < pos; i = i->prox) j++;
        CelulaDupla *tmp = newCelula(x);
        tmp->ant = i;
        tmp->prox = i->prox;
        i->prox->ant = tmp;
        i->prox = tmp;
        free(i); free(tmp);
        i = tmp = NULL;
    }
}

int removerInicio () {
    if (primeiro == ultimo) exit(1);
    CelulaDupla *tmp = primeiro->prox;
    int resp = tmp->elemento;
    primeiro->prox = tmp->prox;
    if (tmp->prox != NULL) tmp->prox->ant = primeiro;
    else ultimo = primeiro;
    tmp->prox = tmp->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}
int removerFim () {
    if (primeiro == ultimo) exit(1);
    int resp = ultimo->elemento;
    ultimo = ultimo->ant;
    ultimo->prox->ant = NULL;
    free(ultimo->prox);
    ultimo->prox = NULL;
    return resp;
}
int removerPos (int pos) {
    if (primeiro == ultimo) exit(1);
    if (pos == 0) return removerInicio();
    else if (pos == tamanho() - 1) return removerFim();
    else {
        CelulaDupla *i = primeiro->prox;
        for (int j = 0; j < pos; i = i->prox) j++;
        int resp = i->elemento;
        i->ant->prox = i->prox;
        i->prox->ant = i->ant;
        i->prox = i->ant = NULL;
        free(i);
        i = NULL;
        return resp;
    }
}

void inserirOrd (int x) {
    if (primeiro == ultimo || x >= ultimo->elemento) inserirFim(x);
    else if (x <= primeiro->prox->elemento) inserirInicio(x);
    else {
        CelulaDupla *i = primeiro;
        while (i->prox != NULL && i->prox->elemento < x) i = i->prox;
        CelulaDupla *tmp = newCelula(x);
        tmp->ant = i;
        tmp->prox = i->prox;
        if (i->prox != NULL) i->prox->ant = tmp;
        i->prox = tmp;
    }
}

void inverter () {
    if (primeiro == ultimo) return;
    CelulaDupla *atual = primeiro->prox;
    CelulaDupla *tmp = NULL;
    while (atual != NULL) {
        tmp = atual->ant;
        atual->prox = atual->ant;
        atual->ant = tmp;
        atual = tmp;
    }
    CelulaDupla *aux = primeiro->prox;
    primeiro->prox = ultimo;
    ultimo = aux;
}

void removerPares () {
    CelulaDupla *i = primeiro->prox;
    while (i != NULL) {
        CelulaDupla *aux = i->prox;
        if (i->elemento % 2 == 0) {
            i->ant->prox = i->prox;
            if (i->prox != NULL) i->prox->ant = i->ant;
            else ultimo = i->ant;
            i->prox = i->ant = NULL;
            free(i);
        }
        i = aux;
    }
}

int tamanho () {
    int tamanho = 0;
    for (CelulaDupla *i = primeiro->prox; i != NULL; i = i->prox, tamanho++);
    return tamanho;
}

void mostrar () {
    printf("[ ");
    for (CelulaDupla *i = primeiro->prox; i != NULL; i = i->prox) printf("%d ", i->elemento);
    printf("]\n");
}
