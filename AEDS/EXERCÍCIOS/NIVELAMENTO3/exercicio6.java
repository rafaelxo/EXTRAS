import java.util.Scanner;

public class exercicio6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double media = 0;
        int i = 0;
        while (i < n) {
            int num = sc.nextInt();
            media += num;
            i++;
        }
        media /= n;
        System.out.print("Média: " + media);
        sc.close();
    }
}
