import java.util.Scanner;

public class pesqbin {
    public static void main (String []args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int array[] = new int[n];
        for (int i = 0; i < n; i++) array[i] = sc.nextInt();
        int x = sc.nextInt();
        boolean resp = false;
        int dir = n - 1; int esq = 0; int meio = 0;
        while (esq <= dir) {
            meio = (esq + dir) / 2;
            if (x == array[meio]) {
                resp = true;
                esq = n;
            }
            else if (x > array[meio]) esq = meio + 1;
            else dir = meio - 1;
        }
        if (resp == true) System.out.println("Elemento " + x + " encontrado na posição " + meio + "!");
        sc.close();
    }
}
