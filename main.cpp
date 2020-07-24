#include <iostream>

#include "Grafo.h"

using namespace std;

int main()
{
    Grafo* g = new Grafo();

    g->carregarConfiguracoes(false,false,false);

    g->inserirNo(1,0);
    g->inserirNo(2,0);
    g->inserirNo(3,0);
    g->inserirNo(4,0);
    g->inserirNo(5,0);
    g->inserirNo(6,0);
    g->inserirNo(7,0);

    g->inserirAresta(1,2,0);
    g->inserirAresta(3,2,0);

    g->imprimirListaAdj();

    return 0;
}
