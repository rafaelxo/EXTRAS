import java.util.Scanner;

public class exercicio2 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int menor = 0; int maior = 0;
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (i == 0) { menor = num; maior = num; }
            if (num < menor) { menor = num; }
            if (num > maior) { maior = num; }
        }
        System.out.println("Menor: " + menor);
        System.out.println("Maior: " + maior);
        sc.close();
    }
}
