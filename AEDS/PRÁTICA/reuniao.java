import java.util.*; // biblioteca para scanner

public class reuniao { // main do programa
    public static Scanner sc = new Scanner (System.in); // atribuicao do scanner para leitura
    public static void main (String[] args) {
        int N = sc.nextInt(); int K = sc.nextInt(); // leitura do numero de diretores e do tempo total da reuniao
        int T = (K - (N - 1)) / N; // formula usada para calcular o tempo de fala de cada diretor = tempo total de reuniao menos a quantidade de diretores menos 1 (devido ao intervalo do tempo de fala), tudo isso sobre a quantidade de diretores para se obter a media de tempo
        if (T < 1) T = 1; // se o tempo calculado for menor que 1 minuto, concede ao menos 1 minuto como tempo de fala a cada diretor
        System.out.println(T); // imprime quantos minutos de fala cada diretor tem direito
    }
}