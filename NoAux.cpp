#include "NoAux.h"

NoAux::NoAux(int id)
{
    this->id = id;
    this->prox = nullptr;
}

NoAux::~NoAux()
{
    //
}

int NoAux::getId()
{
    return this->id;
}

NoAux* NoAux::getProx()
{
    return this->prox;
}

void NoAux::setProx(NoAux* p)
{
    this->prox = p;
}
