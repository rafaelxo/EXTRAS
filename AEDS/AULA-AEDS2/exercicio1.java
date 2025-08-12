import java.util.Scanner;

public class exercicio1 {
    public static int contMaiusc(String str) {
        int quant = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isUpperCase(str.charAt(i))) quant++;
        }
        return quant;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        while (!str.equals("FIM")) {
            System.out.println(contMaiusc(str));
            str = sc.nextLine();
        }
        sc.close();
    }
}
