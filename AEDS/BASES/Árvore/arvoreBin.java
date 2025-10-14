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

        public void inserir (int x) {
            raiz = inserir (x, raiz);
        }
        private No inserir (int x, No i) {
            if (i == null) i = new No(x);
            else if (x < i.elemento) i.esq = inserir(x, i.esq);
            else if (x > i.elemento) i.dir = inserir(x, i.dir);
            else throw new RuntimeException ("Erro!");
            return i;
        }

        public void inserirPai (int x) {
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

        public boolean pesquisar (int x) {
            return pesquisar(x, raiz);
        }
        private boolean pesquisar (int x, No i) {
            boolean resp;
            if (i == null) resp = false;
            else if (x == i.elemento) resp = true;
            else if (x < i.elemento) resp = pesquisar(x, i.esq);
            else resp = pesquisar(x, i.dir);
            return resp;
        }

        public void caminharCentral (No i) {
            if (i != null) {
                caminharCentral(i.esq);
                System.out.print(i.elemento + " ");
                caminharCentral(i.dir);
            }
        }

        public void caminharPre (No i) {
            if (i != null) {
                System.out.print(i.elemento + " ");
                caminharPre(i.esq);
                caminharPre(i.dir);
            }
        }

        public void caminharPos (No i) {
            if (i != null) {
                caminharPos(i.esq);
                caminharPos(i.dir);
                System.out.print(i.elemento + " ");
            }
        }

        public void remover (int x) {

        }

        public int getAltura () {
            int h = 0, j =0;
            for (No i = raiz; i != null; i = i.esq) h++;
            for (No i = raiz; i != null; i = i.dir) j++;
            return (h > j) ? h : j;
        }

        public int getAlturaRec (No i) {
            if (i == null) return -1;
            else {
                int altEsq = getAlturaRec(i.esq);
                int altDir = getAlturaRec(i.dir);
                return (altEsq > altDir) ? altEsq + 1 : altDir + 1;
            }
        }

        public int somar () {
            int soma = 0;
            for (No i = raiz; i != null; i = i.esq) soma += i.elemento;
            for (No i = raiz; i != null; i = i.dir) soma += i.elemento;
            return soma;
        }

        public int somarRec (No i) {
            if (i == null) return 0;
            else return i.elemento + somarRec(i.esq) + somarRec(i.dir);
        }
    }
}
