#ifndef LISTAARESTA_H
#define LISTAARESTA_H
#include <iostream>
#include "aresta.h"

using namespace std;

class ListaAresta
{
    public:
        ListaAresta();
        virtual ~ListaAresta();

        Aresta* getPrimeiro();
        void insereAresta(int id_alvo,int id_origem,float peso);
        Aresta* removeAresta(int id_alvo,int id_origem);
        int getTamanho();
        bool vazia();
        void imprime();

    private:
        Aresta* primeiro;
        int tamanho;

        bool existeAresta(int id_alvo,int id_origem);
};

#endif // LISTAARESTA_H
