#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoAN {
    int elemento;
    bool cor;
    struct NoAN *esq, *dir;
} NoAN;

NoAN *newNo (int x) {
    NoAN *novo = (NoAN*)malloc(sizeof(NoAN));
    novo->elemento = x;
    novo->cor = false;
    novo->esq = novo->dir = NULL;
    return novo;
}

NoAN *raiz;

void ArvoreAN () {
    raiz = NULL;
}

NoAN* rotacionarDir (NoAN *i) {
    No *noEsq = i->esq;
    No *noEsqDir = noEsq->dir;
    noEsq->dir = i;
    i->esq = noEsqDir;
    return noEsq;
}
NoAN* rotacionarEsq (NoAN *i) {
    No *noDir = i->dir;
    No *noDirEsq = noDir->esq;
    noDir->esq = i;
    i->dir = noDirEsq;
    return noDir;
}
NoAN* rotacionarDirEsq (NoAN *i) {
    i->dir = rotacionarDir(i->dir);
    return rotacionarEsq(i);
}
NoAN* rotacionarEsqDir (NoAN *i) {
    i->esq = rotacionarEsq(i->esq);
    return rotacionarDir(i);
}

NoAN* balancear (NoAN *i) {
    if (i != NULL) {
        int fator = getNivel(i->dir) - getNivel(i->esq);
        if (abs(fator) <= 1) setNivel(i);
        else if (fator == 2) {
            int fatorFilhoDir = getNivel(i->dir->dir) - getNivel(i->dir->esq);
            if (fatorFilhoDir == -1) i->dir = rotacionarDir(i->dir);
            i = rotacionarEsq(i);
        }
        else if (fator == -2) {
            int fatorFilhoEsq = getNivel(i->esq->dir) - getNivel(i->esq->esq);
            if (fatorFilhoEsq == 1) rotacionarEsq(i->esq);
            i = rotacionarDir(i);
        } else exit(1);
    }
    return i;
}

void inserirRec (int x, NoAN *i) {
    if (i == NULL) i = newNo(x);
    else if (x < i->elemento) i->esq = inserirRec(x, i->esq);
    else if (x > i->elemento) i->dir = inserirRec(x, i->dir);
    else exit(1);
    return balancear(i);
}
void inserir (int x) {
    raiz = inserirRec(x, raiz);
}

bool pesquisarNo (NoAN *i, int x) {
    if (i == NULL) return false;
    else if (x == i->elemento) return true;
    else if (x < i->elemento) return pesquisarNo(i->esq, x);
    else return pesquisarNo(i->dir, x);
}
bool pesquisar (int x) {
    return pesquisarNo(raiz, x);
}

NoAN* removerNo (int x, NoAN *i) {
    if (i == NULL) exit(1);
    else if (x < i->elemento) i->esq = removerNo(x, i->esq);
    else if (x > i->elemento) i->dir = removerNo(x, i->dir);
    else if (i->dir == NULL) i = i->esq;
    else if (i->esq == NULL) i = i->dir;
    else i->esq = maiorEsq(i, i->esq);
    return i
}
void remover (int x) {
    raiz = removerNo(x, raiz);
}

NoAN* maiorEsq (NoAN *i, NoAN *j) {
    if (j->dir == NULL) {
        i->elemento = j->elemento;
        j = j->esq;
    }
    else j->dir = maiorEsq(i, j->dir);
    return j;
}
NoAN* menorDir (NoAN *i, NoAN *j) {
    if (j->esq == NULL) {
        i->elemento = j->elemento;
        j = j->dir;
    }
    else j->esq = menorDir(i, j->esq);
    return j;
}

void caminharCentral (NoAN *i) {
    if (i != NULL) {
        caminharCentral(i->esq);
        printf("%d %s ", i->elemento, (i->cor ? "(P)" : "(B)"));
        caminharCentral(i->dir);
    }
}
void caminharPre (NoAN *i) {
    if (i != NULL) {
        printf("%d %s ", i->elemento, (i->cor ? "(P)" : "(B)"));
        caminharPre(i->esq);
        caminharPre(i->dir);
    }
}
void caminharPos (NoAN *i) {
    if (i != NULL) {
        caminharPos(i->esq);
        caminharPos(i->dir);
        printf("%d %s ", i->elemento, (i->cor ? "(P)" : "(B)"));
    }
}

int getAlturaRec (NoAN *i) {
    if (i == NULL) return 0;
    else {
        int altEsq = getAlturaRec(i->esq);
        int altDir = getAlturaRec(i->dir);
        return (altEsq > altDir ) ? altEsq + 1: altDir + 1;
    }
}

int getMaior () {
    if (raiz == NULL) exit(1);
    NoAN *i;
    for (i = raiz; i->dir != NULL; i = i->dir);
    return i->elemento;
}
int getMenor () {
    if (raiz == NULL) exit(1);
    NoAN *i;
    for (i = raiz; i->esq != NULL; i = i->esq);
    return i->elemento;
}

int somarRec (NoAN *i) {
    if (i == NULL) return 0;
    return i->elemento + somarRec(i->esq) + somarRec(i->dir);
}

bool igual (NoAN *a, NoAN *b) {
    if (a == NULL && b == NULL) return true;
    else if (a == NULL || b == NULL) return false;
    else if (a->elemento != b->elemento) return false;
    else return igual(a->esq, b->esq) && igual(a->dir, b->dir);
}
bool igualArvore (NoAN *outraRaiz) {
    return igual(raiz, outraRaiz);
}
bool espelho (NoAN *a, NoAN *b) {
    if (a == NULL && b == NULL) return true;
    else if (a == NULL || b == NULL) return false;
    else if (a->elemento != b->elemento) return false;
    else return espelho(a->esq, b->dir) && espelho(a->dir, b->esq);
}
bool espelhoArvore (NoAN *outraRaiz) {
    return espelho(raiz, outraRaiz);
}
