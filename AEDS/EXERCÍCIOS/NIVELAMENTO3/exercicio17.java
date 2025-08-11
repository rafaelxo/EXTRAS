import java.util.Scanner;

public class exercicio17 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] mediaL = new double[n]; double[] mediaC = new double[n];
        int mat[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
                mediaL[i] += mat[i][j];
                mediaC[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            mediaL[i] /= n; mediaC[i] /= n;
            System.out.println("Média da linha " + (i + 1) + ": " + mediaL[i]);
            System.out.println("Média da coluna " + (i + 1) + ": " + mediaC[i]);
        }
        sc.close();
    }
}
