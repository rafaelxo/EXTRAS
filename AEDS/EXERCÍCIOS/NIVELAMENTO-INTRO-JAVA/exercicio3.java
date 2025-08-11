import java.util.Scanner;

public class exercicio3 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int mandante = sc.nextInt(); int visitante = sc.nextInt();
        System.out.println("Resultado: ");
        if (mandante == visitante) System.out.print("Empate");
        else if (mandante > visitante) System.out.print("Mandante");
        else System.out.print("Visitante");
        sc.close();
    }
}
