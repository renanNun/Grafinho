#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>

#include "no.h"
#include "aresta.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Renan Nunes da Costa Gon�alves
*   vers�o: 1.0
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

        void inserirNo(int id);
        void inserirAresta(int id, int id_alvo,float peso);
        void removerNo(int id);
        bool buscarNo(int id);
        No* getNo(int id);

        void aumentaNumArestas();
        void diminuiNumArestas();

        int grauMedioPorSomatorio();
        int grauMedioPorAdjacencia();

        bool depthFirstSearch(int id_inicial, int id_alvo);
        void breathFirstSearch(ofstream& output_file);
        Grafo* getComplementar();
        Grafo* getSubjacente();
        bool existeCircuito();
        bool ehConexo();
        float** floydMarshall();
        float* dijkstra(int id);

        void imprimir();

    private:
        int ordem;
        int numero_arestas;
        bool direcionado;
        bool ponderado_no;
        bool ponderado_aresta;
        No* primeiro_no;
        No* ultimo_no;

        //Fun��es auxiliares
        bool existeNo(int id);
        void removerAdjacencias(int id);
};

#endif // GRAFO_H
