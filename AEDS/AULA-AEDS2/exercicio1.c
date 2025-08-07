#include <stdlib.h>
#include <stdio.h>

int contMaiusc (char *str) {
    int quant = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') quant++;
    }
    return quant;
}

int main () {
    char *str = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", str);
    while (str[0] != 'F' && str[1] != 'I' && str[2] != 'M' && str[3] == '\0') {
        printf("%d\n", contMaiusc(str));
        scanf(" %[^\n]", str);
    }
}
