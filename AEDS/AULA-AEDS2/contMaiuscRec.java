import java.util.*;

public class contMaiuscRec {
    public static Scanner sc = new Scanner (System.in);
    public static int contarMaiusculasRecursivo (String str) {
        if (str.length() == 0) return 0;
        else if (str.charAt(0) >= 'A' && str.charAt(0) <= 'Z') return 1 + contarMaiusculasRecursivo (str.substring(1));
        else return contarMaiusculasRecursivo (str.substring(1));
    }
    public static void main (String[] args) {
        String str = sc.nextLine();
        while (!(str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M')) {
            System.out.println(contarMaiusculasRecursivo(str));
            str = sc.nextLine();
        }
        sc.close();
    }
}
