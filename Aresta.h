#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

using namespace std;

class Aresta
{
    public:
        Aresta(int idAdjacente,int pesoAresta);
        virtual ~Aresta();

        int getPeso();
        int getNoAdj();
        Aresta* getProx();

        void setProx(Aresta* a);


    private:
        int peso;
        int idNoAdjacente;
        Aresta* prox;
};

#endif // ARESTA_H
