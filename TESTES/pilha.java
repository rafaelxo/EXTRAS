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
        public void mostrar () {
            System.out.println("[");
            for (int i = n - 1; i >= 0; i--) System.out.print(array[i] + " ");
            System.out.println("]");
        }
        public void mostrarRec (int i) {
            if (n == 0) System.out.println("[");
            else {
                System.out.print(array[i] + " ");
                mostrarRec(i - 1);
            }
            if (i == n - 1) System.out.print("]");
        }
    }
}
