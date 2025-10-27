public class matrizF {
    static class Celula {
        int elemento;
        Celula esq, dir, sup, inf;
        public Celula (int x) {
            this.elemento = x;
            this.esq = this.dir = this.sup = this.inf = null;
        }
    }
    static class Matriz {
        Celula inicio;
        int linhas, colunas;
        public Matriz (int lin, int col) {
            this.linhas = lin;
            this.colunas = col;
            this.inicio = null;
        }
        public void construir () {

        }
    }
}
