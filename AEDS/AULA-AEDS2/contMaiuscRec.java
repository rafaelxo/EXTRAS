import java.util.*;

public class contMaiuscRec {
    public static Scanner sc = new Scanner (System.in);
    public static int contarMaiusculasRecursivo (String str, int i) {
        if (str.length() == 0) return 0;
        else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') return 1 + contarMaiusculasRecursivo (str, i + 1);
        else return contarMaiusculasRecursivo (str, i + 1);
    }
    public static void main (String[] args) {
        String str = sc.nextLine();
        while (!(str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M')) {
            System.out.println(contarMaiusculasRecursivo(str, 0));
            str = sc.nextLine();
        }
        sc.close();
    }
}
