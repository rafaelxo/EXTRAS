#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int elemento;
    struct No* esq;
    struct No* dir;
} No;

No *newNo (int x) {
    No *novo = (No*)malloc(sizeof(No));
    novo->elemento = x;
    novo->esq = novo->dir = NULL;
    return novo;
}

typedef struct Arvore {
    No* raiz;
} Arvore;

Arvore *newArvore () {
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}

void inserirRef (int x) {

}
No* inserirRef (int x, No *i) {

}

void inserirPai () {

}
void inserirPai (int x, No *i, No *pai) {

}

bool pesquisar (int x) {

}
bool pesquisar (int x, No *i) {

}

void caminharCentral (No *i) {

}
void caminharPre (No *i) {

}
void caminharPos (No *i) {

}

void remover (int x) {

}
No* remover (int x, No *i) {

}

No* maiorEsq (No *i) {

}
No* menorDir (No *i) {

}

int getAlturaRec (No *i) {

}

int getMaior () {

}
int getMenor () {

}

int somarRec (No *i) {

}

bool igual (Arvore *a, Arvore *b) {

}
bool igual (No *a, No *b) {

}
