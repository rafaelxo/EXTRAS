import java.util.*;

public class heapsort {
    public static Scanner sc = new Scanner (System.in);
    public static class Pedido {
        private int id;
        private int prioridade;
        private double valor;
        public Pedido(int id, int prioridade, double valor) {
            this.id = id;
            this.prioridade = prioridade;
            this.valor = valor;
        }
        public int getId() { return id; }
        public int getPrioridade() { return prioridade; }
        public double getValor() { return valor; }
        public String toString() {
            return "ID: " + id + ", Prioridade: " + prioridade + ", Valor: " + valor;
        }
    }

    public static void swap (Pedido vet[], int i, int j) {
        Pedido aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }

    public static boolean compara (Pedido a, Pedido b) {
        if (a.getPrioridade() != b.getPrioridade()) return a.getPrioridade() < b.getPrioridade();
        if (a.getValor() != b.getValor()) return a.getValor() > b.getValor();
        return a.getId() < b.getId();
    }

    public static void heapify (Pedido[] arr, int n, int i) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        if (esq < n && compara(arr[esq], arr[maior])) maior = esq;
        if (dir < n && compara(arr[dir], arr[maior])) maior = dir;
        if (maior != i) {
            swap(arr, i, maior);
            heapify(arr, n, maior);
        }
    }

    public static void heapSort (Pedido[] arr) {
        int tam = arr.length;
        for (int i = tam / 2 - 1; i >= 0; i--) heapify(arr, tam, i);
        for (int i = tam - 1; i > 0; i--) {
            swap(arr, 0, i);
            heapify(arr, i, 0);
        }
    }

    public static void main (String[] args) {
        int n = sc.nextInt();
        Pedido[] ped = new Pedido[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int prioridade = sc.nextInt();
            double valor = sc.nextDouble();
            ped[i] = new Pedido(id, prioridade, valor);
        }
        heapSort(ped);
        for (int i = 0; i < n; i++) System.out.println(ped[i].toString());
    }
}
