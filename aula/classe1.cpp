#include <iostream>
using namespace std;

class Endereco {
    private:
        string logradouro;
        int numero;
        string complemento;
    public:
        Endereco() {
            setLogradouro("rua");
            setNumero(0);
            setComplemento("nenhum");
        }
        Endereco(string nLogradouro, int nNumero, string nComplemento) {
            setLogradouro(nLogradouro);
            setNumero(nNumero);
            setComplemento(nComplemento);
        }
        void setLogradouro(string log) {
            if(log.length() > 5) logradouro = log;
            else cout << "ERRO - Logradouro deve ter mais de 5 caracteres!" << endl;
        }
        void setNumero(int num) {
            if (num > 0) numero = num;
            else cout << "ERRO - Numero deve ser positivo!" << endl;
        }
        void setComplemento(string comp) {
            if (comp.length() > 3) complemento = comp;
            else cout << "ERRO - Complemento deve ter mais de 3 caracteres!" << endl;
        }
        string getLogradouro() { return logradouro; }
        int getNumero() { return numero; }
        string getComplemento() { return complemento; }
        string getEndereco () { 
            string texto = getLogradouro() + ", " + to_string(getNumero()) + "\n" + getComplemento();
            return texto;
        }
};

class Data {
    private:
        int dia, mes, ano;
    public:
        Data () { setData(1, 1, 2000); }
        Data(int d, int m, int a) { setData(d, m, a); }
        void setData(int d, int m, int a) {
            switch (m) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                    if (d >= 1 && d <= 31) dia = d;
                break;
                case 2:
                    if (d >= 1 && d <= 28) dia = d;
                break;
                case 4: case 6: case 9: case 11:
                    if (d >= 1 && d <= 30) dia = d;
                break;
                default:
                    cout << "Mes invalido" << endl;
                break;
            }
            if (m >= 1 && m <= 12) mes = m;
            else cout << "ERRO - Mes inexistente!" << endl;
            if (a > 1910 && a <= 2025) ano = a;
            else cout << "ERRO - Ano improvavel!" << endl;
        }
        int getDia() { return dia; }
        string getMes() {
            switch (mes) {
                case 1: return string("Janeiro");
                case 2: return string("Fevereiro");
                case 3: return string("Marco");
                case 4: return string("Abril");
                case 5: return string("Maio");
                case 6: return string("Junho");
                case 7: return string("Julho");
                case 8: return string("Agosto");
                case 9: return string("Setembro");
                case 10: return string("Outubro");
                case 11: return string("Novembro");
                case 12: return string("Dezembro");
                default: return string("Mes invalido!");
            }
        }
        int getAno() { return ano; }
        string getData() {
            string texto = to_string(getDia()) + " de " + getMes() + " de " + to_string(getAno());
            return texto;
        }
};

class Aluno {
    private:
        string nome;
        int idade;
        float notas[3];
        Data nasc;
        Endereco ende;
    public:
        Aluno() {
            float val[3] = {0, 0, 0};
            setNome("nenhum");
            setIdade(1);
            setNotas(val);
        }
        Aluno(string nNome, int nIdade, float nNotas[3], int nDia, int nMes, int nAno, string nLog, int nNum, string nComp) {
            setNome(nNome);
            setIdade(nIdade);
            setNotas(nNotas);
            nasc.setData(nDia, nMes, nAno);
            ende.setLogradouro(nLog);
            ende.setNumero(nNum);
            ende.setComplemento(nComp);
        }
        void setNome(string texto) {
            if (texto.length() > 2) nome = texto;
            else cout << "ERRO - Nome com menos de 2 caracteres!" << endl;
        }
        void setIdade(int numero) {
            if (numero > 0) idade = numero;
            else cout << "ERRO - Idade nula ou negativa!" << endl;
        }
        void setNotas(float vet[3]) {
            for (int i = 0; i < 3; i++) {
                if (vet[i] >= 0) notas[i] = vet[i];
                else cout << "ERRO - Nota negativa para prova " << (i + 1) << "!" << endl;
            }
        }
        void preenche() {
            string enter, texto, log, comp;
            int valor, diaN, mesN, anoN, num;
            float val[3];
            cout << "Nome: ";
            getline(cin, texto);
            setNome(texto);
            cout << "Idade: ";
            cin >> valor;
            setIdade(valor);
            cout << "Notas: ";
            for (int i = 0; i < 3; i++) cin >> val[i];
            setNotas(val);
            cout << "Data do nascimento (dd mm aaaa): ";
            cin >> diaN >> mesN >> anoN;
            nasc.setData(diaN, mesN, anoN);
            getline(cin, enter);
            cout << "Logradouro: ";
            getline(cin, log);
            ende.setLogradouro(log);
            cout << "Numero: ";
            cin >> num;
            ende.setNumero(num);
            getline(cin, enter);
            cout << "Complemento: ";
            getline(cin, comp);
            ende.setComplemento(comp);
        }
        void exibe() {
            cout << "Nome: " << getNome() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Notas: ";
            for (int i = 0; i < 3; i++) cout << getNotas()[i] << " ";
            cout << endl;
            cout << "Data de nascimento: " << nasc.getData() << endl;
            cout << "Endereco: " << ende.getEndereco() << endl;
        }
        string getNome() { return nome; }
        int getIdade() { return idade; }
        float *getNotas() { return notas; }
};


class AlunoGrad : public Aluno {
    private:
        string TCC;
    public:
        AlunoGrad() { setTCC("nada"); }
        AlunoGrad(string texto) { setTCC(texto); }
        AlunoGrad(string nomeAluno, int idadeAluno, float notasAluno[3], int diaNasc, int mesNasc, int anoNasc, string logEnd, int numEnd, string compEnd, string tcc) 
            : Aluno(nomeAluno, idadeAluno, notasAluno, diaNasc, mesNasc, anoNasc, logEnd, numEnd, compEnd) {
            setTCC(tcc);
        }
        void setTCC(string texto) {
            if (texto.length() > 10) TCC = texto;
            else cout << "ERRO - TCC deve ter mais de 10 caracteres!" << endl;
        }
        string getTCC() { return TCC; }
        void preenche() {
            string texto;
            Aluno::preenche();
            cout << "TCC: ";
            getline(cin, texto);
            setTCC(texto);
        }
        void exibe() {
            Aluno::exibe();
            cout << "TCC: " << getTCC() << endl;
        }
};

class AlunoMestr : public Aluno {
    private:
        string artigo;
    public:
        AlunoMestr() { setArtigo("nada"); }
        AlunoMestr(string texto) { setArtigo(texto); }
        AlunoMestr(string nomeAluno, int idadeAluno, float notasAluno[3], int diaNasc, int mesNasc, int anoNasc, string logEnd, int numEnd, string compEnd, string Artigo) 
            : Aluno(nomeAluno, idadeAluno, notasAluno, diaNasc, mesNasc, anoNasc, logEnd, numEnd, compEnd) {
            setArtigo(Artigo);
        }
        void setArtigo(string texto) {
            if (texto.length() > 10) artigo = texto;
            else cout << "ERRO - Artigo deve ter mais de 10 caracteres!" << endl;
        }
        string getArtigo() { return artigo; }
        void preenche() {
            string texto;
            Aluno::preenche();
            cout << "Artigo: ";
            getline(cin, texto);
            setArtigo(texto);
        }
        void exibe() {
            Aluno::exibe();
            cout << "Artigo: " << getArtigo() << endl;
        }
};

void preencheTurma(Aluno turma[3]) {
    cout << endl << "Preenche dados dos alunos" << endl;
    for (int pos = 0; pos < 3; pos++) {
        cout << "Aluno " << (pos + 1) << endl;
        turma[pos].preenche();
        cout << endl;
    }
}

void exibeTurma(Aluno turma[3]) {
    cout << endl << "Exibe dados dos alunos" << endl;
    for (int pos = 0; pos < 3; pos++) {
        cout << "Aluno " << (pos + 1) << endl;
        turma[pos].exibe();
        cout << endl;
    }
}

float mediaIdades(Aluno turma[3]) {
    float soma = 0;
    for (int i = 0; i < 3; i++) soma += turma[i].getIdade();
    return soma / 3;
}

float mediaNotas(Aluno turma[3]) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) soma += turma[i].getNotas()[j];
    }
    return soma / (3*3);
}

int main() {
    Aluno turma[3];
    float vet[3] = {0, 0, 0};
    AlunoGrad individual ("Jorge", 20, vet, 3, 5, 2015, "Rua Claudio", 1100, "Sala 200", "Titulo do TCC");
    individual.exibe();
    cout << endl;
    AlunoMestr solo ("Mateus", 28, vet, 9, 5, 1997, "Rua Alagoas", 750, "Sala 8", "Artigo");
    solo.exibe();
    cout << endl;
    float idades, notas;
    for (int i = 0; i < 3; i++) turma[i] = Aluno("nome", 30, vet, 1, 1, 2000, "logradouro", 1, "complemento");
    preencheTurma(turma);
    exibeTurma(turma);
    idades = mediaIdades(turma);
    notas = mediaNotas(turma);
    cout << "A media das idades e " << idades << " anos!" << endl;
    cout << "A media das notas e " << notas << " pontos!" << endl;
}