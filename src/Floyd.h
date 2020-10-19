#ifndef FLOYD_H
#define FLOYD_H

#include "grafo.h"



using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli
*   vers�o: 1.0
*/
class Floyd
{
    public:

    void imprimirMatrizSolucao(int dist[][V]);
    Floyd (Grafo *G);


    private:

    int ordem;


};

#endif // FLOYD_H
