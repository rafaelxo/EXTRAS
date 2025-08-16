#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int array[], int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(esq + dir) / 2];
    while (i <= j) {
        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;
        if (i <= j) {
            swap(&array[i], &array[j]);
            i++; j--;
        }
    }
    if (esq < j) quicksort(array, esq, j);
    if (i < dir) quicksort(array, i, dir);
}

void ordenar(int array[], int n) {
    quicksort(array, 0, n - 1);
}

int main() {
    int n; scanf("%d", &n);
    int array[n]; for (int i = 0; i < n; i++) scanf("%d", &array[i]);
    ordenar(array, n);
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
}
