#include "Grafo.h"

/**
    Construtor do Grafo
*/
Grafo::Grafo()
{
    this->ordem = 0;
    this->numArestas = 0;

    this->cabeca = nullptr;
    this->cauda = nullptr;
}

/**
    Destrutor do Grafo
*/
Grafo::~Grafo()
{
    No* t = this->cabeca;

    while(t != nullptr)
    {
        No* aux = t->getProx();
        delete t;
        t = aux;

    }

    this->cabeca = this->cauda = nullptr;
}

/**
    Função que carrega os parâmetros do Grafo
    @param: dir - representa se o Grafo é um Grafo Direcionado ou não
    @param: pondA - representa se o Grafo é Ponderado em suas Arestas
    @param: pondN - representa se o Grafo é ponderado em seus Nós
*/
void Grafo::carregarConfiguracoes(bool dir, bool pondA, bool pondN)
{
    this->direcionado = dir;
    this->ponderadoA = pondA;
    this->ponderadoN = pondN;
}

/**
    Getters
*/
int Grafo::getOrdem()
{
    return this->ordem;
}

int Grafo::getNumAretas()
{
    return this->numArestas;
}

/**
    Função responsável pela impressão do Grafo em forma de lista de Adjacência
*/
void Grafo::imprimirListaAdj()
{
    cout << "\tImpressão por Lista de Adjacência;" << endl;
    cout << "\tOrdem: " << getOrdem() << endl;
    cout << "\tNúmero de Arestas: " << getNumAretas() << endl;
    cout << endl;

    for(No* no = this->cabeca;  no != nullptr; no = no->getProx())
    {
        cout << no->getId();

        if(no->getAresta() != nullptr)
            cout << "--->";

        for(Aresta* a = no->getAresta(); a != nullptr; a = a->getProx())
        {
            if(a->getProx() != nullptr)
                cout << a->getNoAdj() << "--->";
            else
                cout << a->getNoAdj();
        }

        cout << endl;
    }
}

/**
    Função responsável pela pesquisa de determinado nó em um Grafo, ela retorna se eles está presente ou não
    @param: id - A informação contida no Nó
*/
bool Grafo::existeNo(int id)
{
    No* no = this->cabeca;

    while(no != nullptr)
    {
        if(no->getId() == id)
        {
            return true;
            break;
        }
        no = no->getProx();
    }

    return false;
}

/**
    Função que verifica a existência de um Nó no Grafo ou não, ela retorna o proprio nó ou nullptr caso ele nao exista
    @param: id - Informação contina no Nó
*/
No* Grafo::buscaNo(int id)
{
    No* no = this->cabeca;

    while(no != nullptr)
    {
        if(no->getId() == id)
        {
            return no;
            break;
        }
        no = no->getProx();
    }

    return nullptr;
}

/**
    Função responsável por inserir um Nó no Grafo, os Nós são inseridos em uma lista encadeada, essa função os insere no final da lista
    @param: id - Informação contida no Nó
    @param: peso - peso do No
*/
void Grafo::inserirNo(int id, int peso)
{
    if(!existeNo(id))
    {
        No* novo = new No(id,peso);

        if(this->cabeca == nullptr)
        {
            this->cabeca = novo;
            this->cauda = this->cabeca;
            this->ordem++;
        }
        else
        {
            cauda->setProx(novo);
            cauda = novo;
            novo->setProx(nullptr);
            this->ordem++;
        }
    } else {
        //cout << "Nó já inserido!" << endl;
        return;
    }
}

void Grafo::removerNo(int id)
{
    No* p = this->cabeca;

    if(p == nullptr)
    {
        cout << "GRAFO VAZIO" << endl;
        return;
    }

    if(this->cabeca->getId() == id)
    {
        this->cabeca = this->cabeca->getProx();
        delete p;
    } else
    {
        No* aux = p->getProx();

        while(aux != nullptr)
        {
            if(aux->getId() == id)
            {
                break;
            } else
            {
                p = aux;
                aux = aux->getProx();
            }
        }

        if(this->cauda != nullptr)
        {
            if(this->cauda == aux)
            {
                this->cauda = p;
            }
            p->setProx(aux->getProx());
            delete aux;
        }
    }
    removeAdjacencias(id);
}


void Grafo::removeAdjacencias(int id)
{
    No* p = this->cabeca;

    while (p != nullptr)
    {
        p->removerAresta(id);
        p = p->getProx();
    }
}

/**
    Função responsável por inserir as Arestas entre os Nós
    @param: idOrigem - O Nó de origem da aresta
    @param: idDestino - O Nó de destino da aresta
    @param: peso - o Custo da aresta
*/
void Grafo::inserirAresta(int idOrigem, int idDestino, int peso)
{
    No* origem = buscaNo(idOrigem);
    No* destino = buscaNo(idDestino);

    if(origem != nullptr && destino != nullptr)
    {
        if(this->direcionado)
        {
            origem->inserirAresta(idDestino,peso);
            this->numArestas++;
        } else {
            origem->inserirAresta(idDestino,peso);
            destino->inserirAresta(idOrigem,peso);
            this->numArestas++;
        }
    } else {
        cout << "Nó não existe! " << endl << endl;
        return;
    }
}

/**
    Função responsável por remover Arestas
    @param: idOrigem - O no de onde parte a aresta
    @param: idDestino - O no onde a aresta se direciona
*/
void Grafo::removerAresta(int idOrigem, int idDestino)
{
    if(!existeNo(idOrigem) && existeNo(idDestino))
    {
        cout << "\nIDs Inválidos!" << endl;
        return;
    }

    No* origem = buscaNo(idOrigem);
    No* destino = buscaNo(idDestino);

    if(origem != nullptr && destino != nullptr)
    {
        origem->removerAresta(destino->getId());
        destino->removerAresta(origem->getId());
        this->numArestas--;
    }
}

/**
    Métodos para representação do Grafo em Matriz de Adjacência
*/
/**
    Retorna a Matriz de Adjacência de um Grafo
*/
int** Grafo::getMatrizAdj()
{
    int** matrizAdj;
    int n = this->ordem;
    int origem, destino;

    /*INICIANDO A MATRIZ*/
    matrizAdj = new int* [n];
    for(int i = 0; i < n; i++)
    {
        matrizAdj[i] = new int[n];
        for(int j = 0; j < n; j++)
            matrizAdj[i][j] = -1;
    }

    /*Preenchendo a Matriz com o peso das arestas*/
    for(No* no = this->cabeca; no != nullptr ; no = no->getProx())
    {
        origem = getPosicaoMatriz(no->getId());

        for(Aresta* a = no->getAresta(); a != nullptr; a = a->getProx())
        {
            destino = this->getPosicaoMatriz(a->getNoAdj());
            matrizAdj[origem][destino] = a->getPeso();
        }
    }
    return matrizAdj;
}

/**
    Retorna a posição de determinado Nó na matriz
    @param: id - informação contida no Nó
*/
int Grafo::getPosicaoMatriz(int id)
{
    int c = 0;
    for(No* no = this->cabeca; no != nullptr; no = no->getProx())
    {
        if(no->getId() == id)
        {
            return c;
        }
        c++;
    }

    return -1;
}
