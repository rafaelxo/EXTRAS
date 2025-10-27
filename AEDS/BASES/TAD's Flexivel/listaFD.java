public class listaFD {
    static class Celula {
        int elemento;
        Celula ant, prox;
        public Celula (int x) {
            this.elemento = x;
            this.ant = this.prox = null;
        }
    }

    static class Lista {
        private Celula primeiro, ultimo;
        public Lista () {
            primeiro = new Celula(0);
            ultimo = primeiro;
        }

        public void inserirIni (int x) {
            primeiro.elemento = x;
            Celula tmp = new Celula(0);
            tmp.prox = primeiro;
            primeiro.ant = tmp;
            primeiro = tmp;
            tmp = null;
        }
        public void inserirPos (int x, int pos) {
            if (pos < 0 || pos > tamanho()) throw new RuntimeException("Erro!");
            else if (pos == 0) inserirIni(x);
            else if (pos == tamanho()) inserirFim(x);
            else {
                Celula i = primeiro;
                for (int j = 0; j < pos; j++, i = i.prox);
                Celula tmp = new Celula(x);
                tmp.ant = i;
                tmp.prox = i.prox;
                i.prox = tmp.prox.ant = tmp;
                tmp = i = null;
            }
        }
        public void inserirFim (int x) {
            ultimo.prox = new Celula(x);
            ultimo.prox.ant = ultimo;
            ultimo = ultimo.prox;
        }

        public int removerIni () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            Celula tmp = primeiro.prox;
            int resp = tmp.elemento;
            primeiro.prox = tmp.prox;
            if (primeiro.prox != null) primeiro.prox.ant = primeiro;
            else ultimo = primeiro;
            tmp = tmp.prox = tmp.ant = null;
            return resp;
        }
        public int removerPos (int pos) {
            if (primeiro == ultimo || pos < 0 || pos >= tamanho()) throw new RuntimeException("Erro!");
            else if (pos == 0) return removerIni();
            else if (pos == tamanho() - 1) return removerFim();
            else {
                Celula i = primeiro.prox;
                for (int j = 0; j < pos; j++) i = i.prox;
                int resp = i.elemento;
                i.ant.prox = i.prox;
                i.prox.ant = i.ant;
                i = i.ant = i.prox = null;
                return resp;
            }
        }
        public int removerFim () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            int resp = ultimo.elemento;
            ultimo = ultimo.ant;
            ultimo.prox.ant = ultimo.prox = null;
            return resp;
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
