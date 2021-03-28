#include "Metodos.cpp"
#include "Interface.cpp"

#include<vector>
#include<iostream>
using namespace std;

int main() {
    Interface interface;
    Metodos metodos;
    int n; // quantidade de linhas e colunas da matriz

    vector<vector<float>> minhamatriz;
    vector<float> independente;
    vector<float> resposta;
    vector<vector<float>> matrizL;
    vector<vector<float>> matrizU;
    vector<vector<float>> matrizD;
    vector<vector<float>> matrizP;
    int decisao = 1;
    int tmp = 0;
    do {
        switch(decisao)
        {
        case 1:
            // primeira opcao, onde sao definidos o numero de foquetes e o ajuste
            // monta tela inicial
            system("clear");
            
            interface.header();
            interface.menu();
            interface.descricao();
            cout<<"\r\t\tTecle 3 para usar valores de benchmark ou 1 para preencher: ";
            cin >> tmp;
            if(tmp == 3){
                decisao = 3;
                continue;
            }
            interface.menuInicial(minhamatriz, independente, &n);
            metodos.setA(minhamatriz);
            metodos.setTam(n);
            metodos.setF(independente);
            interface.matrizPrint(metodos.getA());
            resposta = metodos.fatoracaoLuNormal();

            interface.dadosSaida(resposta);
            

            resposta = metodos.fatoracaoLDP();
            interface.respostaLDP(resposta);
            metodos.conclusao();

            
            decisao = 0;
            interface.inicioCarro();
            cout << "\t  ";
            cout<<"Os dados foram calculados! tecle 2 para detalhes de implementação:  ";
            break;
        case 2:
            cout<<"DECISAO:  " << decisao << "\n\n";
            matrizL = metodos.getMatrizL();
            matrizU = metodos.getMatrizU();
            matrizD = metodos.getMatrizD();
            matrizP = metodos.getMatrizP();
            interface.detalhes(minhamatriz, matrizL, matrizU, matrizD, matrizP);
            cout<<endl<<endl;
            interface.inicioCarro();
            cout << "\t   ";
            cout << "Os detalhes foram mostrados. Tecle 1 para novo cálculo. Tecle 0 para sair: ";
            break;
        case 3: // benchmark
            metodos.setBench();
            interface.matrizPrint(metodos.getA());
            resposta = metodos.fatoracaoLuNormal();
            interface.dadosSaida(resposta);
            resposta = metodos.fatoracaoLDP();
            interface.respostaLDP(resposta);
            resposta = metodos.conclusao();
            interface.conclusaoFinal(resposta);
            decisao = 0;
            interface.inicioCarro();
            cout << "\t  ";
            cout<<"Os dados foram calculados! tecle 2 para detalhes de implementação:  ";
            break;
        case 4: // benchmark
            system("clear");
            interface.header();
            interface.menu();
            interface.descricao();
            cout<<"\r\t\tporcentagem de ajuste: ";
            cin >> tmp;
            metodos.ajuste(tmp);
            interface.matrizPrint(metodos.getA());
            resposta = metodos.fatoracaoLuNormal();
            interface.dadosSaida(resposta);
            resposta = metodos.fatoracaoLDP();
            interface.respostaLDP(resposta);
            resposta = metodos.conclusao();
            interface.conclusaoFinal(resposta);
            
            decisao = 0;
            interface.inicioCarro();
            cout << "\t  ";
            cout<<"Os dados foram calculados! tecle 2 para detalhes de implementação:  ";
            break;
            
        default:    
            cout<<"DECISAO:  " << decisao << "\n\n";
            // mesmo que a opcao "1", fica como padrao
            // monta tela inicial
            interface.header();
            break;
        }
        cin >> decisao;
        
    }while(decisao != 0);
    return 0;
}