#include "no.h"

/**
    Construtor da Classe No.h
    @param: id - informa��o contida no n�
    autor: Renan Nunes da Costa Gon�alves
*/
No::No(int id)
{
    this->id = id;
    this->peso = 0;
    this->grau_entrada = 0;
    this->grau_saida = 0;
    this->primeira_aresta = nullptr;
    this->ultima_aresta = nullptr;
    this->prox = nullptr;
    this->marca=false;
}

/**
    Destrutor da classe No.h
    autor: Renan Nunes da Costa Gon�alves
*/
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

void No::setId (int Newid)
{
    this->id=Newid;
}

//Outros m�todos
/**
    M�todo que insere uma aresta no No
    @param: id_alvo - No que possui um caminho
    @param: peso - custo do caminho
    autor: Renan Nunes da Costa Gon�alves
*/
void No::inserirAresta(int id_alvo,float peso)
{
    if(this->primeira_aresta != nullptr)
    {
        Aresta* aresta = new Aresta(id_alvo);
        aresta->setPeso(peso);
        this->ultima_aresta->setProxAresta(aresta);
        this->ultima_aresta = aresta;
    }
    else
    {
        this->primeira_aresta = new Aresta(id_alvo);
        this->primeira_aresta->setPeso(peso);
        this->ultima_aresta = this->primeira_aresta;
    }
}

/**
    M�todo respons�vel por remover todas as arestas de um n�
    autor: Renan Nunes da Costa Gon�alves
*/
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

/**
    M�todo resons�vel por remover uma aresta da lista de n�s
    @param: id - informa��o contida no n�
    @param: direcionado - se o grafo � direcionado ou n�o
    @param: no_alvo - o N� para qual aresta se direcionado
    autor: Renan Nunes da Costa Gon�alves
*/
int No::removerAresta(int id,bool direcionado, No* no_alvo)
{
    if(this->buscaAresta(id))
    {
        Aresta* aux = this->primeira_aresta;
        Aresta* anterior = nullptr;

        while(aux->getId_alvo() != id)
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
        else
        {
            this->diminuiGrauEntrada();
            no_alvo->diminuiGrauEntrada();
        }

        return 1;
    }

    return 0;
}

/**
    busca uma �nica aresta
    @param: id_alvo - id do n� para qual a aresta se direciona
    autor: Renan Nunes da Costa Gon�alves
*/
bool No::buscaAresta(int id_alvo)
{
    if(this->primeira_aresta != nullptr)
    {
        for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
            if(aux->getId_alvo() == id_alvo)
                return true;
    }

    return false;
}

/**
    Fun��o que aumenta o Grau de Entrada
    autor: Renan Nunes da Costa Gon�alves
*/
void No::aumentaGrauEntrada()
{
    this->grau_entrada++;
}

/**
    Fun��o que diminui o Grau de Entrada
    autor: Renan Nunes da Costa Gon�alves
*/
void No::diminuiGrauEntrada()
{
    if(this->grau_entrada > 0)
        this->grau_entrada--;
}

/**
   Fun��o que aumenta o Grau de Saida
   autor: Renan Nunes da Costa Gon�alves
*/
void No::aumentaGrauSaida()
{
    this->grau_saida++;
}

/**
    Fun��o que diminui o Grau de Saida
    autor: Renan Nunes da Costa Gon�alves
*/
void No::diminuiGrauSaida()
{
    if(this->grau_saida > 0)
        this->grau_saida--;
}

/**
    Fun��o que verifica a existencia de uma aresta entre n�s e retorna o n�
    @param: id_alvo - informa��o do n� alvo
    autor: Renan Nunes da Costa Gon�alves
*/
Aresta* No::existeArestaEntre(int id_alvo)
{
    for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
        if(aux->getId_alvo() == id_alvo)
            return aux;
    return nullptr;
}

/**
    Fun��o que verifica a existencia de uma aresta entre n�s e retorna verdadeiro ou falso
    @param: id_alvo - informa��o do n� alvo
    autor: Renan Nunes da Costa Gon�alves
*/
bool No::existeArestaEntreBool(int id_alvo)
{
    for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
        if(aux->getId_alvo() == id_alvo)
            return true;
    return false;
}


// Fun��es Prim

bool No::getMarca()
{
    return marca;
}
void No::setMarca()
{
    marca=true;
}
void No::desmarca()
{
    marca=false;
}

Aresta* No::getAresta()
{
    for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
        return aux;
    return nullptr;
}
