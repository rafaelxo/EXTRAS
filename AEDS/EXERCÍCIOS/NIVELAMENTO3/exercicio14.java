import java.util.Scanner;

public class exercicio14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mat1[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) mat1[i][j] = sc.nextInt();
        }
        int mat2[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) mat2[i][j] = sc.nextInt();
        }
        int mat3[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(mat3[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
