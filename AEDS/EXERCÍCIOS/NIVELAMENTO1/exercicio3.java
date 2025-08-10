import java.util.Scanner;

public static void elementos(int vet[], int N) {
    int maior = vet[0]; int menor = vet[0];
    for (int i = 0; i < N; i++) {
        if (vet[i] > maior) maior = vet[i];
        if (vet[i] < menor) menor = vet[i];
    }
    printf("Menor: %d\nMaior: %d\n", menor, maior);
}

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int vet[] = new int[N]; for (int i = 0; i < N; i++) vet[i] = sc.nextInt();
        elementos(vet, N);
    }
}
