#ifndef PRIM_H
#define PRIM_H

#include "grafo.h"


using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli
*   vers�o: 1.0
*/

#include <iostream>

#include "no.h"
#include "aresta.h"
#include "grafo.h"

class Prim
{

public:
    Prim(Grafo *grafo);
    ~Prim();

    void algoritmo();


private:
    int numeroDeArestas;
    Grafo* grafo;

    void corrigePesos(float** matriz);


};


#endif // PRIM_H

