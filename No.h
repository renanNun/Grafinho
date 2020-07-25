#ifndef NO_H
#define NO_H

#include <iostream>

#include "Aresta.h"

using namespace std;

class No
{
    public:
        No(int idNo, int pesoNo);
        virtual ~No();

        int getPeso();
        int getId();
        No* getProx();
        Aresta* getAresta();

        void setProx(No* p);

        void aumentaDin();
        void diminuiDin();
        void aumentaDout();
        void diminuiDout();

        Aresta* buscaAresta(int id);
        bool inserirAresta(int id, int peso);
        void removerAresta(int id);

        int visitado;

    private:
        int id;
        int peso;
        int grauDeEntrada;
        int grauDeSaida;
        No* prox;

        Aresta* cabeca;
        Aresta* cauda;

        bool vazio();

};

#endif // NO_H
