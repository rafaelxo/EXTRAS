import java.util.*;

public class dicionario {
    public static Scanner sc = new Scanner(System.in, "UTF-8");

    public static class No {
        private String elemento;
        private No esq, dir;

        public No (String x) {
            this.elemento = x;
            this.esq = this.dir = null;
        }

        public No (String x, No esq, No dir) {
            this.elemento = x;
            this.esq = esq;
            this.dir = dir;
        }
    }

    public static class Arvore {
        private No raiz;
        public Arvore () {
            this.raiz = null;
        }

        private No inserirRef (String x, No i) {
            if (i == null) i = new No(x);
            else if (x.compareToIgnoreCase(i.elemento) < 0) i.esq = inserirRef(x, i.esq);
            else if (x.compareToIgnoreCase(i.elemento) > 0) i.dir = inserirRef(x, i.dir);
            return i;
        }
        public void inserir (String x) {
            raiz = inserirRef(x, raiz);
        }

        public void caminharCentral (No i) {
            if (i != null) {
                caminharCentral(i.esq);
                System.out.println(i.elemento);
                caminharCentral(i.dir);
            }
        }
        public void caminharCentral () {
            caminharCentral(raiz);
        }
    }

    public static void main (String[] args) {
        Arvore arvore = new Arvore();
        while (sc.hasNextLine()) {
            String str = sc.nextLine();
            String palavra = "";
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (Character.isLetter(c)) palavra += Character.toLowerCase(c);
                else if (palavra.length() > 0) {
                    arvore.inserir(palavra);
                    palavra = "";
                }
            }
            if (palavra.length() > 0) arvore.inserir(palavra);
        }
        arvore.caminharCentral();
    }
}
