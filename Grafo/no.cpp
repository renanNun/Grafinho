#include "no.h"

No::No(int id)
{
    this->id = id;
    this->peso = 0;
    this->grau_entrada = 0;
    this->grau_saida = 0;
    this->primeira_aresta = nullptr;
    this->ultima_aresta = nullptr;
    this->prox = nullptr;
}

No::~No()
{
    Aresta* proxima_aresta = this->primeira_aresta;

    while(proxima_aresta != nullptr)
    {
        Aresta* aresta_auxiliar = proxima_aresta->getProxAresta();
        delete proxima_aresta;
        proxima_aresta = aresta_auxiliar;
    }
}

//Getters e Setters
Aresta* No::getPrimeiraAresta()
{
    return this->primeira_aresta;
}

Aresta* No::getUltimaAresta()
{
    return this->ultima_aresta;
}

int No::getId()
{
    return this->id;
}

int No::getGrauEntrada()
{
    return this->grau_entrada;
}

int No::getGrauSaida()
{
    return this->grau_saida;
}

float No::getPeso()
{
    return this->peso;
}

No* No::getProx()
{
    return this->prox;
}

void No::setProxNo(No* no)
{
    this->prox = no;
}

void No::setPeso(float peso)
{
    this->peso = peso;
}

//Outros métodos
void No::inserirAresta(int id_alvo,float peso)
{
    if(this->primeira_aresta != nullptr)
    {
        Aresta* aresta = new Aresta(id_alvo);
        aresta->setPeso(peso);
        this->ultima_aresta->setProxAresta(aresta);
        this->ultima_aresta = aresta;
    }
    else {
        this->primeira_aresta = new Aresta(id_alvo);
        this->primeira_aresta->setPeso(peso);
        this->ultima_aresta = this->primeira_aresta;
    }
}

void No::removerTodasArestas()
{
    if(this->primeira_aresta != nullptr)
    {
        Aresta* proxima = nullptr;
        Aresta*  aux = this->primeira_aresta;

        while(aux != nullptr)
        {
            proxima = aux->getProxAresta();
            delete aux;
        }
    }

    this->primeira_aresta = this->ultima_aresta = nullptr;
}

int No::removerAresta(int id,bool direcionado, No* no_alvo)
{
    if(this->buscaAresta(id))
    {
        Aresta* aux = this->primeira_aresta;
        Aresta* anterior = nullptr;

        while(aux->getId() != id)
        {
            anterior = aux;
            aux = aux->getProxAresta();
        }

        if(anterior != nullptr)
            anterior->setProxAresta(aux->getProxAresta());
        else
            this->primeira_aresta = aux->getProxAresta();

        if(aux == this->ultima_aresta)
            this->ultima_aresta = anterior;

        if(aux->getProxAresta() == this->ultima_aresta)
            this->ultima_aresta = aux->getProxAresta();

        delete aux;

        if(direcionado)
            this->diminuiGrauSaida();
        else{
            this->diminuiGrauEntrada();
            no_alvo->diminuiGrauEntrada();
        }

        return 1;
    }

    return 0;
}

bool No::buscaAresta(int id_alvo)
{
    if(this->primeira_aresta != nullptr)
    {
        for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
            if(aux->getId() == id_alvo)
                return true;
    }

    return false;
}

void No::aumentaGrauEntrada()
{
    this->grau_entrada++;
}

void No::diminuiGrauEntrada()
{
    if(this->grau_entrada > 0)
        this->grau_entrada--;
}

void No::aumentaGrauSaida()
{
    this->grau_saida++;
}

void No::diminuiGrauSaida()
{
    if(this->grau_saida > 0)
        this->grau_saida--;
}

Aresta* No::existeArestaEntre(int id_alvo)
{
    for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
        if(aux->getId() == id_alvo)
            return aux;
    return nullptr;
}
