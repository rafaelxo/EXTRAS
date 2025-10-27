public class filaF {
    static class Celula {
        int elemento;
        Celula prox;
        public Celula (int x) {
            this.elemento = x;
            this.prox = null;
        }
    }
    static class Fila {
        Celula primeiro, ultimo;
        public Fila () {
            primeiro = new Celula(0);
            ultimo = primeiro;
        }

        public void inserir (int x) {
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        public int remover () {

        }

        public void mostrar () {

        }
    }
}
