//Questão 1
float funcao (int N) {
    if (N == 1) return 1;
    else return (funcao (N-2) + N);
}

//a | (funcao (9) + 11) - (funcao (7) + 9) - (funcao (5) + 7) - (funcao (3) + 5) - (funcao (1) + 3) = 1 + 3 = 4 + 5 = 9 + 7 = 16 + 9 = 25 + 11 = 36
//b | (funcao (3) + 5) - (funcao (1) + 3) = 1 + 3 = 4 + 5 = 9

//Questão 2
int N;
float num, maior_i;
scanf("%d", &N);
for (int cont1 = 1; cont1 <= N; cont1++) {
    scanf("%f", &num);
    if (fmod(num,2) != 0) {
        if (num > maior_i) {
            maior_i = num;
        }
    }
}
printf("%f", maior_i);

//Questão 3
float calcula (int N, int x) {
    float num = x, den = N, E = num/den;
    for (int cont1 = num; cont1 <= N; cont1++) {
        den--;
        num *= cont1;
        E += num/den;
    }
    return E;
}

int main() {
    int N, x;
    float E;
    scanf("%d%d", &N, &x);
    printf("%f", calcula(N, x));
}