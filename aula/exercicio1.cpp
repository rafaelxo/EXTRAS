#include <iostream>
using namespace std;

#define TAM 3

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
        void setData(int d, int m, int a) {
            setDia(d, m);
            setMes(m);
            setAno(a);
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
            for (int prova = 0; prova < 3; prova++) {
                if (valores[prova] >= 0) notas[prova] = valores[prova];
                else cout << "ERRO - Nota negativa para prova " << prova << endl;
            }
        }
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
            }
        }
        int getAno() { return ano; }
        string getData() {
            string texto = to_string(getDia()) + " de " + getMes() + " de " + to_string(getAno());
            return texto;
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
            cin >> vet[0] >> vet[1] >> vet[2];
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
            cout << "Notas: " << getNotas()[0] << ", " << getNotas()[1] << " e " << getNotas()[2] << endl;
            cout << "Data de nascimento: " << getData() << endl;
        }
        string getNome() { return nome; }
        int getIdade() { return idade; }
        float *getNotas() { return notas; }
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
            if (val > 1910) ano = val;
        }
};

void preencheTurma(Aluno turma[TAM]) {
    cout << endl << "Preenche dados dos alunos" << endl;
    for (int pos = 0; pos < TAM; pos++) {
        cout << "Aluno " << pos << endl;
        turma[pos].preenche();
    }
}

void exibeTurma(Aluno turma[TAM]) {
    cout << endl << "Exibe dados dos alunos" << endl;
    for (int pos = 0; pos < TAM; pos++) {
        cout << "Aluno " << pos << endl;
        turma[pos].exibe();
    }
}

float mediaIdades(Aluno turma[TAM]) {
    float soma = 0;
    for (int i = 0; i < TAM; i++) soma = soma + turma[i].getIdade();
    return soma / TAM;
}

int main() {
    Aluno turma[TAM];
    float media, vals[] = {10, 10, 10};
    preencheTurma(turma);
    exibeTurma(turma);
    media = mediaIdades(turma);
    cout << "A media das idades eh " << media << endl;
    return 0;
}