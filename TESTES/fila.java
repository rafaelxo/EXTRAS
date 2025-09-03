public class fila {
    public class Fila {
        private int[] array;
        private int primeiro, ultimo;
        public Fila () { this(6); }
        public Fila (int tam) {
            array = new int[tam + 1];
            primeiro = ultimo = 0;
        }
        public void inserir (int num) throws Exception {
            if ((ultimo + 1) % array.length == primeiro) throw new Exception ("Erro");
            array[ultimo] = num;
            ultimo = (ultimo + 1) % array.length;
        }
        public int remover () throws Exception {
            if (primeiro == ultimo) throw new Exception ("Erro");
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
    }
    public static void main (String[] args) {
        Fila f = new fila().new Fila(6);
        try {
            f.inserir(1);
            f.inserir(3);
            f.inserir(5);
            f.inserir(7);
            f.inserir(9);
            f.inserir(2);
            f.mostrarRec(f.primeiro);
            System.out.println("Removido: " + f.remover());
            System.out.println("Removido: " + f.remover());
            f.inserir(4);
            f.inserir(6);
            f.mostrarRec(f.primeiro);
            System.out.println("Removido: " + f.remover());
            f.inserir(8);
            f.mostrarRec(f.primeiro);
        } catch (Exception e) { System.out.println(e.getMessage()); }
    }
}
