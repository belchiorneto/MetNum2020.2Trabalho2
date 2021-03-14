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
        fonteVerde();  
        inicioCarro();
        cout << "╔";
        molduraHorizontal();
        cout<<"╗"<<endl<<"\r";

        inicioCarro();
        cout<<"║";
        percorrerLinha();
        cout<<"║";
        cout<<endl;
        inicioCarro();
        cout<<"║";
        percorrerLinha();
        cout<<"║";
        cout<<endl;
        inicioCarro();
        cout <<"║"<< "\t\t\t"<<"#####   ####   ####  #    # ###### #####"<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<< "\t\t\t"<<"#    # #    # #    # #   #  #        #  "<<"\t\t    ║" << endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"#    # #    # #      ####   #####    #"<<"\t\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"#####  #    # #      #  #   #        #  "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"#   #  #    # #    # #   #  #        #   "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"#    #  ####   ####  #    # ######   #   "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"                                         "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"                                         "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<" ####  #   #  ####  ##### ###### #    # "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"#       # #  #        #   #      ##  ## "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<" ####    #    ####    #   #####  # ## # "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"     #   #        #   #   #      #    # "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout <<"║"<<"\t\t\t"<<"######   #   ######   #   #####  #    #    # "<<"\t\t    ║"<<endl;
        inicioCarro();
        cout<<"║";
        percorrerLinha();
        cout<<"║";
        cout << endl;
        inicioCarro();
        cout<<"╚";
        molduraHorizontal();
        cout<<"╝"<<endl;
    }

    void Interface::descricao() {
        fonteVerde();
        inicioCarro();
        cout<<"│";
        percorrerLinha();
        cout<<"│"<<endl;
        inicioCarro();
        cout<<"│";
        resetarFonte();
        cout << "\t" <<"Rocket System é um software que calcula o deslocamento da extremidade";
        fonteVerde();
        cout <<"\t    │"<<endl;
        inicioCarro();
        fonteVerde();
        cout<<"│";
        resetarFonte();
        cout<<"\tde um foguete espacial com o intuito de garantir a eficiência no lançamento";
        fonteVerde();
        cout<<" │"<<endl;
        inicioCarro();
        fonteVerde();
        cout<<"│";
        resetarFonte();
        cout<<"\te a segurança de seus tripulantes.";
        fonteVerde();
        cout << "\t\t\t\t\t    │"<<endl;
        inicioCarro();
        cout<<"│";
        resetarFonte();
        cout<<"\tPara utilizar, preencha os parametros abaixo.";
        fonteVerde();
        cout<<"\t\t\t\t    │"<<endl;
        inicioCarro();
        cout<<"│";
        percorrerLinha();
        cout<<"│"<<endl;
        inicioCarro();
        cout<<"│";
        percorrerLinha();
        cout<<"│"<<endl;
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
            cout << "O foguete cairá." << endl;
        }
        else {
            cout << "O foguete nao caira" << endl;
        }
    }

    void Interface::detalhes(vector<vector<float>> matrizA, vector<vector<float>> &matrizL, vector<vector<float>> matrizU, vector<vector<float>> matrizD, vector<vector<float>> matrizP) {
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
/*
    void loopParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos) {
        // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
        for (int i = 0; i< *foguetes; i++)
        {
            float a;
            cout << "\tInforme o parametro de ajuste para o foguete "<<i+1<<":  ";
            //resetarFonte();
            cin >> a;
            //fonteVerde();
            //Metodos metodos = Metodos(*iteracoes);
            // setando os parametros comuns a todos os métodos
            //vetor_metodos.push_back(metodos); // armazena no vetor
        }
    }
/*
    void allParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos) {
        // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
        float isolamentoA;
        float isolamentoB;
        fonteVerde();
        cout << "\tIsolamento(a):  ";
        resetarFonte();
        cin >> isolamentoA;
        fonteVerde();
        cout << "\tIsolamento (b):  ";
        resetarFonte();
        cin >> isolamentoB;
        fonteVerde();
        cout << "\tErro permitido: ";
        resetarFonte();
        cin >> *E;
        fonteVerde();
        cout << "\tCasas decimais:  ";
        resetarFonte();
        cin >> *casasdecimais;
        fonteVerde();
        cout << "\tLimite Iteracoes: ";
        resetarFonte();
        cin >> *iteracoes;
        fonteVerde();
        cout << "\tArred. ou trunc (0 = arred, 1 trunc)"<<":  ";
        resetarFonte();
        cin >> *AoT;
    }
    */
    /*    
    void mostradados(vector<Metodos> vetor_metodos, int foguetes, int casasdecimais){
        // mostrar dados armazenados
        int espaco = 15; // tabulacao
        // primeiro quadro de respostas, apenas a raiz encontrada, se encontrada
        bool raizencontrada = false; // assumindo que nao temos raiz em nenhum metodo
        for(int i = 0; i < foguetes; i++){
            if(i == 0){ // cabecalho
                cout<<"Fuguete"<<setw(10);
                cout<<"Ajuste"<<setw(20);
                cout<<"Raiz Encontrada"<<setw(15);
                cout<<"Método Usado"<<endl;
            }
            resetarFonte();
            cout<<i+1<<setw(espaco);
            cout<<setprecision(casasdecimais)<<fixed;
            // pega a menor erro e identifica o metodo usado
            float x;
            float raiz;
            string metodousado;
            if(vetor_metodos[i].datametodos[0].converge){
                x = vetor_metodos[i].datametodos[0].erro;
                raiz = vetor_metodos[i].datametodos[0].raiz;
            }
            for(int k = 1; k<3; k++){
                if(vetor_metodos[i].datametodos[0].converge){
                    float x1 = vetor_metodos[i].datametodos[k].erro;
                    if(x1 < x){ // x assume a menor raiz
                        x = x1;
                        raiz = vetor_metodos[i].datametodos[k].raiz;
                        metodousado = vetor_metodos[i].datametodos[k].nome;
                    }
                }
            }
            cout<<vetor_metodos[i].ajuste<<setw(espaco);
            if(raizencontrada){
                cout<<raiz<<setw(espaco);
                cout<<metodousado<<endl;
            }else{
                cout<<"Nao converge"<<setw(espaco);
                cout<<"-"<<endl;
            }
            raizencontrada = false;
        }
        cout<<endl;
        // Segundo quadro de respostas, com os métodos e seus dados
        for(int i = 0; i<3; i++){ // loop nos metodos implementados
            if(i == 0){ // cabecalho
                cout<<"FOG."<<setw(10);
                cout<<"METODO"<<setw(15);
                cout<<"RAIZ"<<setw(15);
                cout<<"ERRO"<<setw(17);
                cout<<"AJUSTE"<<setw(20);
                cout<<"ISOLAMENTO"<<setw(20);
                cout<<"CONVERGE?" << endl;
            }
            resetarFonte();
            for (int j = 0; j<foguetes; j++){ // loop na quantidade de foguetes
                
                cout<<j+1<<setw(espaco);
                cout<<setprecision(casasdecimais)<<fixed;
                cout<<vetor_metodos[j].datametodos[i].nome<<setw(espaco);
                cout<<vetor_metodos[j].datametodos[i].raiz<<setw(espaco);
                cout<<vetor_metodos[j].datametodos[i].erro<<setw(espaco);
                cout<<vetor_metodos[j].ajuste<<setw(espaco);
                float a = vetor_metodos[j].getA();
                float b = vetor_metodos[j].getB();
                cout<<setprecision(0)<<fixed;
                cout<<"["<<a<<","<<b<<"]"<< setw(espaco);
                if(vetor_metodos[j].datametodos[i].converge){
                    cout<<"sim, em "<< vetor_metodos[j].datametodos[i].iter<< endl;
                }else{
                    cout<<"nao, em "<< vetor_metodos[j].datametodos[i].iter<< endl;
                }
                
            }
        }
    }
    */
    // para analizar se o foquete explode ou nao, (ou seja, se deslocamento > (2 + o erro permitido))
    /*
    void analisar(vector<Metodos> vetor_metodos, int foguetes, int iteracoes){
        for(int i = 0;i<foguetes; i++){
            resetarFonte();
            cout<<setprecision(7)<<fixed;
            cout<<"Foguete numero "<<i+1 << " ajuste: "<<vetor_metodos[i].ajuste<<endl;
            for(int j = 0; j<3; j++){
                cout<<"Metodo> " <<vetor_metodos[i].datametodos[j].nome<<" ------ > ";
                if(vetor_metodos[i].datametodos[j].fogueteexplode || !vetor_metodos[i].datametodos[j].converge){
                    fonteRed();
                    cout<<"falha!"<<endl;
                    resetarFonte(); 
                }else{
                    fonteVerde();
                    cout<<"Sucesso!"<<endl;
                    resetarFonte();
                }
            }
            cout<<"==================================="<<endl;
        }
    }
    
    
    void printparametros(int foguetes, int iteracoes, float E, float casasdecimais, bool AoT){
        fonteVerde();
        inicioCarro();
        cout<<"│";
        cout<<setprecision(casasdecimais)<<fixed;
        
        cout << "\tFoguetes:"<<foguetes<<" Iteracoes: "<<iteracoes<<" Erro: "<<E <<" Casas Dec.:"<<casasdecimais;
        cout<<"\t\t\t\t    │"<<endl;
    }
    */
    void Interface::menu() {
        fonteVerde();
        inicioCarro();
        cout<<"│";
        cout << "\t[1 = RECALCULAR][2 = DADOS][3 = BENCHMARK][4 = AJUSTE][0 = SAIR]";
        cout<<"\t    │"<<endl;
    }