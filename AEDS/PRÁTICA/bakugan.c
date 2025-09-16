#include <stdio.h>
#include <stdbool.h>

int main () {
    int n; scanf("%d", &n);
    while (n != 0) {
        int mark[n], leti[n];
        int sMark = 0, sLeti = 0;
        bool lMark = false, lLeti = false;
        for (int i = 0; i < n; i++) scanf ("%d", mark[i]);
        for (int i = 0; i < n; i++) scanf("%d", leti[i]);
        for (int i = 0; i < n; i++) {
            sMark += mark[i];
            sLeti += leti[i];
            if (n >= 3 && (mark[i] == mark[i + 1] && mark[i + 1] == mark[i + 2])) {
                lMark = true;
                sMark += 30;
            }
            if (lMark == false && n >= 3 && (leti[i] == leti[i + 1] && leti[i + 1] == leti[i + 2])) {
                lLeti = true;
                sLeti += 30;
            }
            if (lMark && lLeti) {
                sMark -= 30;
                sLeti -= 30;
            }
        }
        if (sMark > sLeti) printf("M\n");
        else if (sLeti > sMark) printf("L\n");
        else printf("T\n");
        scanf("%d", &n);
    }
}
