#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tamTab = 0;

int* inicializar (int x, int y) {
    tamTab = x;
    int* tabela = (int*)malloc(x*sizeof(int*));
    for (int i = 0; i < x; i++) tabela[i] = -1;
    return tabela;
}

int hashar (int x) { return x % tamTab; }
int rehashar (int x) { return ++x % tamTab; }

void inserir (int x, int* tabela) {
    if (x != -1) {
        int i = hashar(x);
        if (tabela[i] == -1) tabela[i] = x;
        else if (tabela[i] != x) {
            int j = rehashar(x);
            if (tabela[j] == -1) tabela[j] = x;
        }
        else printf("Erro!\n");
    }
}

bool pesquisar (int x, int* tabela) {
    int i = hashar(x);
    if (tabela[i] == x) return true;
    if (tabela[i] != -1) {
        int j = rehashar(x);
        if (tabela[j] == x) return true;
    }
    return false;
}

int remover (int x, int* tabela, int* reserva) {
    int i = hashar(x);
    if (tabela[i] == x) {
        tabela[i] = -1;
        return i;
    } else {
        int j = rehashar(x);
        if (tabela[j] == x) {
            tabela[j] = -1;
            return j;
        }
    }
    return -1;
}



