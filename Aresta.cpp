#include "Aresta.h"

Aresta::Aresta(int idAdjacente,int pesoAresta)
{
    this->idNoAdjacente = idAdjacente;
    this->peso = pesoAresta;
    this->prox = nullptr;
}

Aresta::~Aresta()
{
    //dtor
}

int Aresta::getPeso()
{
    return this->peso;
}

int Aresta::getNoAdj()
{
    return this->idNoAdjacente;
}

Aresta* Aresta::getProx()
{
    return this->prox;
}

void Aresta::setProx(Aresta* a)
{
    this->prox = a;
}
