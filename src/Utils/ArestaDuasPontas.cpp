#include "Utils/ArestaDuasPontas.h"


ArestaDuasPontas::ArestaDuasPontas() {};

ArestaDuasPontas::~ArestaDuasPontas() {};

int ArestaDuasPontas::getnoOrigem()
{
    return this->noOrigem;
}

void ArestaDuasPontas::setnoOrigem(int id)
{
    this->noOrigem = id;
}

int ArestaDuasPontas::getnoAdj()
{
    return this->noAdj;
}

void ArestaDuasPontas::setnoAdj(int id)
{
    this->noAdj = id;
}

float ArestaDuasPontas::getPeso()
{
    return this->peso;
}

void ArestaDuasPontas::setPeso(float peso)
{
    this->peso = peso;
}

bool ArestaDuasPontas::getVistado()
{
    return this->visitado;
}

void ArestaDuasPontas::setVistado(bool x)
{
    this->visitado = x;
}

ArestaDuasPontas* ArestaDuasPontas::getProx()
{
    return this->prox;
}


void ArestaDuasPontas::setProx(ArestaDuasPontas* p)
{
    this->prox = p;
}
