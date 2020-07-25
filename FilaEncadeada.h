#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H

#include <iostream>
#include "NoAux.h"

using namespace std;

class FilaEncadeada
{
    public:
        FilaEncadeada();
        virtual ~FilaEncadeada();

        bool vazia();

        int getInicio();
        void enfileira(int id);
        int desenfileira();

        void imprime();
    private:
        NoAux* cabeca;
        NoAux* cauda;
};

#endif // FILAENCADEADA_H
