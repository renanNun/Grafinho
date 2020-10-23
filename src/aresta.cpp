#include "aresta.h"

/**
    Construtor da Classe Aresta
*/

Aresta::Aresta() {}

Aresta::Aresta(int id_alvo)
{
    this->id_alvo = id_alvo;
    this->prox = nullptr;
    this->peso = 0;
}

Aresta::Aresta(int no, float peso)
{
    this->id_alvo = no;
    this->peso = peso;
    this->prox = nullptr;
}

Aresta:: Aresta(int no, int noOrigem, float peso)
{
    this->id_alvo = no;
    this->peso = peso;
    this->id_Origem = noOrigem;
    this->prox = nullptr;
}


/**
    Destrutor da Classe Aresta
    Autor: Renan Nunes da Costa Gonçalves
*/
Aresta::~Aresta()
{
    if(this->prox != nullptr)
    {
        delete this->prox;
        this->prox = nullptr;
    }
}

/**
    Getters e Setters
    Autor: Renan Nunes da Costa Gonçalves
*/
int Aresta::getId_alvo()
{
    return this->id_alvo;
}

int Aresta::getId_Origem()
{
    return this->id_Origem;
}

Aresta* Aresta::getProxAresta()
{
    return this->prox;
}

float Aresta::getPeso()
{
    return this->peso;
}


void Aresta::setId_alvo(int novo_id_alvo)
{
    id_alvo=novo_id_alvo;
}

void Aresta::setId_origem(int novo_id_Origem)
{
    id_Origem=novo_id_Origem;
}


void Aresta::setProxAresta(Aresta* aresta)
{
    this->prox = aresta;
}

void Aresta::setPeso(float peso)
{
    this->peso = peso;
}
