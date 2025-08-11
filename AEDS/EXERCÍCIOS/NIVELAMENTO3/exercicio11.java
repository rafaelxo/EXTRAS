import java.util.Scanner;

public class exercicio11 {
    public static void swap () {

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) array[i] = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int menor = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[menor]) menor = j;
            }
            swap ()
        }
        sc.close();
    }
}
