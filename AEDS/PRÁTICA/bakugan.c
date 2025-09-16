#include <stdio.h>

int main () {
    int n; scanf("%d", &n);
    while (n != 0) {
        int mark[n], leti[n];
        int sMark = 0, sLeti = 0;
        for (int i = 0; i < n; i++) scanf ("%d", mark[i]);
        for (int i = 0; i < n; i++) scanf("%d", leti[i]);
        for (int i = 0; i < n; i++) {
            sMark += mark[i];
            sLeti += leti[i];
        }
        
        if (sMark > sLeti) printf("M\n");
        else if (sLeti > sMark) printf("L\n");
        else printf("T\n");
        scanf("%d", &n);
    }
}
