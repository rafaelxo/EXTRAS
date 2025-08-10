#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main () {
    char nomeArq[100]; scanf("%s", nomeArq);
    FILE *arq = fopen(nomeArq, "w");
    char frase[100]; scanf(" %[^\n]", frase);
    fprintf(arq, "%s", frase);
    fclose(arq);
    arq = fopen(nomeArq, "r");
    char fraseLida[100];
    fscanf(arq, " %[^\n]", fraseLida);
    printf("%s\n", fraseLida);
    fclose(arq);
    for (int i = 0; fraseLida[i] != '\0'; i++) fraseLida[i] = toupper(fraseLida[i]);
    printf("%s\n", fraseLida);
    char nomeArq2[100]; scanf("%s", nomeArq2);
    FILE *arq2 = fopen(nomeArq2, "w");
    fprintf(arq2, "%s", fraseLida);
    fclose(arq2);
}
