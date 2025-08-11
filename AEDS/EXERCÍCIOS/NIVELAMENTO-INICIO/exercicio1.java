import java.util.Scanner;

public class exercicio1 {
    public static int comparar(int vet[], int N, int x) {
        for (int i = 0; i < N; i++) {
            if (vet[i] == x)
                return 1;
        }
        return 0;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int vet[] = new int[N]; for (int i = 0; i < N; i++) vet[i] = sc.nextInt();
        int x = sc.nextInt();
        int comp = comparar(vet, N, x);
        if (comp == 1) System.out.println("SIM");
        else System.out.println("NAO");
        sc.close();
    }
}
