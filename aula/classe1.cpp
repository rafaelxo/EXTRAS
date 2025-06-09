#include <iostream>
using namespace std;

class Aluno {
    private:
        string nome;
        int idade;
        float notas[3];
        int dia, mes, ano;
        string logradouro;
        int numero;
        string complemento;
    public:
        Aluno() {
            float val[3] = {0, 0, 0};
            setNome("nenhum");
            setIdade(1);
            setNotas(val);
            setData(1, 1, 2000);
            setEndereco("nenhum", 0, "nenhum");
        }
        Aluno(string nNome, int nIdade, float nNotas[3], int nDia, int nMes, int nAno, string nLogradouro, int nNumero, string nComplemento) {
            setNome(nNome);
            setIdade(nIdade);
            setNotas(nNotas);
            setData(nDia, nMes, nAno);
            setEndereco(nLogradouro, nNumero, nComplemento);
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
        void setEndereco(string log, int num, string comp) {
            if (log.length() > 5) logradouro = log;
            else cout << "ERRO - Logradouro deve ter mais de 5 caracteres!" << endl;
            if (num > 0) numero = num;
            else cout << "ERRO - Numero deve ser positivo!" << endl;
            if (comp.length() > 3) complemento = comp;
            else cout << "ERRO - Complemento deve ter mais de 3 caracteres!" << endl;
        }
        void preenche() {
            string enter, texto, log, comp;
            int valor, diaNasc, mesNasc, anoNasc, num;
            float vet[3];
            cout << "Nome: ";
            getline(cin, texto);
            setNome(texto);
            cout << "Idade: ";
            cin >> valor;
            setIdade(valor);
            cout << "Notas: ";
            for (int i = 0; i < 3; i++) cin >> vet[i];
            setNotas(vet);
            cout << "Dia do nascimento: ";
            cin >> diaNasc;
            cout << "Mes do nascimento: ";
            cin >> mesNasc;
            cout << "Ano do nascimento: ";
            cin >> anoNasc;
            setData(diaNasc, mesNasc, anoNasc);
            getline(cin, enter);
            cout << "Logradouro: ";
            getline(cin, log);
            cout << "Numero: ";
            cin >> num;
            getline(cin, enter);
            cout << "Complemento: ";
            getline(cin, comp);
            setEndereco(log, num, comp);
            getline(cin, enter);
        }
        void exibe() {
            cout << "Nome: " << getNome() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Notas: ";
            for (int i = 0; i < 3; i++) cout << getNotas()[i] << " ";
            cout << endl;
            cout << "Data de nascimento: " << getData() << endl;
            cout << "Endereco: " << getEndereco() << endl;
        }
        string getNome() { return nome; }
        int getIdade() { return idade; }
        float *getNotas() { return notas; }
        int getDia() { return dia; }
        string getMes() {
            switch (mes) {
                case 1:
                    return string("Janeiro");
                case 2:
                    return string("Fevereiro");
                case 3:
                    return string("Marco");
                case 4:
                    return string("Abril");
                case 5:
                    return string("Maio");
                case 6:
                    return string("Junho");
                case 7:
                    return string("Julho");
                case 8:
                    return string("Agosto");
                case 9:
                    return string("Setembro");
                case 10:
                    return string("Outubro");
                case 11:
                    return string("Novembro");
                case 12:
                    return string("Dezembro");
                default:
                    return string("Mes invalido!");
            }
        }
        int getAno() { return ano; }
        string getData() {
            string texto = to_string(getDia()) + " de " + getMes() + " de " + to_string(getAno());
            return texto;
        }
        string getEndereco() { return logradouro + ", " + to_string(numero) + " - " + complemento;}
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
    float idades, notas;
    for (int i = 0; i < 3; i++) turma[i] = Aluno("nome", 30, vet, 1, 1, 2000, "logradouro", 0, "complemento");
    preencheTurma(turma);
    exibeTurma(turma);
    idades = mediaIdades(turma);
    notas = mediaNotas(turma);
    cout << "A media das idades e " << idades << " anos!" << endl;
    cout << "A media das notas e " << notas << " pontos!" << endl;
}