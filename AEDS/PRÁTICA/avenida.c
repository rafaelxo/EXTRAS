#include <stdio.h>

int main () { // main do programa
    int d; scanf("%d", &d); // declaracao e leitura da distancia
    int i = 0;
    while (i <= 2000) { // loop para verificar os pontos de onibus de 0 a 2000
        if (d <= i) { // se a distancia for menor ou igual ao proximo ponto de onibus
            int meio = (i + (i - 400)) / 2; // definicao de um meio para comparar se luiza desce no ponto atual ou no anterior
            if (d == meio) printf("%d\n", i - meio); // se a distancia for igual ao meio, ela anda do ponto atual ate o meio
            else if (d < meio) printf("%d\n", d - (i - 400)); // se a distancia for menor que o meio, ela desce no ponto anterior
            else if (d > meio) printf("%d\n", i - d); // se nao, desce no ponto atual
            i = 2001; // atribuicao de i maior que a condicao do laco para sair
        }
        i += 400; // incremento de 400 em 400 para cada ponto de onibus
    }
    return 0;
}