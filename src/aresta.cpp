#include "aresta.h"

/**
    Construtor da Classe Aresta
    Autor: Renan Nunes da Costa Gonçalves
*/
Aresta::Aresta(int id_alvo)
{
    this->id_alvo = id_alvo;
    this->prox = nullptr;
    this->peso = 0;
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
int Aresta::getId(){
    return this->id_alvo;
}

Aresta* Aresta::getProxAresta(){
    return this->prox;
}

float Aresta::getPeso(){
    return this->peso;
}

void Aresta::setProxAresta(Aresta* aresta){
    this->prox = aresta;
}

void Aresta::setPeso(float peso){
    this->peso = peso;
}
