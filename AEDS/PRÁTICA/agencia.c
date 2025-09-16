#include <stdio.h>

int main () {
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF) {
        int SA[x], SB[y];
        for (int i = 0; i < x; i++) scanf("%d", &SA[i]);
        for (int i = 0; i < y; i++) scanf("%d", &SB[i]);
        int i = 0, j = 0;
        while (i < x && j < y) {
            if (SA[i] == SB[j]) j++;
            i++;
        }
        if (j == y) printf("S\n");
        else printf("N\n");
    }
}
