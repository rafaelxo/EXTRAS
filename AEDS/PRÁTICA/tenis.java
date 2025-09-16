import java.util.*;

public class tenis {
    public static Scanner sc = new Scanner (System.in);

    public static void main (String[] args) {
        int vit = 0;
        for (int i = 0; i < 6; i++) {
            char c = sc.next().charAt(0);
            if (c == 'V') vit++;
        }
        if (vit >= 5) System.out.println("1");
        else if (vit >= 3 && vit <= 4) System.out.println("2");
        else if (vit >= 1 && vit <= 6) System.out.println("3");
        else System.out.println("-1");
    }
}
