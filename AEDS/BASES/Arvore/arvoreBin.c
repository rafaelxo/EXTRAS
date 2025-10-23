#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int elemento;
    struct No *esq, *dir;
} No;

No *newNo (int x) {
    No *novo = (No*)malloc(sizeof(No));
    novo->elemento = x;
    novo->esq = novo->dir = NULL;
    return novo;
}

typedef struct Arvore {
    No *raiz;
} Arvore;

Arvore* newArvore () {
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}

No* inserirRef (int x, No *i) {
    if (i == NULL) i = newNo(x);
    else if (x < i->elemento) i->esq = inserirRef(x, i->esq);
    else if (x > i->elemento) i->dir = inserirRef(x, i->dir);
    else exit(1);
    return i;
}
void inserirRefArvore (Arvore *a, int x) {
    a->raiz = inserirRef(x, a->raiz);
}

void inserirPai (Arvore *a, int x, No *i, No *pai) {
    if (i == NULL) {
        if (x < pai->elemento) pai->esq = newNo(x);
        else pai->dir = newNo(x);
    } else if (x < i->elemento) inserirPai(a, x, i->esq, i);
    else if (x > i->elemento) inserirPai(a, x, i->dir, i);
    else exit(1);
}
void inserirPaiArvore (Arvore *a, int x) {
    if (a->raiz == NULL) a->raiz = newNo(x);
    else if (x < a->raiz->elemento) inserirPai(a, x, a->raiz->esq, a->raiz);
    else if (x > a->raiz->elemento) inserirPai(a, x, a->raiz->dir, a->raiz);
    else exit(1);
}

bool pesquisar (Arvore *a, int x) {
    return pesquisarNo(a->raiz, x);
}
bool pesquisarNo (No *i, int x) {
    if (i == NULL) return false;
    else if (x == i->elemento) return true;
    else if (x < i->elemento) return pesquisarNo(i->esq, x);
    else return pesquisarNo(i->dir, x);
}

void caminharCentral (No *i) {
    if (i != NULL) {
        caminharCentral(i->esq);
        printf("%d ", i->elemento);
        caminharCentral(i->dir);
    }
}
void caminharPre (No *i) {
    if (i != NULL) {
        printf("%d ", i->elemento);
        caminharPre(i->esq);
        caminharPre(i->dir);
    }
}
void caminharPos (No *i) {
    if (i != NULL) {
        caminharPos(i->esq);
        caminharPos(i->dir);
        printf("%d ", i->elemento);
    }
}

void remover (Arvore *a, int x) {
    a->raiz = removerNo(x, a->raiz);
}
No* removerNo (int x, No *i) {
    if (i == NULL) exit(1);
    else if (x < i->elemento) i->esq = removerNo(x, i->esq);
    else if (x > i->elemento) i->dir = removerNo(x, i->dir);
    else if (i->dir == NULL) i = i->esq;
    else if (i->esq == NULL) i = i->dir;
    else i->esq = maiorEsq(i, i->esq);
    return i;
}

No* maiorEsq (No *i, No *j) {
    if (j->dir == NULL) {
        i->elemento = j->elemento;
        j = j->esq;
    }
    else j->dir = maiorEsq(i, j->dir);
    return j;
}
No* menorDir (No *i, No *j) {
    if (j->esq == NULL) {
        i->elemento = j->elemento;
        j = j->dir;
    }
    else j->esq = menorDir(i, j->esq);
    return j;
}

int getAlturaRec (No *i) {
    if (i == NULL) return 0;
    else {
        int altEsq = getAlturaRec(i->esq);
        int altDir = getAlturaRec(i->dir);
        return (altEsq > altDir ) ? altEsq + 1: altDir + 1;
    }
}

int getMaior (Arvore *a) {
    if (a->raiz == NULL) exit(1);
    No *i;
    for (i = a->raiz; i->dir != NULL; i = i->dir);
    return i->elemento;
}
int getMenor (Arvore *a) {
    if (a->raiz == NULL) exit(1);
    No *i;
    for (i = a->raiz; i->esq != NULL; i = i->esq);
    return i->elemento;
}

int somarRec (No *i) {
    if (i == NULL) return 0;
    return i->elemento + somarRec(i->esq) + somarRec(i->dir);
}

bool igual (Arvore *a, Arvore *b) {
    return igualNo(a->raiz, b->raiz);
}
bool igualNo (No *a, No *b) {
    if (a == NULL && b == NULL) return true;
    else if (a == NULL || b == NULL) return false;
    else if (a->elemento != b->elemento) return false;
    else return igualNo(a->esq, b->esq) && igualNo(a->dir, b->dir);
}
