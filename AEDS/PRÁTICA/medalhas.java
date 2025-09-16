import java.util.*;

public class medalhas {
    public class Pais {
        private String nome;
        private int ouro, prata, bronze;
        Pais () {
            this.nome = "nenhum";
            this.ouro = 0;
            this.prata = 0;
            this.bronze = 0;
        }
        Pais (String str, int o, int p, int b) {
            this.nome = str;
            this.ouro = o;
            this.prata = p;
            this.bronze = b;
        }
        public String getNome() { return nome; }
        public int getOuro() { return ouro; }
        public int getPrata() { return prata; }
        public int getBronze() { return bronze; }
    }
    public static Scanner sc = new Scanner (System.in);
    public static void main (String[] args) {
        int n = sc.nextInt();
        Pais[] paises = new Pais[n];
        for (int i = 0; i < n; i++) {
            String nome = sc.next();
            int ouro = 0, prata = 0, bronze = 0;
        }
    }
}
