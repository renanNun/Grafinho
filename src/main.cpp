#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "grafo.h"
#include "no.h"
#include "Floyd.h"

using namespace std;
std::ifstream input_file;
std::ofstream output_file;

Grafo* leitura(int direcionado, int ponderadoAresta, int ponderadoNo)
{
    //Vari�veis auxiliares
    int id_no;
    int id_no_alvo;
    int ordem;

    string line;

    //Pegando a ordem do grafo
    getline(input_file,line);
    ordem = (stoi(line));

    Grafo* graph = new Grafo(ordem,direcionado,ponderadoAresta,ponderadoNo);

    //Leitura do Arquivo
    if(!graph->getPonderadoAresta() && !graph->getPonderadoNo())
    {
        while(input_file >> id_no >> id_no_alvo)
        {
            graph->inserirAresta(id_no,id_no_alvo,0);
            graph->adicionaArestaMatriz(id_no,id_no_alvo);
            if(!direcionado)
            {
                graph->inserirAresta(id_no_alvo,id_no,0);
                graph->adicionaArestaMatriz(id_no_alvo,id_no);
            }
            graph->aumentaNumArestas();
        }
    }
    else if(graph->getPonderadoAresta() && !graph->getPonderadoNo())
    {

        float peso_aresta;

        while(input_file >> id_no >> id_no_alvo >> peso_aresta)
        {
            graph->inserirAresta(id_no,id_no_alvo,peso_aresta);
            graph->adicionaArestaMatriz(id_no,id_no_alvo);
            if(!direcionado)
            {
                graph->inserirAresta(id_no_alvo,id_no,peso_aresta);
                graph->adicionaArestaMatriz(id_no_alvo,id_no);
            }
            graph->aumentaNumArestas();

        }
    }
    else if(!graph->getPonderadoAresta() && graph->getPonderadoNo())
    {
        float id_no_peso, id_no_alvo_peso;
        while(input_file >> id_no >> id_no_peso >> id_no_alvo >> id_no_alvo_peso)
        {
            graph->inserirAresta(id_no,id_no_alvo,0);
            graph->adicionaArestaMatriz(id_no,id_no_alvo);
            if(!direcionado)
            {
                graph->inserirAresta(id_no_alvo,id_no,0);
                graph->adicionaArestaMatriz(id_no_alvo,id_no);
            }
            graph->getNo(id_no)->setPeso(id_no_peso);
            graph->getNo(id_no_alvo)->setPeso(id_no_alvo_peso);

            graph->aumentaNumArestas();
        }
    }
    else if(graph->getPonderadoAresta() && graph->getPonderadoNo())
    {
        float id_no_peso,id_no_alvo_peso,aresta_peso;
        while(input_file >> id_no >> id_no_peso >> id_no_alvo >> id_no_alvo_peso >> aresta_peso)
        {
            graph->inserirAresta(id_no,id_no_alvo,aresta_peso);
            graph->adicionaArestaMatriz(id_no,id_no_alvo);
            if(!direcionado)
            {
                graph->inserirAresta(id_no_alvo,id_no,aresta_peso);
                graph->adicionaArestaMatriz(id_no_alvo,id_no);
            }
            graph->getNo(id_no)->setPeso(id_no_peso);
            graph->getNo(id_no_alvo)->setPeso(id_no_alvo_peso);

            graph->aumentaNumArestas();
        }
    }

    return graph;
}

void clear()
{
#if defined(__WIN32)
    system("cls");
#elif defined (__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif // defined
}

void mainMenu(Grafo* graph)
{
    int selecao;
    bool flag = false;
    string retornar;

    string id_inicial;
    string id_alvo;
    int a,b;

    cout << endl << endl;

    clear();

    while(true)
    {
        if(flag)
        {
            cout << "Escolha Invalida!" << endl << "Digite Novamente: ";
        }
        else
        {
            cout << "Escolha a opcao desejada: " << endl << endl;
        }
        flag = false;

        cout << endl << endl;
        cout << "\t\t MENU" << endl;
        cout << "--------------------------------" << endl;
        cout << "[01] Impressao por Lista de Adjacencia " << endl;
        cout << "[02] Impressao por Matriz de Adjacencia " << endl;
        cout << "[03] Ordem e Numero de Arestas do Grafo" << endl;
        cout << "[04] Grau Medio do Grafo" << endl;
        cout << "[05] Busca Em Profundidade" << endl;
        cout << "[06] Busca em Largura" << endl;
        cout << "[07] Algoritmo de Dijkstra" << endl;
        cout << "[08] Algoritmo de Prim" << endl;
        cout << "[09] Algoritmo de FloydMarshall" << endl;
        cout << "[10] Algoritmo de Kruskal" << endl;
        cout << " [0] Sair" << endl;

        cout << endl << "Escolha: ";
        cin >> selecao;

        clear();

        if(output_file.is_open())
        {
            switch(selecao)
            {
            case 0:
                cout << "Encerrando o programa" << endl;
                return;
            case 1:
                graph->imprimir();
                break;
            case 2:
                graph->imprimirMatriz();
                break;
            case 3:
                cout << "Ordem do Grafo: " << graph->getOrdem() << endl;
                cout << "Numero de Arestas: " << graph->getNumeroArestas() << endl;
                break;
            case 4:
                cout << "Grau Medio do Grafo " << endl;
                cout << "\tPor Somatorio: " << graph->grauMedioPorSomatorio() << endl;
                cout << "\tPor Adjacencia: " << graph->grauMedioPorAdjacencia() << endl;
                break;
            case 5:
                cout << "\tNo inicial: ";
                cin >> id_inicial;
                cout << "\tNo alvo: ";
                cin >> id_alvo;
                cout << endl;
                a = atoi(id_inicial.c_str());
                b = atoi(id_alvo.c_str());
                graph->depthFirstSearch(a,b);
                break;
            case 6:
                graph->breathFirstSearch(output_file);
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                    cout<< "Imprimindo solução Floyd: "
                    Floyd(graph);

                break;
            case 10:

                break;
            default:
                flag = true;
            }

            cout << endl<< endl<<"Pressione ENTER para voltar ao menu."<<endl;

            if(!flag)
            {
#if defined(__WIN32)
                system("read retornar");
#elif defined(__linux__)
                system("read retornar");
#elif defined(__APPLE__)
                system("read retornar");
#endif // defined
            }
        }
        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;

    }
}

int main(int argc, char const *argv[])
{
    //Verifica��o se todos os par�metros do programa foram entrados
    if(argc != 6)
    {
        cout << "ERROR: Espera-se: ./<program_name> <input_file> <output_file> <direcionado> <ponderado_aresta> <ponderado_no>" << endl;
        return 1;
    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    string instance;

    //Abrindo arquivo de entrada
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);

    Grafo* graph;

    if(input_file.is_open())
    {

        graph = leitura(atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    }
    else
        cout << "Unable to open " << argv[1];


    mainMenu(graph);

    if(input_file_name.find("v") <= input_file_name.size())
    {
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " com a instancia " << instance << " ... " << endl;
    }

    output_file << "\t\tTRABALHO DE GRAFOS" << endl;
    output_file << "alunos: Luan Reis Ciribelli e Renan Nunes da Costa Gon�alves" << endl << endl;
    output_file << "Numero de Vertices: " << graph->getOrdem() << endl;
    output_file << "Numero de Arestas: " << graph->getNumeroArestas()  <<endl;
    output_file << "Grau Medio do Grafo" << endl;
    output_file << "\tPor Adjacencia: " << graph->grauMedioPorAdjacencia() << endl;
    output_file << "\tPor Adjacencia: " << graph->grauMedioPorSomatorio() << endl;
    output_file << "Fecho Triadico: " << endl;
    output_file << endl << endl;

    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saída
    output_file.close();

    return 0;
}
