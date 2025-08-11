import java.util.Scanner;

public class exercicio2 {
    public static int compararOrd(int vet[], int N, int x) {
        int esq = 0;
        int dir = N - 1;
        while (esq <= dir) {
            int meio = (esq + dir) / 2;
            if (vet[meio] < x) esq = meio + 1;
            else if (vet[meio] > x) dir = meio - 1;
            else return 1;
        }
        return 0;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int vet[] = new int[N]; for (int i = 0; i < N; i++) vet[i] = sc.nextInt();
        int x = sc.nextInt();
        int comp = compararOrd(vet, N, x);
        if (comp == 1) System.out.println("SIM");
        else System.out.println("NAO");
        sc.close();
    }
}
