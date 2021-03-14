#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdlib.h>

using namespace std;
class Interface {

    public:
    
    void fonteVerde();
    void fonteRed();
    void resetarFonte();
    void inicioCarro();
    void molduraHorizontal();
    void percorrerLinha();
    void header();
    void descricao();
    void menu();
    void dadosSaida(vector<float> &vetorResposta);
    void respostaLDP(vector<float> &vetorResposta);
    void conclusaoFinal(bool decisao);
    void detalhes(vector<vector<float>> matrizA, vector<vector<float>> &matrizL, vector<vector<float>> matrizU, vector<vector<float>> matrizD, vector<vector<float>> matrizP); 
    void matrizPrint(vector<vector<float>> matriz);
    void vetorPrint(vector<float> vetor);

  //  void printparametros(int foguetes, int iteracoes, float E, float casasdecimais, bool AoT);
    void menuInicial(vector<vector<float>> &minhamatriz, vector<float> &independente, int *n);
    //void loopParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos);
    //void allParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos);
    
    void mostradados(int foguetes, int casasdecimais);
    //void analisar(vector<Metodos> vetor_metodos, int foguetes, int iteracoes);
    void decisaoFinal(bool *decisao);
    Interface(){

    }
};
    void Interface::fonteVerde() {
        cout << "\033[0;32m";
    }
    void Interface::fonteRed() {
        cout << "\033[0;31m";
    }

    void Interface::resetarFonte() {
        cout<<"\033[1;0m";
    }

    void Interface::inicioCarro() {
        cout << "\t   ";
    }

    void Interface::molduraHorizontal() {
        for(int i=0; i<80; i++) {cout <<"═";}
    }

    void Interface::percorrerLinha() {
        fonteVerde();
        for(int i=0; i<80; i++) {cout <<" ";}
    }

    void Interface::header() {
      
    }

    void Interface::descricao() {
       
    }

    void Interface::menuInicial(vector<vector<float>> &minhamatriz, vector<float> &independente, int *n) {
        fonteVerde();
        inicioCarro();
        
        cout<<"│";
        //cout<<"\t"<<"Insira o nº de linhas da matriz: ";
        cout<<"\t\t\t\t\t\t\t\t\t\t    │";
        cout<<"\r\t\tInsira o nº de deslocamentos:  ";
        resetarFonte();
        cin >> *n;
        float valor;
        minhamatriz.resize(*n);
        independente.resize(*n);
        cout<<"foi gerado uma matriz "<< *n << " X " <<*n <<", preencha os valores"<<endl;
        for(int i = 0; i<*n; i++){
            minhamatriz[i].resize(*n);
;            for (int j = 0; j<*n; j++) {
                cout<<"\r\t\tDados da matriz linha "<< i+1 <<" coluna "<<j+1<<":  ";
                cin >> valor;
                
                minhamatriz[i][j] = valor;
                
            }
           
        }
        float valor2;
        cout<<"agora preencha os " << *n << " valores do vetor independente do sistema:"<<endl;
        for(int i = 0; i<*n; i++){
            cout<<"\r\t\tDados do vetor intependente, coluna "<<i+1<<":  ";
            cin >> valor2;
            independente[i] = valor2;
        }
        inicioCarro();
        fonteVerde();
        
    }

    void Interface::dadosSaida(vector<float> &vetorResposta) {
        cout << endl;
        inicioCarro();
        cout <<"════════════════════════════════ Dados de saída ══════════════════════════════════" << endl;
        int n = vetorResposta.size();
        resetarFonte();
        inicioCarro();
        cout << "\t  ";
        cout << "Fatoracao LU Normal:   d:";
        vetorPrint(vetorResposta);
    } 

    void Interface::respostaLDP(vector<float> &vetorResposta) {
        inicioCarro();
        cout << "\t  ";
        int n = vetorResposta.size();
        cout << "Fatoracao LDP:   d:";
        vetorPrint(vetorResposta);
        
    }

    void Interface::conclusaoFinal(bool decisao) {
        cout << endl;
        inicioCarro();
        cout << "\t  ";
        if(decisao == true) {
            cout << "\n O foguete cairá." << endl;
        }
        else {
            cout << "\n O foguete nao caira" << endl;
        }
    }

    void Interface::detalhes(
        vector<vector<float>> matrizA,
        vector<vector<float>> &matrizL,
        vector<vector<float>> matrizU,
        vector<vector<float>> matrizD,
        vector<vector<float>> matrizP) {
        
        fonteVerde();
        inicioCarro();
        cout <<"════════════════════════════════ Matrizes da fatoracao LU ══════════════════════════════" << endl;
        resetarFonte();
        inicioCarro();
        cout << "\t ";
        cout << "1) ********* Matriz L *********" << endl;
        matrizPrint(matrizL);
        inicioCarro();
        cout << "\t ";
        cout << "2) ********* Matriz U *********" << endl;
        matrizPrint(matrizU);
        fonteVerde();
        inicioCarro();
        cout <<"════════════════════════════════ Matrizes da fatoracao LDP ══════════════════════════════" << endl;
        resetarFonte();
        inicioCarro();
        cout << "\t ";
        cout << "1) ********* Matriz L *********" << endl;
        matrizPrint(matrizL);
        inicioCarro();
        cout << "\t ";
        cout << "2) ********* Matriz D *********" << endl;
        matrizPrint(matrizD);
        inicioCarro();
        cout << "\t ";
        cout << "3) ********* Matriz P *********" << endl;
        matrizPrint(matrizP);
    }
void Interface::matrizPrint(vector<vector<float>> matriz) {
    cout<<setprecision(2)<<fixed; // casas decimais
    cout << endl;
    int linha = matriz.size() * 7;
    cout << "\t   ╔";
    for(int l = 0; l < linha; l++){
        cout<<"═";
    }
    cout<<"╗"<<endl;
    for(int i=0;i<matriz.size(); i++) {
        cout << "\t   ║  ";
        for(int j=0; j<matriz.size(); j++) {
            if(matriz[i][j] < 0){
                if(matriz[i][j] > 10){
                    cout << matriz[i][j] <<"║";
                }else{
                    cout << matriz[i][j] <<"║ ";
                }
            }else{

                cout << matriz[i][j] <<" ║ ";
            }
            
        }
        cout << endl;
        if(i<matriz.size() - 1){
            cout << "\t   ║";
            for(int l = 0; l < linha; l++){
                cout<<"═"; // ate penultima linha
            }
            cout<<"║"<<endl;    
        }
     
    }

    cout << "\t   ╚";
    for(int l = 0; l < linha; l++){
        cout<<"═";
    }
    cout<<"╝"<<endl;
}

void Interface::vetorPrint(vector<float> vetor) {
    cout<<setprecision(3)<<fixed; // casas decimais
    cout << endl;
    cout << "\t   ╔";
    for(int l = 0; l < vetor.size() * 10 - 1; l++){
        cout<<"═";
    }
    cout<<"╗"<<endl;
    cout << "\t   ║  ";
    for(int i=0;i<vetor.size(); i++) {
        cout << vetor[i] <<"  ║  ";
    }
    cout<<endl;
    cout << "\t   ╚";
    for(int l = 0; l < vetor.size() * 10 - 1; l++){
        cout<<"═";
    }
    cout<<"╝"<<endl;
}
    void Interface::menu() {
        fonteVerde();
        inicioCarro();
        cout<<"│";
        cout << "\t[1 = RECALCULAR][2 = DADOS][3 = BENCHMARK][4 = AJUSTE][0 = SAIR]";
        cout<<"\t    │"<<endl;
    }