public class insertion {
    public static void insercao (int array[], int n) {
        for (int i = 1; i < n; i++) {
            int aux = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > aux) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = aux;
        }
    }
}
