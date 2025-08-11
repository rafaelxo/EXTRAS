import java.util.Scanner;

public class exercicio15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mat[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) mat[i][j] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) System.out.print(mat[i][i] + " ");
        for (int i = 0; i < n; i++) System.out.print(mat[i][n-1-i] + " ");
        sc.close();
    }
}
