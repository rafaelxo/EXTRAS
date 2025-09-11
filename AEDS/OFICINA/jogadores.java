import java.util.*;

public class jogadores {
    public static Scanner sc = new Scanner (System.in);

    static class Jogador {
        private String nome;
        private int gols;
        private int assistencias;
        private int partidas;
        Jogador() {
            this.nome = "nenhum";
            this.gols = 0;
            this.assistencias = 0;
            this.partidas = 0;
        }
        Jogador(String str, int g, int a, int p) {
            setNome(str);
            setGols(g);
            setAssistencias(a);
            setPartidas(p);
        }
        public String getNome() { return nome; }
        public void setNome (String str) { this.nome = str; }
        public int getGols() { return gols; }
        public void setGols (int g) { this.gols = g; }
        public int getAssitencias() { return assistencias; }
        public void setAssistencias (int a) { this.assistencias = a; }
        public int getPartidas() { return partidas; }
        public void setPartidas(int p) { this.partidas = p; }
        public double getMedia() { return (getGols() + getAssitencias()) / (partidas * 1.0); }
    }

    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static int comparaNomes (String a, String b) {
        int tam = (a.length() < b.length()) ? a.length() : b.length();
        for (int i = 0; i < tam; i++) {
            if (a.charAt(i) < b.charAt(i)) return -1;
            if (a.charAt(i) > b.charAt(i)) return 1;
        }
        if (a.length() < b.length()) return -1;
        if (a.length() > b.length()) return 1;
        return 0;
    }

    public static void swap (Jogador[] jog, int i, int j) {
        Jogador aux = jog[i];
        jog[i] = jog[j];
        jog[j] = aux;
    }

    public static void selecao (Jogador[] jog, int n) {
        for (int i = 0; i < n - 1; i++) {
            int melhor = i;
            for (int j = i + 1; j < n; j++) {
                if (jog[j].getMedia() > jog[melhor].getMedia()) melhor = j;
                else if (jog[j].getMedia() == jog[melhor].getMedia()) {
                    if (jog[j].getGols() > jog[melhor].getGols()) melhor = j;
                    else if (jog[j].getGols() == jog[melhor].getGols()) {
                        if (comparaNomes(jog[j].getNome(), jog[melhor].getNome()) < 0) melhor = j;
                    }
                }
            }
            swap(jog, i, melhor);
        }
    }

    public static void main (String[] args) {
        int n = sc.nextInt();
        Jogador[] jog = new Jogador[n];
        for (int i = 0; i < n; i++) {
            String nome; int gols = 0; int assistencias = 0; int partidas = 0;
            nome = sc.next();
            while (sc.hasNextInt() && !isFim(nome)) {
                gols += sc.nextInt();
                assistencias += sc.nextInt();
                partidas++;
            }
            jog[i] = new Jogador(nome, gols, assistencias, partidas);
        }
        selecao(jog, n);
        System.out.println("Ranking de jogadores:");
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + ". " + jog[i].getNome() + " - Média: " + jog[i].getMedia() + " - Gols: " + jog[i].getGols());
        }
    }
}
