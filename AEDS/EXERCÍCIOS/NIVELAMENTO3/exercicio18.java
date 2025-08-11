import java.util.Scanner;

public class exercicio18 {
    public static boolean isVogal(char c) {
        c = Character.toLowerCase(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    public static boolean isConsoante(char c) {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && !isVogal(c);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String palavra = sc.nextLine();
        System.out.println("Tamanho da palavra: " + palavra.length());
        int letras = 0; int simb = 0; int vog = 0; int cons = 0;
        for (int i = 0; i < palavra.length(); i++) {
            char carac = palavra.charAt(i);
            if (carac >= 65 && carac <= 90 || carac >= 97 && carac <= 122) letras++;
            else simb++;
            if (isVogal(carac)) vog++;
            if (isConsoante(carac)) cons++;
        }
        System.out.println("Letras: " + letras);
        System.out.println("Símbolos: " + simb);
        System.out.println("Vogais: " + vog);
        System.out.println("Consoantes: " + cons);
        sc.close();
    }
}
