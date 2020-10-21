#include "ListaArestasDuasPontas.h"

ListaArestaDuasPontas::ListaArestaDuasPontas()
{
    this->tamanho = 0;
    this->primeiro = nullptr;
}

ListaArestaDuasPontas::~ListaArestaDuasPontas()
{
    ArestaDuasPontas* a = this->primeiro;

    while (a != nullptr)
    {
        ArestaDuasPontas* aux = a->getProx();
        delete a;
        a = aux;
    }
}

ArestaDuasPontas* ListaArestaDuasPontas::getPrimeiro()
{
    return this->primeiro;
}

void ListaArestaDuasPontas::insereAresta(int id,int id2, float peso)
{

    if(!existeAresta(id,id2))
    {
        ArestaDuasPontas* p = this->primeiro;
        ArestaDuasPontas* a = new ArestaDuasPontas();

        a->setnoOrigem(id);
        a->setnoAdj(id2);
        a->setPeso(peso);

        if(p == nullptr)
        {
            this->primeiro = a;
            a->setProx(nullptr);
            tamanho++;
        }
        else
        {
            this->primeiro = a;
            a->setProx(p);
            tamanho++;
        }
    } else {

        return;
    }

}

ArestaDuasPontas* ListaArestaDuasPontas::removeAresta(int id,int id2)
{
    ArestaDuasPontas* p = this->primeiro;
    ArestaDuasPontas* aux = nullptr;

    while(p!=nullptr)
    {

        if((p->getnoOrigem() == id && p->getnoAdj() == id2) || (p->getnoOrigem() == id2 && p->getnoAdj() == id))
        {
            break;
        }
        aux = p;
        p = p->getProx();
    }

    if(p != nullptr)
    {

        aux->setProx(p->getProx());

        delete p;
        tamanho--;
    }


}

int ListaArestaDuasPontas::getTamanho()
{
    return this->tamanho;
}

bool ListaArestaDuasPontas::vazia()
{
    if (this->primeiro == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ArestaDuasPontas* ListaArestaDuasPontas::removePrimeiraAresta()
{

    ArestaDuasPontas* p = this->primeiro;

    if(p!= nullptr)
    {
        this->primeiro = p->getProx();
        delete p;
        tamanho--;
    }

}

bool ListaArestaDuasPontas::existeAresta(int id,int id2)
{
    for(ArestaDuasPontas* aresta = this->primeiro; aresta != nullptr; aresta = aresta->getProx())
    {
        if(aresta->getnoOrigem() == id && aresta->getnoAdj() == id2 || aresta->getnoOrigem() == id2 && aresta->getnoAdj() == id)
        {
            break;
            return true;
        }
    }
    return false;
}
