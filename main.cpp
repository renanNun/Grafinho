#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Grafo.h"

using namespace std;
std::fstream fin;

void menu(Grafo* g);
void getConfig(Grafo* g);
Grafo* realizaLeitura();

int main(int argc,char* argv[])
{
    Grafo* g = new Grafo();

    g->carregarConfiguracoes(false,false,false);

    g->inserirNo(1,0);
    g->inserirNo(2,0);
    g->inserirNo(3,0);
    g->inserirNo(4,0);
    g->inserirNo(5,0);
    g->inserirNo(6,0);
    g->inserirNo(7,0);

    g->inserirAresta(1,2,0);
    g->inserirAresta(3,2,0);

    menu(g);

    return 0;
}

void menu(Grafo* g)
{
    string stringEscolha,stringEscolhaAux,stringEscolhaAux2,retornar;
    int escolha;
    bool flagInvalido = false;

    int a,b,c;

    cout << endl << endl;

    while(true)
    {
        system("clear");

        if(flagInvalido)
        {
            cout << "Opção Inválida!" << endl << "Digite Novamente: ";
        }
        else
        {
            cout << "Digite a Opção desejada: " << endl;
        }
        flagInvalido = false;

        cout << endl << endl;
        cout << "\t 01) Imprimir o Grafo por Lista de Adjacência" << endl;
        cout << "\t 02) Imprimir o Grafo por Matriz de Adjacência" << endl;
        cout << "\t 03) Inserir Nó no Grafo" << endl;
        cout << "\t 04) Inserir Aresta no Grafo" << endl;
        cout << "\t 05) Remover Nó do Grafo" << endl;
        cout << "\t 06) Remover Aresta do Grafo" << endl;
        cout << "\t  0) Sair" << endl;
        cout << endl << "Opção: ";

        cin >> stringEscolha;
        escolha = atoi(stringEscolha.c_str());

        system("clear");

        switch(escolha)
        {
        case 0:
            cout << "Encerrando programa" << endl;
            return;
        case 1:
            g->imprimirListaAdj();
            break;
        case 2:
            break;
        case 3:
            if(g->isPondN())
            {
                cout << "Insira o Valor: ";
                cin >> stringEscolha;
                cout << endl << "Insira o Peso: ";
                cin >> stringEscolhaAux;
                cout << endl;

                a = atoi(stringEscolha.c_str());
                b = atoi(stringEscolhaAux.c_str());

            }
            else
            {
                cout << "Insira o Valor: ";
                cin >> stringEscolha;
                cout << endl;
                a = atoi(stringEscolha.c_str());
                b = 0;
            }
            g->inserirNo(a,b);
            break;
        case 4:
            if(g->isPondA())
            {
                cout << "Insira o Nó de Origem: ";
                cin >> stringEscolha;
                cout << endl << "Insira o Nó de Destino: ";
                cin >> stringEscolhaAux;
                cout << endl << "Insira o Peso: ";
                cin >> stringEscolhaAux2;
                cout << endl;

                a = atoi(stringEscolha.c_str());
                b = atoi(stringEscolhaAux.c_str());
                c = atoi(stringEscolhaAux2.c_str());

            }
            else
            {
                cout << "Insira o Nó de Origem: ";
                cin >> stringEscolha;
                cout << endl << "Insira o Nó Destino: ";
                cin >> stringEscolhaAux;
                cout << endl;
                a = atoi(stringEscolha.c_str());
                b = atoi(stringEscolhaAux.c_str());
                c = 0;
            }
            g->inserirAresta(a,b,c);
            break;
        case 5:
            cout << "Insira o Nó a ser removido: ";
            cin >> stringEscolha;

            a = atoi(stringEscolha.c_str());
            g->removerNo(a);
            break;
        case 6:
            cout << "Insira o Nó de origem: ";
            cin >> stringEscolha;
            cout << endl << "Insira o Nó destino: ";
            cin >> stringEscolhaAux;

            a = atoi(stringEscolha.c_str());
            b = atoi(stringEscolhaAux.c_str());

            g->removerAresta(a,b);

            break;
        default:
            flagInvalido = true;
        }

        cout << endl<< endl<<"Pressione ENTER para voltar ao menu."<<endl;

        if (!flagInvalido)
            system("read retornar");

    }
}
