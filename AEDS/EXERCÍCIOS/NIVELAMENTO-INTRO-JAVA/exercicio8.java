import java.util.Scanner;

public class exercicio8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt(); double media = 0;
        double[] nums = new double[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextDouble();
            media += nums[i];
        }
        media /= n;
        System.out.println("Média: " + media);
        for (int i = 0; i < n; i++) {
            if (nums[i] > media) System.out.println("Numero " + (i + 1) + " acima da média!");
            else System.out.println("Numero " + (i + 1) + " abaixo da média!");
        }
        sc.close();
    }
}
