#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Metodos {
    protected:
    int tam;                    //Numero de deslocamentos
    vector<vector<float>> A;    //Matriz de coeficientes
    vector<float> f;            //Vetor de termos independentes.
    vector<float> solucao;
    vector<vector<float>> matrizL;
    vector<vector<float>> matrizU;
    vector<vector<float>> matrizD;
    vector<vector<float>> matrizP;

    // para benchmark
    vector<vector<float>> bench = {
        {3, -2, 1},
        {1, -3, 4},
        {9, 4, -5}
    };
    vector<float> benchIndependente = {
        8, 6, 11
    };
    public:
    void setBench();
    void ajuste(float porcento);    
    void setA(vector<vector<float>> matriz);
    vector<vector<float>> getA();
    void setTam(int tam);
    int getTam();
    void iniciarMatrizL();
    void iniciarMatrizU();
    vector<float> pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador);
    void printarVetor(vector<float> vetor);
    void printarMatriz(vector<vector<float>> matriz);
    vector<float> fatoracaoLuNormal();
    vector<float> fatoracaoLDP();
    vector<float> solucionarSistemaInferior(vector<vector<float>> matrizL, vector<float> f);
    vector<float> solucionarSistemaSuperior(vector<vector<float>> matrizU, vector<float> f);
    void iniciarMatrizD(vector<vector<float>> matrizU);
    void iniciarMatrizP(vector<vector<float>> matrizU);
    vector<vector<float>> getMatrizU();
    vector<vector<float>> getMatrizL();
    vector<vector<float>> getMatrizD();
    vector<vector<float>> getMatrizP();
    void setF(vector<float> f);
    bool conclusao();
    Metodos(){

    }
};

void Metodos::ajuste(float porcento){
    for(int i = 0; i<this->A.size(); i++){
        for(int j = 0; j<this->A.size(); j++){
            this->A[i][j] = this->bench[i][j] +  (this->bench[i][j] * (porcento / 100));
        }
    }
    setTam(A.size());
}
void Metodos::setF(vector<float> f){
    this->f = f;   
}
void Metodos::setBench(){
    this->f = this->benchIndependente;
    this->A = this->bench;
    setTam(this->A.size());
}
void Metodos::setTam(int tam){
    this->tam = tam;
    iniciarMatrizL();
    iniciarMatrizU();
}

void Metodos::setA(vector<vector<float>> matriz) {
    this->A = matriz;
    this->bench = matriz;
}

vector<vector<float>> Metodos::getA() {
    return this->A;
}

vector<vector<float>> Metodos::getMatrizL() {
    return this->matrizL;
}

vector<vector<float>> Metodos::getMatrizU() {
    return this->matrizU;
}

vector<vector<float>> Metodos::getMatrizD() {
    return this->matrizD;
}

vector<vector<float>> Metodos::getMatrizP() {
    return this->matrizP;
}


int Metodos::getTam() {
    return this->tam;
}

void Metodos::iniciarMatrizL() {
    matrizL.resize(this->getTam());
    for(int i=0; i<this->getTam(); i++) {
        matrizL[i].resize(this->getTam());
        for(int j=0; j<this->getTam(); j++) {
            if(i == j)  matrizL[i][j] = 1;
            else        matrizL[i][j] = 0;
        }
    }
}

void Metodos::iniciarMatrizU() {
    matrizU.resize(this->getTam());
    for(int i=0; i<this->getTam(); i++) {
        matrizU[i].resize(this->getTam());
        for(int j=0; j<this->getTam(); j++) {
            matrizU[i][j] = this->getA()[i][j];
        }
    }
}

vector<float> Metodos::fatoracaoLuNormal() {
    int iteracao = 0;
    float pivo;
    float multiplicador;

    for(int j=0; j<this->getTam(); j++) {
        pivo = matrizU[j][j];
        for(int i=j+1; i<matrizU.size(); i++) {
            multiplicador = matrizU[i][j]/pivo;
            matrizL[i][j] = multiplicador;
            matrizU[i] = pivoteamento(matrizU[iteracao],matrizU[i],multiplicador);
            multiplicador = matrizU[i][j]/pivo;
        }
        iteracao++;
    }
    //LY = b
    vector<float> y(this->getTam());
    y = solucionarSistemaInferior(this->matrizL,this->f);

    //Ux=y
    vector<float> x(this->getTam());
    x = solucionarSistemaSuperior(this->matrizU, y);
    for(int i=0; i<x.size(); i++) {
        x[i] = abs(x[i]);
    }
    solucao = x;
    return x;
}

vector<float> Metodos::pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador) {
    for(int j=0;j<this->A.size(); j++) {
        linhaOperanda[j] = linhaOperanda[j] - multiplicador*linhaPivo[j];
    }
    return linhaOperanda;
}

vector<float> Metodos::solucionarSistemaInferior(vector<vector<float>> matriz, vector<float> f) {
    vector<float> x(matriz.size());
    float controlador;
    for(int i=0;i<x.size();i++) {
        controlador = 0;
        for(int j=0; j<i; j++) {
            if(matriz[i][j] != 0) {
                controlador = controlador + matriz[i][j]*x[j];  
            }
        }
        x[i] = (f[i]-controlador)/matriz[i][i];
    }
    return x;
}

vector<float> Metodos::solucionarSistemaSuperior(vector<vector<float>> matriz, vector<float> f) {
    vector<float> x(matriz.size());
    float controlador;
    for(int i=x.size()-1; i>=0; i--) {
        controlador=0;
        for(int j=x.size()-1; j>i; j--) {
            if(matriz[i][j] != 0) {
                controlador = controlador + matriz[i][j]*x[j];  
            }
        }
        x[i] = (f[i]-controlador)/matriz[i][i];
    }
    return x;
}

void Metodos::printarVetor(vector<float> vetor) {
    for(int i=0; i<vetor.size(); i++) {
        cout << vetor[i]<< "  ";
    }
}

void Metodos::printarMatriz(vector<vector<float>> matriz) {
    for(int i=0;i<matriz.size(); i++) {
        for(int j=0; j<matriz.size(); j++) {
            cout << matriz[i][j] <<"  ";
        }
        cout << endl;
    }
}

/******************* Inicio FatoracaoLDP *****************************/

void Metodos::iniciarMatrizD(vector<vector<float>> matrizU) {
    this->matrizD = matrizU;
    for(int i=0; i<matrizD.size(); i++) {
        for(int j=0; j<matrizD.size(); j++) {
            if(i==j)
                matrizD[i][j] = matrizU[i][j];
            else
                matrizD[i][j] = 0;
        }
    }
}

void Metodos::iniciarMatrizP(vector<vector<float>> matrizU) {
    this->matrizP = matrizU;
    for(int i=0; i<matrizU.size(); i++) {
        for(int j=0; j<matrizU.size(); j++) {
            this->matrizP[i][j] = (matrizU[i][j])/matrizU[i][i];
        }
    }
}

vector<float> Metodos::fatoracaoLDP() {
    iniciarMatrizD(this->matrizU);
    iniciarMatrizP(this->matrizU);

    vector<float> z = solucionarSistemaInferior(this->matrizL,this->f);
    vector<float> y = solucionarSistemaSuperior(this->matrizD,z);
    vector<float> x = solucionarSistemaSuperior(this->matrizP,y);
    for(int i=0; i<x.size(); i++) {
        x[i] = abs(x[i]);
    }
    solucao = x;
    return x;
}

bool Metodos::conclusao() {
    for(int i=0; i<solucao.size(); i++) {
        if(solucao[i] > 2)
            return true;
    }
    return false;
}