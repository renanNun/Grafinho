#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <chrono>
#include <stack>
#include <list>
#include <queue>

#include "no.h"
#include "aresta.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Renan Nunes da Costa Gonçalves
*   versão: 1.0
*/
class Grafo
{
public:
    Grafo(int ordem, bool direcionado,bool ponderado_aresta,bool ponderado_no);
    virtual ~Grafo();

    int getOrdem();
    int getNumeroArestas();
    bool getDirecionado();
    bool getPonderadoAresta();
    bool getPonderadoNo();
    No* getPrimeiroNo();
    No* getUltimoNo();
    void setOrdem(int ordem);

    void inserirNo(int id);
    void inserirAresta(int id, int id_alvo,float peso);
    void removerNo(int id);
    bool buscarNo(int id);
    No* getNo(int id);

    void aumentaNumArestas();
    void diminuiNumArestas();

    int grauMedioPorSomatorio();
    int grauMedioPorAdjacencia();


    bool depthFirstSearch(int id_inicial);
    void breathFirstSearch(ofstream& output_file);

    void imprimir();
    void imprimirMatriz();

    float** getMatriz();

    void adicionaArestaMatriz(int i,int j,float peso);
    void removeArestaMatriz(int i, int j);
    bool verificaAdjacencia(int i, int j);

    double frequenciaRelativa(int d);

    // Kruskal
    int listarComponentesConexas(int* indComp, int* idNos);

private:
    int ordem;
    int numero_arestas;
    bool direcionado;
    bool ponderado_no;
    bool ponderado_aresta;
    No* primeiro_no;
    No* ultimo_no;

    float** matriz_adjacencia;
    void getMatrizAdj();
    void deleteMatrizAdj();
    int getPosicaoMatriz(int id);


    //Funções auxiliares
    bool existeNo(int id);
    void removerAdjacencias(int id);
    void depthFirstSearchF(No* no, bool* vetor_coloracao,No* pai, int nivel);




};

#endif // GRAFO_H
