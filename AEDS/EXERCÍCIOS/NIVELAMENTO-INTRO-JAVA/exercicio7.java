import java.util.Scanner;

public class exercicio7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int acima = 0;
        double media = 0; double maior = 0;
        int i = 0;
        while (i < n) {
            double num = sc.nextDouble();
            media += num;
            if (num > maior) maior = num;
            if (num > 60) {
                System.out.println("Acima da média!");
                acima++;
            }
            if (num > 90) System.out.println("Conceito A!");
        }
        media /= n;
        System.out.println("Média: " + media);
        System.out.println("Maior: " + maior);
        System.out.println("Acima de 60: " + acima);
        sc.close();
    }
}
