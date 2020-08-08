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
    int getNumArestas();

    void inserirNo(int id, int peso);
    void inserirAresta(int idOrigem, int idDestino, int peso);
    void removerNo(int id);
    void removerAresta(int idOrigem, int idDestino);


    void imprimirListaAdj();

    int **getMatrizAdj();
    int getPosicaoMatriz(int id);
    int grauMedioPorSomatorio();
    int grauMedioPorAdjacencia();

    bool isDir();
    bool isPondA();
    bool isPondN();

    void buscaEmProfundidade(int id);
    void buscaEmLargura(int id); //Tá com erro de Falha de segmentação
    void BEL(int id);

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
    void buscaEmProfundidadeF(No* v,bool* vetorColoracao, No* pai, int nivel);
    void buscaEmLarguraF(No* pai, int* vetorColoracao,bool* vetorColoracaoB,bool* vetorColoracaoC);
};

#endif // GRAFO_H
