import java.util.Scanner;

public class exercicio1 {
    public static int contVogal(String str) {
        if (str.length() == 0) return 0;
        char c = str.charAt(0);
        if (c >= 'a' && c <= 'z') c = (char) (c - 32);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1 + contVogal(str.substring(1));
        else return contVogal(str.substring(1));
    }
    public static int contConsoante(String str) {
        if (str.length() == 0) return 0;
        char c = str.charAt(0);
        if (c >= 'a' && c <= 'z') c = (char) (c - 32);
        if ((c >= 'A' && c <= 'Z') && !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) return 1 + contConsoante(str.substring(1));
        else return contConsoante(str.substring(1));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("Vogais: " + contVogal(str));
        System.out.println("Consoantes: " + contConsoante(str));
        sc.close();
    }
}
