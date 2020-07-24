#include "No.h"

No::No(int idNo, int pesoNo)
{
    this->id = idNo;
    this->peso = pesoNo;
    this->grauDeEntrada = 0;
    this->grauDeSaida = 0;

    this->prox = nullptr;
    this->cabeca = nullptr;
    this->cauda = nullptr;
}

No::~No()
{
    Aresta* t = this->cabeca;

    while(t != nullptr)
    {
        Aresta* aux = t;
        t = t->getProx();
        delete aux;
    }

    this->cabeca = this->cauda = nullptr;

    free(t);
    free(cabeca);
    free(cauda);
}

/**
    Getters
*/

int No::getPeso()
{
    return this->peso;
}

int No::getId()
{
    return this->id;
}

No* No::getProx()
{
    return this->prox;
}

Aresta* No::getAresta()
{
    return this->cabeca;
}

/**
    Setters
*/

void No::setProx(No* p)
{
    this->prox = p;
}

/**
    Funções Auxiliares de Grau
*/
void  No::aumentaDin()
{
    this->grauDeEntrada++;
}

void  No::diminuiDin()
{
    if(this->grauDeEntrada > 0)
        this->grauDeEntrada--;
}

void  No::aumentaDout()
{
    this->grauDeSaida++;
}

void  No::diminuiDout()
{
    if(this->grauDeSaida > 0)
        this->grauDeSaida--;
}

bool No::vazio()
{
    return this->cabeca == nullptr && this->cauda == nullptr;
}

Aresta* No::buscaAresta(int id)
{
    Aresta* t = this->cabeca;

    while(t != nullptr)
    {
        if(t->getNoAdj() == id)
            break;
        t = t->getProx();
    }

    return t;
}

bool No::inserirAresta(int id, int peso)
{
    if(this->buscaAresta(id) == nullptr)
    {
        Aresta* a = new Aresta(id,peso);

        if(this->vazio())
        {
            this->cabeca = this->cauda = a;
        } else {
            a->setProx(this->cabeca);
            this->cabeca = a;
        }

    } else
        return false;
}
