import java.util.*;

public class quicksort {
    public static Random ger = new Random();
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

        for (int i = 0; i < 10; i++) dez[i] = ger.nextInt(11);
        System.out.println("Array com 10 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 100; i++) cem[i] = ger.nextInt(101);
        System.out.println("Array com 100 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 1000; i++) mil[i] = ger.nextInt(1001);
        System.out.println("Array com 1000 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");

        QuickSortFirstPivot(dez, 0, dez.length); QuickSortFirstPivot(cem, 0, cem.length); QuickSortFirstPivot(mil, 0, mil.length);

        System.out.println("Array com 10 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        System.out.println("Array com 100 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        System.out.println("Array com 1000 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");

        /* System.out.println("QUICKSORT COM PIVO NO ULTIMO ELEMENTO:");

        System.out.println("Array com 10 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        System.out.println("Array com 100 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        System.out.println("Array com 1000 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");

        QuickSortLastPivot(dez, 0, dez.length); QuickSortLastPivot(cem, 0, cem.length); QuickSortLastPivot(mil, 0, mil.length);

        System.out.println("Array com 10 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        System.out.println("Array com 100 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        System.out.println("Array com 1000 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]"); */

        /* System.out.println("QUICKSORT COM PIVO ALEATORIO:");

        for (int i = 0; i < 10; i++) dez[i] = ger.nextInt(11);
        System.out.println("Array com 10 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 100; i++) cem[i] = ger.nextInt(101);
        System.out.println("Array com 100 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 1000; i++) mil[i] = ger.nextInt(1001);
        System.out.println("Array com 1000 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");

        QuickSortLastPivot(dez, 0, dez.length); QuickSortLastPivot(cem, 0, cem.length); QuickSortLastPivot(mil, 0, mil.length);

        System.out.println("Array com 10 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        System.out.println("Array com 100 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        System.out.println("Array com 1000 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]"); */

        /* System.out.println("QUICKSORT COM PIVO DE MEDIANA DE TRES:");

        for (int i = 0; i < 10; i++) dez[i] = ger.nextInt(11);
        System.out.println("Array com 10 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 100; i++) cem[i] = ger.nextInt(101);
        System.out.println("Array com 100 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        for (int i = 0; i < 1000; i++) mil[i] = ger.nextInt(1001);
        System.out.println("Array com 1000 inteiros desordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");

        QuickSortMedianofThree(dez, 0, dez.length); QuickSortMedianofThree(cem, 0, cem.length); QuickSortMedianofThree(mil, 0, mil.length);

        System.out.println("Array com 10 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");

        System.out.println("Array com 100 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");

        System.out.println("Array com 1000 inteiros ordenado:");
        System.out.println("[ ");
        for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]"); */
    }
}
