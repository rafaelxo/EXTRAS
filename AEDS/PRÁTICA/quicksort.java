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

    public static void QuickSortFirstPivot (int[] vet, int left, int right) {

    }

    public static void QuickSortLastPivot (int[] vet, int left, int right) {

    }

    public static void QuickSortRandomPivot (int[] vet, int left, int right) {

    }

    public static void QuickSortMedianofThree (int[] vet, int left, int right) {

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

        QuickSortLastPivot(dez, 0, dez.length - 1); QuickSortLastPivot(cem, 0, cem.length - 1); QuickSortLastPivot(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil); */

        /* System.out.println("QUICKSORT COM PIVO DE MEDIANA DE TRES:");

        gerarArray(dez, 10); gerarArray(cem, 100); gerarArray(mil, 1000);

        imprimirArray("Array com 10 inteiros desordenado:", dez);
        imprimirArray("Array com 100 inteiros desordenado:", cem);
        imprimirArray("Array com 1000 inteiros desordenado:", mil);

        QuickSortMedianofThree(dez, 0, dez.length - 1); QuickSortMedianofThree(cem, 0, cem.length - 1); QuickSortMedianofThree(mil, 0, mil.length - 1);

        imprimirArray("Array com 10 inteiros ordenado:", dez);
        imprimirArray("Array com 100 inteiros ordenado:", cem);
        imprimirArray("Array com 1000 inteiros ordenado:", mil); */
    }
}
