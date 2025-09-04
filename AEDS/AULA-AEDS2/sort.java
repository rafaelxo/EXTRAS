import java.util.*;

public class sort {
    public static Scanner sc = new Scanner (System.in);
    public static void swap (int[] v, int i, int j) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    public static void selecao (int[] v) {
        for (int i = 0; i < v.length - 1; i++) {
            int menor = i;
            for (int j = i + 1; j < v.length; j++) {
                if (v[j] < v[menor]) menor = j;
            }
            swap(v, i, menor);
        }
    }
    public static void esquematizacao (int[] v, int n, int m) {
        for (int mod = -m + 1; mod < m; mod++) {
            for (int i = n - 1; i >= 0; i--) {
                if (v[i] % m == mod && v[i] % 2 != 0) System.out.println(v[i]);
            }
            for (int i = 0; i < n; i++) {
                if (v[i] % m == mod && v[i] % 2 == 0) System.out.println(v[i]);
            }
        }
    }
    public static void main (String[] args) {
        int n = sc.nextInt(); int m = sc.nextInt();
        while (n != 0 && m != 0) {
            System.out.println(n + " " + m);
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
            selecao(nums); esquematizacao(nums, n, m);
            n = sc.nextInt(); m = sc.nextInt();
        }
        System.out.println(n + " " + m);
    }
}
