import java.util.Scanner;

public class contMaiuscRec {
    public static int contarMaiusculasRecursivo (String str) {
        if (str.isEmpty()) return 0;
        else if (str.charAt(0) >= 'A' && str.charAt(0) <= 'Z') return 1 + contarMaiusculasRecursivo (str.substring(1));
        else return contarMaiusculasRecursivo (str.substring(1));
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        while (!str.equals("FIM")) {
            System.out.println(contarMaiusculasRecursivo(str));
            str = sc.nextLine();
        }
        sc.close();
    }
}
