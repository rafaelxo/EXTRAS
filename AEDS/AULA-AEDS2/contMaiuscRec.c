#include <stdlib.h>
#include <stdio.h>

int contMaiuscRec (char str[]) {
    if (str[0] == '\0') return 0;
    else if (str[0] >= 'A' && str[0] <= 'Z') return 1 + contMaiuscRec(str + 1);
    else return contMaiuscRec(str + 1);
}

int main () {
    char str[100];
    scanf(" %[^\n]", str);
    while (!(str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0')) {
        printf("%d\n", contMaiuscRec(str));
        scanf(" %[^\n]", str);
    }
}
