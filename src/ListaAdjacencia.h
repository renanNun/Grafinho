#ifndef LISTAADJACENCIA_H
#define LISTAADJACENCIA_H
#include "no.h"
#include "grafo.h"
#include <list>

class ListaAdjacencia
{
    public:
        ListaAdjacencia(Grafo G,No* Inicial);
        virtual ~ListaAdjacencia();
        bool isEmpty();
        list<list> listadeNos(No* incial);


    private:
    No* head;
};

#endif // LISTAADJACENCIA_H
