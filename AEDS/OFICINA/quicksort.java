import java.util.*;

public class quicksort {
    public static Scanner sc = new Scanner (System.in);

    public static void swap(int vet[], int i, int j) {
        int aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }

    public static int partition (int[] arr, int low, int high) {
        int pivo = arr[(low + high)/2];
        int i = low, j = high;
        while (i <= j) {
            while (arr[i] < pivo) i++;
            while (arr[j] > pivo) j--;
            if (i <= j) {
                swap(arr, i, j);
                i++; j--;
            }
        }
        return i;
    }

    public static void quickSort (int[] arr, int low, int high) {
        if (low < high) {
            int pivo = partition(arr, low, high);
            quickSort(arr, low, pivo - 1);
            quickSort(arr, pivo, high);
        }
    }

    public static void main (String[] args) {
        int n = sc.nextInt();
        int[] vet = new int[n];
        for (int i = 0; i < n; i++) vet[i] = sc.nextInt();
        quickSort(vet, 0, n - 1);
        System.out.print("[ ");
        for (int i = 0; i < n; i++) System.out.print(vet[i] + " ");
        System.out.print("]");
    }
}
