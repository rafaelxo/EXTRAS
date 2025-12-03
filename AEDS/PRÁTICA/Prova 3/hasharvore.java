import java.util.*;

public class hasharvore {
    public static Scanner sc = new Scanner (System.in);

    static class Carro {
        public String placa, modelo, tipo, chassi;
        void ler (String linha) {
            String[] partes = linha.split(",");
            placa = partes[0];
            modelo = partes[1];
            tipo = partes[2];
            chassi = partes[3];
        }
        void imprimir () {
            System.out.println("[" + placa + "] [" + modelo + "] [" + tipo + "] [" + chassi + "]");
        }
    }

    static class No {
        public Carro elemento;
        public No esq, dir;
        public No (Carro x) {
            elemento = x;
            esq = dir = null;
        }
    }

    static class Arvore {
        No raiz;
        public Arvore() { raiz = null; }

        public void inserir (Carro x, No i) {
            if (i == null) raiz = new No(x);
            else if (x.placa.compareTo(i.elemento.placa) < 0) inserir(x, i.esq);
            else if (x.placa.compareTo(i.elemento.placa) > 0) inserir(x, i.dir);
        }
        public void caminhar (No i) {
            if (i != null) {
                caminhar(i.esq);
                i.elemento.imprimir();
                caminhar(i.dir);
            }
        }
    }

    public static void main (String[] args) {
        Arvore carros = new Arvore();
        String dados = sc.nextLine();
        while (!dados.equals("FIM")) {
            Carro c = new Carro();
            c.ler(dados);
            carros.inserir(c, carros.raiz);
            dados = sc.nextLine();
        }
        carros.caminhar(carros.raiz);
    }
}
