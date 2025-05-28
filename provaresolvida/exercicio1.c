void modulo1 (int *vet, int N) {
    for (int pos = 0; pos < N; pos++) {
        scanf("%d", (vet + pos));
    }
}

void modulo2 (int *dados, int N) {
    printf("Conteúdo: ");
    for (int i =0; i < N; i++) {
        printf("%d ", *(dados + i));
    }
}

int main () {
    int total = 10;
    int *valores = (int*)malloc(total*sizeof(int));
    modulo1(valores, total);
    modulo2(valores, total);
}