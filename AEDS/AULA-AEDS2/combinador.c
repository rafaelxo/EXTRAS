#include <stdio.h>
#include <stdlib.h>

int length (char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void combinacao (char str1[], char str2[]) {
    int maior = length(str1);
    if (length(str2) > maior) maior = length(str2);
    int i = 0;
    while (i < maior) {
        if (i < length(str1)) printf ("%c", str1[i]);
        if (i < length(str2)) printf("%c", str2[i]);
        i++;
    }
}

int main () {
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);
    while (scanf("%s %s", str1, str2) != EOF) {
        combinacao(str1, str2);
        printf("\n");
    }
    return 0;
}
