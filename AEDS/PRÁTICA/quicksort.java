import java.util.*;

public class quicksort {
    public static Random ger = new Random();

    public static void gerarArray(int[] arr, int limite) {
        for (int i = 0; i < arr.length; i++) arr[i] = ger.nextInt(limite + 1);
    }

    public static void imprimirArray(String titulo, int[] arr) {
        System.out.print(titulo + "\n[ ");
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        System.out.println("]");
    }

    public static void swap (int[] array, int i, int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public static void QuickSortFirstPivot (int[] array, int left, int right) {
        int i = left, j = right;
        int pivo = array[left];
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(array, i, j);
                i++; j--;
            }
        }
        if (left < j) QuickSortFirstPivot(array, left, j);
        if (i < right) QuickSortFirstPivot(array, i, right);
    }

    public static void QuickSortLastPivot (int[] array, int left, int right) {
        int i = left, j = right;
        int pivo = array[right];
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(array, i, j);
                i++; j--;
            }
        }
        if (left < j) QuickSortLastPivot(array, left, j);
        if (i < right) QuickSortLastPivot(array, i, right);
    }

    public static void QuickSortRandomPivot (int[] array, int left, int right) {
        int i = left, j = right;
        int p = left + ger.nextInt(right - left + 1);
        int pivo = array[p];
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(array, i, j);
                i++; j--;
            }
        }
        if (left < j) QuickSortRandomPivot(array, left, j);
        if (i < right) QuickSortRandomPivot(array, i, right);
    }

    public static int MedianOfThree (int[] array, int left, int right) {
        int meio = (left + right) / 2;
        if (array[left] > array[meio]) swap(array, left, meio);
        if (array[left] > array[right]) swap(array, left, right);
        if (array[meio] > array[right]) swap(array, meio, right);
        return array[meio];
    }

    public static void QuickSortMedianOfThree (int[] array, int left, int right) {
        int i = left, j = right;
        int pivo = MedianOfThree(array, left, right);
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(array, i, j);
                i++; j--;
            }
        }
        if (left < j) QuickSortMedianOfThree(array, left, j);
        if (i < right) QuickSortMedianOfThree(array, i, right);
    }

    public static void main (String[] args) {
        int[] dez = new int[10];
        int[] cem = new int[100];
        int[] mil = new int[1000];

        System.out.println("QUICKSORT COM PIVO NO PRIMEIRO ELEMENTO:");

        gerarArray(dez, 10); gerarArray(cem, 100); gerarArray(mil, 1000);

        imprimirArray("Array com 10 inteiros desordenado:", dez);
        imprimirArray("Array com 100 inteiros desordenado:", cem);
        imprimirArray("Array com 1000 inteiros desordenado:", mil);

        QuickSortFirstPivot(dez, 0, dez.length - 1); QuickSortFirstPivot(cem, 0, cem.length - 1); QuickSortFirstPivot(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil);

        /* System.out.println("QUICKSORT COM PIVO NO ULTIMO ELEMENTO:");

        gerarArray(dez, 10); gerarArray(cem, 100); gerarArray(mil, 1000);

        imprimirArray("Array com 10 inteiros desordenado:", dez);
        imprimirArray("Array com 100 inteiros desordenado:", cem);
        imprimirArray("Array com 1000 inteiros desordenado:", mil);

        QuickSortLastPivot(dez, 0, dez.length - 1); QuickSortLastPivot(cem, 0, cem.length - 1); QuickSortLastPivot(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil); */

        /* System.out.println("QUICKSORT COM PIVO ALEATORIO:");

        gerarArray(dez, 10); gerarArray(cem, 100); gerarArray(mil, 1000);

        imprimirArray("Array com 10 inteiros desordenado:", dez);
        imprimirArray("Array com 100 inteiros desordenado:", cem);
        imprimirArray("Array com 1000 inteiros desordenado:", mil);

        QuickSortRandomPivot(dez, 0, dez.length - 1); QuickSortRandomPivot(cem, 0, cem.length - 1); QuickSortRandomPivot(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil); */

        /* System.out.println("QUICKSORT COM PIVO DE MEDIANA DE TRES:");

        gerarArray(dez, 10); gerarArray(cem, 100); gerarArray(mil, 1000);

        imprimirArray("Array com 10 inteiros desordenado:", dez);
        imprimirArray("Array com 100 inteiros desordenado:", cem);
        imprimirArray("Array com 1000 inteiros desordenado:", mil);

        QuickSortMedianOfThree(dez, 0, dez.length - 1); QuickSortMedianOfThree(cem, 0, cem.length - 1); QuickSortMedianOfThree(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil); */
    }
}
