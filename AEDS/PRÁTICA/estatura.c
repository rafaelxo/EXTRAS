#include <stdio.h>

int main () {
    int n, h;
    scanf("%d%d", &n, &h);
    int brinq[n];
    int cont = 0;
    for (int i = 0; i < n; i++) scanf("%d", &brinq[i]);
    for (int i = 0; i < n; i++) {
        if (h >= brinq[i]) cont++;
    }
    printf("%d\n", cont);
}
