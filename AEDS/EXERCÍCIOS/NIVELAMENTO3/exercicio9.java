import java.util.Scanner;

public class exercicio9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n]; for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        for (int i = 0; (2*i+1) < n; i++) System.out.println("Resultado: " + (nums[i] + nums[2*i+1]));
        sc.close();
    }
}
