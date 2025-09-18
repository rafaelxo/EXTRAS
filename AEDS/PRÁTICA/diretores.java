import java.util.*;

public class diretores {
    public static Scanner sc = new Scanner (System.in);
    public static void main (String[] args) {
        while (sc.hasNextInt()) {
            int n = sc.nextInt(); int k = sc.nextInt();
            if ((k / n) >= 1) System.out.println(k / n);
        }
    }
}
