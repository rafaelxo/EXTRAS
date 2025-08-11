import java.util.Scanner;

public class exercicio10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n]; for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        int maior = nums[0]; int menor = nums[0];
        int i = 0;
        while (i < n) {
            if (nums[i] > maior) maior = nums[i];
            if (nums[i] < menor) menor = nums[i];
            i++;
        }
        System.out.println("Menor: " + menor);
        System.out.println("Maior: " + maior);
        sc.close();
    }
}
