#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include "grafo.h"


using namespace std;

class Dijkstra
{
    public:
        Dijkstra(Grafo* g,int no_inicial);
        virtual ~Dijkstra();

        void iniciaIndices();
        void algoritmo();
        int buscaIndiceComMenorEstimativa(int* distancias, int* abertos,int tam);

    private:

        Grafo* graph;
        int no_inicial;


        int* vertices;
        int* distancias;
        int* predecessores;
        int* abertos;
};

#endif // DIJKSTRA_H
