import java.util.*;

public class pilha {
    public static Scanner sc = new Scanner (System.in);

    static class Celula {
        public int elemento;
        public Celula prox;
        public Celula (int x) {
            elemento = x;
            prox = null;
        }
    }
    static class Pilha {
        private Celula topo;
        public Pilha () { topo = null; }
        public void push (int x) {
            Celula tmp = new Celula (x);
            tmp.prox = topo;
            topo = tmp;
            tmp = null;
        }
        public int pop () {
            if (topo == null) throw new RuntimeException ("Erro!");
            int resp = topo.elemento;
            Celula tmp = topo;
            topo = topo.prox;
            tmp.prox = null;
            tmp = null;
            return resp;
        }
    }

    public static boolean resolver (Pilha p1, Pilha p2, Pilha p3) {
        
        return false;
    }

    public static void main (String[] args) {
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            Pilha p1 = new Pilha (), p2 = new Pilha (), p3 = new Pilha ();
            for (int i = 0; i < n; i++) {
                int valor = sc.nextInt(); p1.push (valor);
                valor = sc.nextInt(); p2.push (valor);
                valor = sc.nextInt(); p3.push (valor);
            }
            System.out.println(resolver(p1, p2, p3) ? "1" : "0");
            n = sc.nextInt();
        }
    }
}
