import java.util.*;

public class quicksort {
    public static Random ger = new Random();
    public static void QuickSortFirstPivot (int[] vet, int left, int right) {
        
    }
    public static void QuickSortLastPivot(int[] vet, int left, int right) {

    }
    public static void QuickSortRandomPivot(int[] vet, int left, int right) {

    }
    public static void QuickSortMedianofThree(int[] vet, int left, int right) {

    }
    public static void main (String[] args) {
        int[] dez = new int[10]; for (int i = 0; i < 10; i++) dez[i] = ger.nextInt(11);
        System.out.println("Array com 10 inteiros:");
        System.out.println("[ ");
        for (int i = 0; i < 10; i++) System.out.print(dez[i] + " ");
        System.out.print("]");
        int[] cem = new int[100]; for (int i = 0; i < 100; i++) cem[i] = ger.nextInt(101);
        System.out.println("Array com 100 inteiros:");
        System.out.println("[ "); for (int i = 0; i < 100; i++) System.out.print(cem[i] + " ");
        System.out.print("]");
        int[] mil = new int[1000]; for (int i = 0; i < 1000; i++) mil[i] = ger.nextInt(1001);
        System.out.println("Array com 1000 inteiros:");
        System.out.println("[ "); for (int i = 0; i < 1000; i++) System.out.print(mil[i] + " ");
        System.out.print("]");
        System.out.println("QuickSort com pivo no primeiro elemento:");

        System.out.println("QuickSort com pivo no ultimo elemento:");

        System.out.println("QuickSort com pivo aleatorio:");

        System.out.println("QuickSort com pivo de mediana de tres:");
    }
}
