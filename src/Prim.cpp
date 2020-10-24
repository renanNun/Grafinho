#include "Prim.h"
#define INFINITO 9999

Prim::Prim(Grafo *grafo)
{
    this->grafo = grafo;
    this->numeroDeArestas = 0;

    algoritmo();
}

Prim::~Prim() {}

void Prim::algoritmo()
{
    int* selecionado = new int[grafo->getOrdem()];
    int pesoMin = 0;

    No* no = this->grafo->getPrimeiroNo();

    for(int i = 0; i < this->grafo->getOrdem() && no != nullptr; i++)
    {
        no->i = i;
        selecionado[i] = false;
        no = no->getProx();
    }

    int x,y;

    selecionado[0] = true;

    bool** G = this->grafo->getMatrizDeAdj();
    float** P = this->grafo->getMatrizDePesos();

    corrigePesos(P);

    while(numeroDeArestas < this->grafo->getOrdem()-1)
    {
        int min = INFINITO;
        x = 0;
        y = 0;

        for(int i = 0; i < this->grafo->getOrdem(); i++)
        {
            if(selecionado[i])
            {
                for(int j = 0; j < this->grafo->getOrdem(); j++)
                {
                    if(!selecionado[j] && G[i][j])
                    {
                        if(min > P[i][j])
                        {
                            min = P[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << "-" << y << ":" << P[x][y] << endl;
        pesoMin+= P[x][y];
        selecionado[y] = true;
        numeroDeArestas++;
    }
    cout << "PESO MINIMO " << pesoMin << endl;
}

void Prim::corrigePesos(float** matriz)
{
    for(int i = 0; i < this->grafo->getOrdem(); i++)
        for(int j = 0; j < this->grafo->getOrdem(); j++)
    {
        if(matriz[i][j] == -1)
            matriz[i][j] = INFINITO;
    }
}
