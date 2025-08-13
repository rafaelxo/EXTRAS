import java.util.Scanner;

public class contMaiusc {
    public static int contarMaiusculas (String str) {
        int quant = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isUpperCase(str.charAt(i))) quant++;
        }
        return quant;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        while (!str.equals("FIM")) {
            System.out.println(contarMaiusculas(str));
            str = sc.nextLine();
        }
        sc.close();
    }
}
