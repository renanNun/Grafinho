#ifndef CAMINHOMINIMO_H
#define CAMINHOMINIMO_H

#include "grafo.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli
*   vers�o: 1.0
*/
class CaminhoMinimo
{
public:

    caminhoMinimo(Grafo *grafo);
    void relax(No *u, No *v, int peso);
private:

    No * cabeça;


};

#endif // CAMINHOMINIMO_H
