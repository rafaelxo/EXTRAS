import java.util.Scanner;

public class exercicio1 {
    public static int triang (int a, int b, int c) {
        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && b == c) return 3;
            else if (a == b || b == c || a == c) return 2;
            else return 1;
        }
        return 0;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt();
        int tipo = triang(a, b, c);
        if (tipo == 3) System.out.println("Equilátero!");
        else if (tipo == 2) System.out.println("Isósceles!");
        else if (tipo == 1) System.out.println("Escaleno!");
        else System.out.println("Inválido!");
        sc.close();
    }
}
