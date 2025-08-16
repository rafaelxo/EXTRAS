import java.util.Scanner;

public class exercicio1 {
    public static int contVogal (String str) {
        if (str.length() == 0) return 0;
        else if (str.charAt(0) == 'A' || str.charAt(0) == 'E' || str.charAt(0) == 'I' || str.charAt(0) == 'O' || str.charAt(0) == 'U') return 1 + contVogal(str.substring(1));
        else return contVogal(str.substring(1));
    }
    public static int contConsoante (String str) {
        if (str.length() == 0) return 0;
        else if ((str.charAt(0) >= 'A' && str.charAt(0) <= 'Z') && !(str.charAt(0) == 'A' || str.charAt(0) == 'E' || str.charAt(0) == 'I' || str.charAt(0) == 'O' || str.charAt(0) == 'U')) return 1 + contConsoante(str.substring(1));
        else return contConsoante(str.substring(1));
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("Vogais: " + contVogal(str));
        System.out.println("Consoantes: " + contConsoante(str));
        sc.close();
    }
}
