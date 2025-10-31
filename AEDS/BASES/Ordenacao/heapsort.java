public class heapsort {
    public static void swap (int array[], int i, int j) {
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }
    public static void construir (int array[], int tam) {
        for (int i = tam; i > 1 && array[i] > array[i / 2]; i /= 2) swap(array, i, i / 2);
    }
    public static void reconstruir (int array[], int tam) {
        int i = 1;
        while (i <= tam / 2) {
            int filho = 2 * i;
            if (filho < tam && array[filho] < array[filho + 1]) filho++;
            if (array[i] < array[filho]) {
                swap(array, i, filho);
                i = filho;
            } else i = tam;
        }
    }

    public static void heap (int[] array, int n) {
        int[] tmp = new int[n + 1];
        for (int i = 0; i < n; i++) tmp[i + 1] = array[i];
        for (int tam = 2; tam <= n; tam++) construir(tmp, tam);
        int tam = n;
        while (tam > 1) {
            swap(tmp, 1, tam--);
            reconstruir(tmp, tam);
        }
        for (int i = 0; i < n; i++) array[i] = tmp[i + 1];
    }
}
