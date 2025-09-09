public class pilha {
    public class Pilha {
        private int[] array;
        private int n;
        public Pilha () { this(6); }
        public Pilha (int tam) {
            if (tam <= 0) throw new IllegalArgumentException("Erro!");
            array = new int[tam];
            n = 0;
        }
        public void inserir (int num) {
            if (n >= array.length) throw new RuntimeException("Array cheio!");
            array[n++] = num;
        }
        public int remover () {
            if (n == 0) throw new RuntimeException("Array vazio!");
            return array[--n];
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

        public void mostrarRec(int i) {
            if (i == n - 1) System.out.print("[ ");
            if (i >= 0) {
                System.out.print(array[i] + " ");
                mostrarRec(i - 1);
            } else System.out.println("]");
        }
        public void mostrarPares () {
            System.out.print("[ ");
            for (int i = n - 1; i >= 0; i--) if (array[i] % 2 == 0) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public void mostrarImpares () {
            System.out.print("[ ");
            for (int i = n - 1; i >= 0; i--) if (array[i] % 2 != 0) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public int topo () {
            if (n == 0) throw new RuntimeException("Erro!");
            return array[n - 1];
        }
    }
}
