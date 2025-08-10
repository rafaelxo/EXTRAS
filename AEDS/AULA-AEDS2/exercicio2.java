import java.util.Scanner;

public class Main {
    public static int contMaiuscRec(String str) {
        if (str.isEmpty()) return 0;
        else if (Character.isUpperCase(str.charAt(0))) return 1 + contMaiuscRec(str.substring(1));
        else return contMaiuscRec(str.substring(1));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        while (!str.equals("FIM")) {
            System.out.println(contMaiuscRec(str));
            str = sc.nextLine();
        }
        sc.close();
    }
}
