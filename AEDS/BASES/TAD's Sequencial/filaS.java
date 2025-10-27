public class filaS {
    public class Fila {
        private int[] array;
        private int primeiro, ultimo;
        public Fila (int tam) {
            if (tam <= 0) throw new RuntimeException("Erro!");
            array = new int[tam + 1];
            primeiro = ultimo = 0;
        }

        public void inserir (int num) {
            if ((ultimo + 1) % array.length == primeiro) throw new RuntimeException("Erro!");
            array[ultimo] = num;
            ultimo = (ultimo + 1) % array.length;
        }

        public void inserirOrdenado (int num) {
            if ((ultimo + 1) % array.length == primeiro) throw new RuntimeException("Erro!");
            int i = (ultimo - 1 + array.length) % array.length;
            while (i != primeiro && array[i] > num) {
                array[(i + 1) % array.length] = array[i];
                i = (i - 1 + array.length) % array.length;
            }
            if (i == primeiro && array[i] > num) {
                array[(i + 1) % array.length] = array[i];
                array[i] = num;
            } else array[(i + 1) % array.length] = num;
            ultimo = (ultimo + 1) % array.length;
        }

        public void ordenar () {
            int quant = (ultimo - primeiro + array.length) % array.length;
            for (int i = 1; i < quant; i++) {
                int aux = array[(primeiro + i) % array.length];
                int j = i - 1;
                while (j >= 0 && array[(primeiro + j) % array.length] > aux) {
                    array[(primeiro + j + 1) % array.length] = array[(primeiro + j)];
                    j--;
                }
                array[(primeiro + j + 1) % array.length] = aux;
            }
        }

        public int remover ()  {
            if (primeiro == ultimo) throw new RuntimeException ("Erro!");
            int resp = array[primeiro];
            primeiro = (primeiro + 1) % array.length;
            return resp;
        }

        public boolean vazia () { return primeiro == ultimo; }

        public void mostrar () {
            System.out.print("[ ");
            for (int i = primeiro; i != ultimo; i = (i + 1) % array.length) System.out.print(array[i] + " ");
            System.out.println("]");
        }

        public void mostrarRec (int i) {
            if (i == primeiro) System.out.print("[ ");
            if (i != ultimo) {
                System.out.print(array[i] + " ");
                mostrarRec((i + 1) % array.length);
            } else System.out.println("]");
        }

        public int tamanho () {
            if (ultimo >= primeiro) return ultimo - primeiro;
            else return ultimo - primeiro + array.length;
        }

        public void mostrarInvertido () {
            if (primeiro == ultimo) throw new RuntimeException("Erro!");
            System.out.print("[ ");
            int quant = tamanho() % array.length;
            for (int i = quant - 1; i >= 0; i--) {
                int j = (primeiro + i) % array.length;
                System.out.print(array[j] + " ");
            }
            System.out.println("]");
        }
    }
}
