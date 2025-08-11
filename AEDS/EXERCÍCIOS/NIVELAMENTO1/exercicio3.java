import java.util.Scanner;

public class exercicio3 {
    public static void elementos(int vet[], int N) {
        int maior = vet[0];
        int menor = vet[0];
        for (int i = 0; i < N; i++) {
            if (vet[i] > maior) maior = vet[i];
            if (vet[i] < menor) menor = vet[i];
        }
        System.out.println("Menor: " + menor);
        System.out.println("Maior: " + maior);
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int vet[] = new int[N]; for (int i = 0; i < N; i++) vet[i] = sc.nextInt();
        elementos(vet, N);
        sc.close();
    }
}
