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
        Floyd(Grafo* g, float** matrizAdj);
        ~Floyd();

        void algoritmo();
        void printSolucao(float** dist);

    private:
       int n;
       float** A;
       int** B;
};

#endif // FLOYD_H
