public class lista {
    public class Lista {
        private int[] array;
        private int n;
        public Lista () { this(6); }
        public Lista (int tam) {
            if (tam <= 0) throw new IllegalArgumentException("Erro!");
            array = new int[tam];
            n = 0;
        }
        public void inserirInicio (int num) {
            if (n >= array.length) throw new RuntimeException("Erro");
            for (int i = n; i > 0; i--) array[i] = array[i - 1];
            array[0] = num;
            n++;
        }
        public void inserirFim (int num) {
            if (n >= array.length) throw new RuntimeException("Erro");
            array[n++] = num;
        }
        public void inserir (int num, int pos) {
            if (n >= array.length || pos < 0 || pos > n) throw new RuntimeException("Erro!");
            for (int i = n; i > pos; i--) array[i] = array[i - 1];
            array[pos] = num;
            n++;
        }
        public void inserirOrdenado (int num) {
            if (n >= array.length) throw new RuntimeException("Erro");
            int i = n - 1;
            while (i >= 0 && array[i] > num) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = num;
            n++;
        }
        public int removerInicio () {
            if (n == 0) throw new RuntimeException("Erro!");
            int resp = array[0];
            n--;
            for (int i = 0; i < n; i++) array[i] = array[i + 1];
            return resp;
        }
        public int removerFim () {
            if (n == 0) throw new RuntimeException("Erro!");
            return array[--n];
        }
        public int remover (int pos) {
            if (n == 0 || pos < 0 || pos >= n) throw new RuntimeException("Erro!");
            int resp = array[pos];
            n--;
            for (int i = pos; i < n; i++) array[i] = array[i + 1];
            return resp;
        }
        public boolean vazia () { return n == 0; }
        public int[] impPar () {
            int pares = 0, impares = 0;
            for (int i = 0; i < n; i++) {
                if (array[i] % 2 == 0) pares++;
                else impares++;
            }
            int[] result = new int[2];
            result[0] = pares; result[1] = impares;
            return result;
        }
        public void mostrar () {
            System.out.print("[ ");
            for (int i = 0; i < n; i++) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public void mostrarRec (int i) {
            if (i == 0) System.out.print("[ ");
            if (i < n) {
                System.out.print(array[i] + " ");
                mostrarRec(i + 1);
            } else System.out.println("]");
        }
        public void mostrarPares () {
            System.out.print("[ ");
            for (int i = n - 1; i >= 0; i--) {
                if (array[i] % 2 == 0) System.out.print(array[i] + " ");
            }
            System.out.println("]");
        }
        public void mostrarImpares () {
            System.out.print("[ ");
            for (int i = n - 1; i >= 0; i--) {
                if (array[i] % 2 != 0) System.out.print(array[i] + " ");
            }
            System.out.println("]");
        }
    }
}
