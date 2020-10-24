#include "ListaAresta.h"

ListaAresta::ListaAresta()
{
    this->primeiro = nullptr;
    this->tamanho = 0;
}

ListaAresta::~ListaAresta()
{
    Aresta* aresta = this->primeiro;

    while(aresta != nullptr)
    {
        Aresta* aux = aresta->getProxAresta();
        delete aresta;
        aresta = aux;
    }

    free(aresta);
}

Aresta* ListaAresta::getPrimeiro()
{
    return this->primeiro;
}

void ListaAresta::insereAresta(int id_alvo,int id_origem,float peso)
{

    if(!existeAresta(id_alvo,id_origem))
    {
        if(this->primeiro == nullptr)
        {
            this->primeiro = new Aresta(id_alvo,id_origem,peso);
            this->primeiro->setProxAresta(nullptr);
            this->tamanho++;
        }
        else
        {
            Aresta* a = new Aresta(id_alvo,id_origem,peso);
            a->setProxAresta(this->primeiro);
            this->primeiro = a;
            this->tamanho++;
        }
    }

}
Aresta* ListaAresta::removeAresta(int id_alvo,int id_origem)
{

    Aresta* p = this->primeiro;
    Aresta* aux = nullptr;

    while(p != nullptr)
    {
        if((p->getId_alvo() == id_alvo && p->getId_Origem() == id_origem) || (p->getId_Origem() == id_alvo && p->getId_alvo() == id_origem))
            break;
        aux = p;
        p = p->getProxAresta();
    }

    if(p != nullptr)
    {
        if(aux == nullptr)
        {
            this->primeiro = this->primeiro->getProxAresta();
        }
        else
        {
            aux->setProxAresta(p->getProxAresta());
        }
        aux = p;
        delete p;
    }
    return aux;
}




int ListaAresta::getTamanho()
{
    return this->tamanho;
}
bool ListaAresta::vazia()
{
    if(this->primeiro == nullptr)
        return true;
    else
        return false;
}
void ListaAresta::imprime()
{
    cout << "SOLUCAO: " << endl;
    Aresta* p = this->primeiro;
    while(p != nullptr)
    {
        cout << p->getId_Origem() << " - " << p->getId_alvo() << "/" << p->getPeso() << endl;
        p = p->getProxAresta();
    }
}

bool ListaAresta::existeAresta(int id_alvo,int id_origem)
{
    for(Aresta* a = this->primeiro; a != nullptr; a = a->getProxAresta())
    {
        if((a->getId_alvo() == id_alvo || a->getId_alvo() == id_origem) && (a->getId_Origem() == id_alvo || a->getId_Origem() == id_origem))
        {
            return true;
            break;
        }
    }
    return false;
}
