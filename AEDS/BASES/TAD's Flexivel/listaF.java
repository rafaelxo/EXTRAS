public class listaF {
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
        public Lista (int x) {
            primeiro = new Celula(x);
            ultimo = primeiro;
        }

        public void inserirIni (int x) {
            primeiro.elemento = x;
            Celula tmp = new Celula(0);
            tmp.prox = primeiro;
            primeiro = tmp;
            tmp = null;
        }
        public void inserirPos (int x, int pos) {
            if (pos == 0) inserirIni(x);
            else if (pos == tamanho()) inserirFim(x);
            else {
                Celula i = primeiro;
                for (int j = 0; j < pos; j++, i = i.prox);
                Celula tmp = new Celula(x);
                tmp.prox = i.prox;
                i.prox = tmp;
                tmp = null;
            }
        }
        public void inserirFim (int x) {
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        public int removerIni () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            Celula tmp = primeiro.prox;
            int resp = tmp.elemento;
            primeiro.prox = tmp.prox;
            tmp = tmp.prox = null;
            return resp;
        }
        public int removerPos (int pos) {
            if (pos == 0) return removerIni();
            else if (pos == tamanho() - 1) return removerFim();
            else {
                Celula i = primeiro;
                for (int j = 0; j < pos; j++, i = i.prox);
                Celula tmp = i.prox;
                int resp = tmp.elemento;
                i.prox = tmp.prox;
                tmp = tmp.prox = null;
                return resp;
            }
        }
        public int removerFim () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            Celula i;
            for (i = primeiro; i.prox != ultimo; i = i.prox);
            int resp = ultimo.elemento;
            ultimo = i;
            i = i.prox = null;
            return resp;
        }

        public int tamanho () {
            int tamanho = 0;
            for (Celula i = primeiro; i != null; i = i.prox, tamanho++);
            return tamanho;
        }
    }
}
