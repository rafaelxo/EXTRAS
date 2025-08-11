import java.util.Scanner;

public class exercicio16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); double media = 0;
        int mat[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
                media += mat[i][j];
            }
        }
        media /= (n * n);
        System.out.println("Média: " + media);
        sc.close();
    }
}
