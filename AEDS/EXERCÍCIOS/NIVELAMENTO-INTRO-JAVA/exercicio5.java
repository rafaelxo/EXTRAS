import java.util.Scanner;

public class exercicio5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = 0;
        while (i < n) {
            int num = sc.nextInt();
            if (num % 2 == 0) System.out.println("Par!");
            else System.out.println("Ímpar");
            i++;
        }
        sc.close();
    }
}
