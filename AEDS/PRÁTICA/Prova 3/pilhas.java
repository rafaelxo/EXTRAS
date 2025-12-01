import java.util.*;

public class pilhas {
    public static Scanner sc = new Scanner (System.in);

    static class Celula {
        public int elemento;
        public Celula prox;

        public Celula (int elemento) {
            this.elemento = elemento;
            this.prox = null;
        }
    }

    static class Pilha {
        private Celula topo;

        public Pilha () { topo = null; }

        public void push (int x) {
            Celula nova = new Celula(x);
            nova.prox = topo;
            topo = nova;
        }

        public int pop () throws Exception {
            if (tamanho == 0) throw new Exception ("Erro ao remover: pilha vazia!");
            int resp = topo.elemento;
            topo = topo.prox;
            tamanho--;
            return resp;
        }

        public int top () throws Exception {
            if (tamanho == 0) throw new Exception ("Erro ao consultar: pilha vazia!");
            return topo.elemento;
        }

        public boolean isEmpty () {
            return (tamanho == 0);
        }

        public int size () {
            return tamanho;
        }
    }

    public static void main (String[] args) {

    }
}
