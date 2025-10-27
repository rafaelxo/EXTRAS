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
        private Celula primeiro, ultimo;
        public Fila () {
            primeiro = new Celula(0);
            ultimo = primeiro;
        }

        public void inserir (int x) {
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        public int remover () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            Celula tmp = primeiro.prox;
            int resp = tmp.elemento;
            primeiro.prox = tmp.prox;
            if (primeiro.prox == null) ultimo = primeiro;
            tmp = tmp.prox = null;
            return resp;
        }

        public void mostrar () {
            System.out.print("[ ");
            for (Celula i = primeiro.prox; i != null; i = i.prox) System.out.print(i.elemento + " ");
            System.out.println("]");
        }

        public int somar () {
            int soma = 0;
            for (Celula i = primeiro.prox; i != null; i = i.prox) soma += i.elemento;
            return soma;
        }
        public int somarRec (Celula i) {
            if (i == null) return 0;
            else return i.elemento + somarRec(i.prox);
        }

        public int maior () {
            int maior = primeiro.prox.elemento;
            for (Celula i = primeiro.prox.prox; i != null; i = i.prox) {
                if (i.elemento > maior) maior = i.elemento;
            }
            return maior;
        }
    }
}
