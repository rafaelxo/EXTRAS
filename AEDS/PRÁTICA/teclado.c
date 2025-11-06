#include <stdio.h>
#include <string.h>

int main() {
    char linha[1001];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        int abriu = 0;
        char dentro[1001] = "";
        char normal[1001] = "";
        int iDentro = 0;
        int iNormal = 0;

        linha[strcspn(linha, "\n")] = 0;

        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == '[') abriu++;
            if (linha[i] == ']') abriu--;
            if (abriu > 0 && linha[i] != '[') dentro[iDentro++] = linha[i];
            if (abriu == 0 && (linha[i] != '[' && linha[i] != ']')) normal[iNormal++] = linha[i];
        }
        dentro[iDentro] = '\0';
        normal[iNormal] = '\0';

        if (strlen(dentro) > 1) printf("%s%s\n", dentro, normal);
        else printf("%s\n", normal);
    }

    return 0;
}
