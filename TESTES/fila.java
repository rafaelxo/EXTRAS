public class fila {
    public class Fila {
        private int[] array;
        private int primeiro, ultimo;
        public Fila () { this(6); }
        public Fila (int tam) {
            array = new int[tam + 1];
            primeiro = ultimo = 0;
        }
        public void inserir (int num) {
            if ((ultimo + 1) % array.length == primeiro) throw new RuntimeException("Erro");
            array[ultimo] = num;
            ultimo = (ultimo + 1) % array.length;
        }
        public void inserirPar (int num) {
            if ((ultimo + 1) % array.length == primeiro) throw new RuntimeException("Erro");
            if (num % 2 == 0) {
                array[ultimo] = num;
                ultimo = (ultimo + 1) % array.length;
            } else throw new RuntimeException("Impar!");
        }
        public int remover ()  {
            if (primeiro == ultimo) throw new RuntimeException ("Erro");
            int resp = array[primeiro];
            primeiro = (primeiro + 1) % array.length;
            return resp;
        }
        public boolean vazia () { return primeiro == ultimo; }
        public void mostrar () {
            System.out.println("[ ");
            for (int i = primeiro; i != ultimo; i += 1 % array.length) System.out.print(array[i] + " ");
            System.out.print("]");
        }
        public void mostrarRec (int i) {
            if (i == primeiro) System.out.println("[ ");
            if (i != ultimo) {
                System.out.print(array[i] + " ");
                mostrarRec((i + 1) % array.length);
            }
            if (i == primeiro) System.out.print("]");
        }
        public void mostrarInvertido () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            else {
                System.out.println("[");
                int quant = (ultimo - primeiro + array.length) % array.length;
                for (int i = quant - 1; i >= 0; i--) {
                    int j = (primeiro + i) % array.length;
                    System.out.print(array[j] + " ");
                }
                System.out.print("]");
            }
        }
    }
}
