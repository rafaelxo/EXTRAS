import java.util.Scanner;

public class exercicio4 {
    public static void elementosOtim(int vet[], int N) {
        int maior = vet[0];
        int menor = vet[0];
        for (int i = 1; i < N - 1; i += 2) {
            if (vet[i] > vet[i + 1]) {
                if (vet[i] > maior) maior = vet[i];
                if (vet[i + 1] < menor) menor = vet[i + 1];
            } else {
                if (vet[i + 1] > maior) maior = vet[i + 1];
                if (vet[i] < menor) menor = vet[i];
            }
        }
        System.out.println("Menor: " + menor);
        System.out.println("Maior: " + maior);
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int vet[] = new int[N]; for (int i = 0; i < N; i++) vet[i] = sc.nextInt();
        elementosOtim(vet, N);
    }
}
