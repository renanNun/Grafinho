#include "PilhaEncadeada.h"

PilhaEncadeada::PilhaEncadeada()
{
    this->topo = nullptr;
    this->tam = 0;
}

PilhaEncadeada::~PilhaEncadeada()
{
    NoAux* v = this->topo;
    while(this->topo != nullptr)
    {
        this->topo = v->getProx();
        delete v;
        this->tam--;
        v = this->topo;
    }
}

int PilhaEncadeada::getTopo()
{
    if(!vazia())
        return this->topo->getId();
    else
    {
        //cout << "PILHA VAZIA!" << endl;
        exit(-4);
    }
}

int PilhaEncadeada::tamanho()
{
    return this->tam;
}

bool PilhaEncadeada::vazia()
{
    return this->topo == nullptr;
}

void PilhaEncadeada::empilha(int id)
{
    NoAux* n = new NoAux(id);
    n->setProx(this->topo);
    this->topo = n;
    this->tam++;
}

int PilhaEncadeada::desempilha()
{
    NoAux* n;
    if(this->topo != nullptr)
    {
        n = this->topo;
        this->topo = n->getProx();
        int info = n->getId();
        delete n;
        this->tam--;
        return info;
    } else {
        exit(-4);
    }
}
