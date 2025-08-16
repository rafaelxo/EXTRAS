#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int contVogal (char *str) {
    str[0] = toupper(str[0]);
    if (str[0] == '\0') return 0;
    else if (str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U') return 1 + contVogal(str + 1);
    else return contVogal(str + 1);
}

int contConsoante (char *str) {
    str[0] = toupper(str[0]);
    if (str[0] == '\0') return 0;
    else if ((str[0] >= 'A' && str[0] <= 'Z') && !(str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U')) return 1 + contConsoante(str + 1);
    else return contConsoante(str + 1);
}

int main () {
    char str[100];
    scanf(" %[^\n]", str);
    printf("Vogais: %d\n", contVogal(str));
    printf("Consoantes: %d\n", contConsoante(str));
}
