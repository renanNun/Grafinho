#ifndef PRIM_H
#define PRIM_H

#include "grafo.h"
#include "Utils/ListaArestasDuasPontas.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli
*   vers�o: 1.0
*/

#include <iostream>
#include "Utils/ArestaDuasPontas.h"
#include "Utils/ListaArestasDuasPontas.h"
#include "no.h"
#include "aresta.h"
#include "grafo.h"

class Prim
{

public:
    Prim(Grafo *grafo);

    ~Prim();

    void preencheLista();

private:
    Grafo *grafo;
    void ordenar(ArestaDuasPontas **a,int n);
    int binarySearch(ArestaDuasPontas **a, ArestaDuasPontas *item, int low, int high);
    ArestaDuasPontas** prim();

public:

    Grafo *gerar(float *soma);

};


#endif // PRIM_H

