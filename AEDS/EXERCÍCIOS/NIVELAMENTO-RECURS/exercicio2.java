import java.util.Scanner;

public class exercicio2 {
    public static void swap(int[] array, int i, int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    public static void quicksort(int array[], int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[(esq + dir) / 2];
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(array, i, j);
                i++; j--;
            }
        }
        if (esq < j) quicksort(array, esq, j);
        if (i < dir) quicksort(array, i, dir);
    }
    public static void ordenar(int array[], int n) {
        quicksort(array, 0, n - 1);
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int array[] = new int[n]; for (int i = 0; i < n; i++) array[i] = sc.nextInt();
        ordenar(array, n);
        for (int i = 0; i < n; i++) System.out.print(array[i] + " ");
        sc.close();
    }
}
