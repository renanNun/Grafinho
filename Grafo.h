#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "No.h"
#include "PilhaEncadeada.h"
#include "FilaEncadeada.h"

using namespace std;

class Grafo
{
    public:
        Grafo();
        virtual ~Grafo();

        void carregarConfiguracoes(bool dir, bool pondA, bool pondN);

        int getOrdem();
        int getNumAretas();

        void inserirNo(int id, int peso);
        void inserirAresta(int idOrigem, int idDestino, int peso);
        void removerNo(int id);
        void removerAresta(int idOrigem, int idDestino);


        void imprimirListaAdj();

        int **getMatrizAdj();
        int getPosicaoMatriz(int id);

        bool isDir();
        bool isPondA();
        bool isPondN();

        void buscaEmProfundidade(int idOrigem, int idDestino);

    private:
        No* cabeca;
        No* cauda;

        int ordem;
        int numArestas;

        bool direcionado;
        bool ponderadoA;
        bool ponderadoN;

        bool existeNo(int id);
        No* buscaNo(int id);

        bool visitado(int id, int* vetor, int tam);

        void removeAdjacencias(int id);
};

#endif // GRAFO_H
