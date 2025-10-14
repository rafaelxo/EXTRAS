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
        void inserir (int x) {

        }
        void inserirPai (int x) {

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
