#include <stdio.h>

int contMaiuscRec (char str[], int i) {
    if (str[i] == '\0') return 0;
    else if (str[i] >= 'A' && str[i] <= 'Z') return 1 + contMaiuscRec(str, i + 1);
    else return contMaiuscRec(str, i + 1);
}

int main () {
    char str[100]; scanf(" %[^\n]", str);
    while (!(str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0')) {
        printf("%d\n", contMaiuscRec(str, 0));
        scanf(" %[^\n]", str);
    }
    return 0;
}
