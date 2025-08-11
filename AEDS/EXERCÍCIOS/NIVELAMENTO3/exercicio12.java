import java.util.Scanner;

public class exercicio12 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int vet1[] = new int[n]; for (int i = 0; i < n; i++) vet1[i] = sc.nextInt();
        int vet2[] = new int[n]; for (int i = 0; i < n; i++) vet2[i] = sc.nextInt();
        int i = 0;
        while (i < n) {
            System.out.print(vet1[i] + vet2[i]);
            i++;
        }
        sc.close();
    }
}
