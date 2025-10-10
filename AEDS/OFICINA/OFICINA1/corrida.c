#include <stdio.h>
#include <stdbool.h>

typedef struct Corredor {
    char nome[100];
    char sexo;
} Corredor;

int comparaNomes(char str1[], char str2[]) {
    int tam = (a.length() < b.length()) ? a.length() : b.length();
    for (int i = 0; i < tam; i++) {
        if (a.charAt(i) < b.charAt(i)) return -1;
        if (a.charAt(i) > b.charAt(i)) return 1;
    }
    if (a.length() < b.length()) return -1;
    if (a.length() > b.length()) return 1;
    return 0;
}

void swap(Corredor[] cod, int i, int j) {
    Corredor aux = cod[i];
    cod[i] = cod[j];
    cod[j] = aux;
}

void selecao(Corredor[] cod, int n) {
    for (int i = 0; i < n - 1; i++) {
        int melhor = i;
        for (int j = i + 1; j < n && cod[i] == 'F'; j++) {
            if (cod[j].sexo() > cod[melhor].getMedia()) melhor = j;
        }
        swap(jog, i, melhor);
    }
}

int main () {
    int n; scanf("%d", &n);
    Corredor cod[n];
    for (int i = 0; i < n; i++) {
        char n[100]; scanf(" %[^\n]", n);
        char c; scanf(" %c", &c);
        cod[i].nome = n; cod[i].sexo = c;
    }
    selecao(cod, n);
    for (int i = 0; i < n; i++) printf("%s %c", cod[i].nome, cod[i].sexo);
}
