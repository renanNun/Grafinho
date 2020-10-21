#ifndef LISTAARESTADUASPONTAS_H
#define LISRAARESTADUASPONTAS_H

#include "ArestaDuasPontas.h"


using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli e Renan Nunes
*   vers�o: 1.0
*/
class ListaArestaDuasPontas
{
public:
    ListaArestaDuasPontas();
    ~ListaArestaDuasPontas();

    ArestaDuasPontas* getPrimeiro();
    void insereAresta(int id,int id2, float peso);
    ArestaDuasPontas* removeAresta(int id,int id2);
    ArestaDuasPontas* removePrimeiraAresta();
    int getTamanho();
    bool vazia();

    bool existeAresta(int id,int id2);

private:
    ArestaDuasPontas* primeiro;
    ArestaDuasPontas* ultimo;
    int tamanho;
};

#endif //LISTAARESTADUASPONTAS_H
