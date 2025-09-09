public class pilha {
    public class Pilha {
        public int[] array;
        public int n;
        public Pilha () { this(6); }
        public Pilha (int tam) {
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
        public int[] contador() {
            int pares = 0, impares = 0;
            for (int i = 0; i < n; i++) {
                if (array[i] % 2 == 0) pares++;
                else impares++;
            }
            int[] array = new int[2];
            array[0] = pares; array[1] = impares;
            return array;
        }
        public void mostrar() {
            System.out.print("[ ");
            for (int i = 0; i < n; i++) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public void mostrarRec(int i) {
            if (i == 0) System.out.println("[");
            if (i < n) {
                System.out.print(array[i] + " ");
                mostrarRec(i + 1);
            } else System.out.print("]");
        }
        public void mostrarPares () {
            System.out.println("[ ");
            for (int i = n - 1; i >= 0; i--) if (array[i] % 2 == 0) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public void mostrarImpares () {
            System.out.println("[ ");
            for (int i = n - 1; i >= 0; i--) if (array[i] % 2 != 0) System.out.print(array[i] + " ");
            System.out.println("]");
        }
    }
}
