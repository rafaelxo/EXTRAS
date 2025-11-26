public class hashListaF {
    static class Celula {
        private int elemento;
        private Celula prox;
        public Celula (int x) {
            this.elemento = x;
            this.prox = null;
        }
    }

    static class Lista {
        private Celula primeiro, ultimo;
        public Lista () {
            primeiro = new Celula(0);
            ultimo = primeiro;
        }

        public void inserir (int x) {
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        public int remover (int x) {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            else {
                Celula tmp = primeiro;
                Celula i = primeiro.prox;
                while (i != null && i.elemento != x) {
                    tmp = i;
                    i = i.prox;
                }
                if (i != null) {
                    tmp.prox = i.prox;
                    i.prox = null;
                    if (i == ultimo) ultimo = tmp;
                    return i.elemento;
                }
            }
            return -1;
        }

        int pesquisar (int x) {
            int pos = 0;
            for (Celula i = primeiro.prox; i != null; i = i.prox, pos++) {
                if (i.elemento == x) return pos;
            }
            return -1;
        }

        public int tamanho () {
            int tamanho = 0;
            for (Celula i = primeiro.prox; i != null; i = i.prox) tamanho++;
            return tamanho;
        }

        public void mostrar () {
            System.out.print("[ ");
            for (Celula i = primeiro.prox; i != null; i = i.prox) System.out.print(i.elemento + " ");
            System.out.println("]");
        }
    }
}
