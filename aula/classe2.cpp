#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
using namespace std;

class Figura {
    private:
        int lados;
        float tamanho;
    public:
        Figura () { inicializaTudo(1, 1); }
        Figura (int num, float val) { inicializaTudo(num, val); }
        void setNum (int num) {
            try {
                if (num > 0) lados = num;
                else throw invalid_argument ("Numero de lados invalido!");
            } catch (exception &e) { cerr << e.what() << endl; }
        }
        int getNum () { return lados; }
        void setTam (int val) {
            try {
                if (val > 0) tamanho = val;
                else throw invalid_argument ("Tamanho invalido!");
            } catch (exception &e) { cerr << e.what() << endl; }
        }
        float getTam () { return tamanho; }
        virtual void exibe () {}
        virtual float calculaArea () {}
        virtual float calculaPerimetro () {}
    private:
        void inicializaTudo (int num, float val) {
            setNum(num);
            setTam(val);
        }
};

class Quadrado : public Figura {
    public:
        Quadrado () {
            setNum(4);
            setTam(1);
        }
        Quadrado (float tam) {
            setNum(4);
            setTam(tam);
        }
        void exibe () { cout << "Quadrado com lados de tamanho " << getTam() << endl; }
        float calculaPerimetro () { return (getNum() * getTam()); }
        float calculaArea () { return (getTam() * getTam()); }
};

class Triangulo : public Figura {
    public:
        Triangulo () {
            setNum(3);
            setTam(1);
        }
        Triangulo (float tam) {
            setNum(3);
            setTam(tam);
        }
        void exibe () { cout << "Triangulo com lados de tamanho " << getTam() << endl; }
        float calculaPerimetro () { return (getNum() * getTam()); }
        float calculaArea () { return (pow(getTam(), 2) * sqrt(3) / 4); }
};

int main () {
    int tamanho;
    Quadrado q1; Triangulo t1;
    cout << "Insira o tamanho do quadrado: " << endl;
    cin >> tamanho;
    q1.setTam(tamanho);
    cout << "Insira o tamanho do triangulo: " << endl;
    cin >> tamanho;
    t1.setTam(tamanho);
    q1.exibe();
    cout << "Area do quadrado: " << q1.calculaArea() << endl << "Perimetro do quadrado: " << q1.calculaPerimetro() << endl;
    t1.exibe();
    cout << "Area do triangulo: " << t1.calculaArea() << endl << "Perimetro do triangulo: " << t1.calculaPerimetro() << endl;
}