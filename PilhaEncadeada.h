#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include <iostream>
#include "NoAux.h"

using namespace std;

class PilhaEncadeada
{
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();

        int getTopo();
        void empilha(int id);
        int desempilha();
        bool vazia();
        int tamanho();

    private:
        NoAux* topo;
        int tam;
};

#endif // PILHAENCADEADA_H
