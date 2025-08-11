import java.util.Scanner;

public class exercicio4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double salario = sc.nextDouble(); double prestacao = sc.nextDouble();
        if (prestacao <= salario * 0.3) System.out.println("Empréstimo aprovado!");
        else System.out.println("Empréstimo não aprovado!");
        sc.close();
    }
}
