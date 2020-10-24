#ifndef GRAFO_KRUSKAL_H
#define GRAFO_KRUSKAL_H

#include <iostream>
#include <stdlib.h>

#include "grafo.h"
#include "ListaAresta.h"

using namespace std;

class Kruskal
{

public:
    Kruskal(Grafo* grafo);
    ~Kruskal();

    //void algoritmo();
    void kruskal();
    void quickSort(int inicio, int fim);
    void auxQuickSort(Aresta vetor[],int inicio,int fim);
    float comparacao(Aresta* a,Aresta* b);

private:
    Grafo* grafo;
    ListaAresta* listaDeArestas;


    /*No* parent;
    ListaAresta* listaDeArestas;
    int numeroDeNos;

    void quickSort(ListaAresta* vetor, int inicio, int fim, int tam);
    void auxiliarQuickSort(Aresta* vetor,int inicio, int fim);

    int find_set(int i);
    void union_set(int u,int v);

    int retornaIndices(int i);*/
};


#endif //GRAFO_KRUSKAL_H
