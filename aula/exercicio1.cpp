#include <iostream>
using namespace std;

class Aluno {
    private:
        string nome;
        int idade;
        float notas[3];
        int dia, mes, ano;
    public:
        Aluno() {
            float vet[] = {0, 0, 0};
            setNome("nenhum");
            setIdade(1);
            setNotas(vet);
        }
        Aluno(string nNome, int nIdade, float nNotas[3]) {
            setNome(nNome);
            setIdade(nIdade);
            setNotas(nNotas);
        }
        void setNome(string novo) {
            if (novo.length() > 2) nome = novo;
            else cout << "ERRO - Nome com menos de 3 caracteres" << endl;
        }
        void setIdade(int numero) {
            if (numero > 0) idade = numero;
            else cout << "ERRO - Idade nula ou negativa" << endl;
        }
        void setNotas(float valores[3]) {
            for (int i = 0; i < 3; i++) {
                if (valores[i] >= 0) notas[i] = valores[i];
                else cout << "ERRO - Nota negativa para prova " << (i + 1) << endl;
            }
        }
        void setData(int d, int m, int a) {
            setDia(d, m);
            setMes(m);
            setAno(a);
        }
        void preenche() {
            string enter, texto;
            int valor, diaNasc, mesNasc, anoNasc;
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
        }
        void exibe() {
            cout << "Nome: " << getNome() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Notas: ";
            for (int i = 0; i < 3; i++) cout << getNotas()[i] << " ";
            cout << endl;
            cout << "Data de nascimento: " << getData() << endl;
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
                    return string("Mes invalido");
            }
        }
        int getAno() { return ano; }
        string getData() {
            string texto = to_string(getDia()) + " de " + getMes() + " de " + to_string(getAno());
            return texto;
        }
    private:
        void setDia(int valDia, int valMes) {
            switch (valMes) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                    if (valDia >= 1 && valDia <= 31) dia = valDia;
                break;
                case 2:
                    if (valDia >= 1 && valDia <= 28) dia = valDia;
                break;
                case 4: case 6: case 9: case 11:
                    if (valDia >= 1 && valDia <= 30) dia = valDia;
                break;
                default:
                    cout << "Mes invalido" << endl;
                break;
            }
        }
        void setMes(int val) {
            if (val >= 1 && val <= 12) mes = val;
        }
        void setAno(int val) {
            if (val > 1910 && val <= 2025) ano = val;
        }
};

void preencheTurma(Aluno turma[3]) {
    cout << endl << "Preenche dados dos alunos" << endl;
    for (int pos = 0; pos < 3; pos++) {
        cout << "Aluno " << (pos + 1) << endl;
        turma[pos].preenche();
    }
}

void exibeTurma(Aluno turma[3]) {
    cout << endl << "Exibe dados dos alunos" << endl;
    for (int pos = 0; pos < 3; pos++) {
        cout << "Aluno " << (pos + 1) << endl;
        turma[pos].exibe();
    }
}

float mediaIdades(Aluno turma[3]) {
    float soma = 0;
    for (int i = 0; i < 3; i++) soma += turma[i].getIdade();
    return soma / 3;
}

int main() {
    Aluno turma[3];
    float media, vals[] = {10, 10, 10};
    preencheTurma(turma);
    exibeTurma(turma);
    media = mediaIdades(turma);
    cout << "A media das idades e " << media << " anos!" << endl;
}