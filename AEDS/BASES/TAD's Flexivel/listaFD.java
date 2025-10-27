public class listaFD {
    static class Celula {
        int elemento;
        Celula ant, prox;
        public Celula (int x) {
            this.elemento = x;
            this.ant = this.prox = null;
        }
    }
}
