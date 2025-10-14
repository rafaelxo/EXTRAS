public class arvoreBin {
    public class No {
        private int elemento;
        private No esq, dir;
        public No (int x) {
            this.elemento = x;
            this.esq = this.dir = null;
        }
        public No (int x, No esq, No dir) {
            this.elemento = x;
            this.esq = esq;
            this.dir = dir;
        }
    }

    public class Arvore {
        private No raiz;
        public Arvore () {
            this.raiz = null;
        }
        void inserir (int x) { raiz = inserir (x, raiz); }
        private No inserir (int x, No i) {
            if (i == null) i = new No(x);
            else if (x < i.elemento) i.esq = inserir(x, i.esq);
            else if (x > i.elemento) i.dir = inserir(x, i.dir);
            else throw new RuntimeException ("Erro!");
            return i;
        }
        void inserirPai (int x) {
            if (raiz == null) raiz = new No (x);
            else if (x < raiz.elemento) raiz.esq = inserir(x, raiz.esq);
            else if (x > raiz.elemento) raiz.dir = inserir(x, raiz.dir);
            else throw new RuntimeException ("Erro!");
        }
        private void inserirPai (int x, No i, No pai) {
            if (i == null) {
                if (x < pai.elemento) pai.esq = new No (x);
                else pai.dir = new No (x);
            }
            else if (x < i.elemento) inserirPai(x, i.esq, i);
            else if (x > i.elemento) inserirPai(x, i.dir, i);
            else throw new RuntimeException ("Erro!");
        }
        boolean pesquisar (int x) {

        }
        void caminharCentral () {

        }
        void caminharPre () {

        }
        void caminharPos () {

        }
        void remover (int x) {

        }
    }
}
