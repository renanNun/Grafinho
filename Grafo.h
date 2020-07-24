#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "No.h"

using namespace std;

class Grafo
{
    public:
        Grafo();
        virtual ~Grafo();

        void carregarConfiguracoes(bool dir, bool pondA, bool pondN);

        void inserirNo(int id, int peso);
        void inserirAresta(int idOrigem, int idDestino, int peso);

        void imprimirListaAdj();

        int getOrdem();
        int getNumAretas();

        int **getMatrizAdj();
        int getPosicaoMatriz(int id);

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
};

#endif // GRAFO_H
