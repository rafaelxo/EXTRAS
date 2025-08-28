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
    scanf(" %s", str1); scanf(" %s", str2);
    while (!(str1[0] == 'F' && str1[1] == 'I' && str1[2] == 'M' && str1[3] == '\0')) {
        combinacao (str1, str2);
        printf("\n");
        scanf(" %s", str1); scanf(" %s", str2);
    }
    return 0;
}
