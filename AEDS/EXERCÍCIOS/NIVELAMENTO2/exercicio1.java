import java.util.Scanner; import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nomeArq = sc.nextLine();
        String frase = sc.nextLine();
        try (FileWriter arq = new FileWriter(nomeArq)) {
            arq.write(frase);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArq))) {
            String fraseLida = br.readLine();
            System.out.println(fraseLida);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArq))) {
            String fraseLida = br.readLine();
            String fraseMaiuscula = fraseLida.toUpperCase();
            System.out.println(fraseMaiuscula);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        String nomeArq2 = sc.nextLine();
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArq));
             BufferedWriter bw = new BufferedWriter(new FileWriter(nomeArq2))) {
            String fraseLida = br.readLine();
            String fraseMaiuscula = fraseLida.toUpperCase();
            bw.write(fraseMaiuscula);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        sc.close();
    }
}
