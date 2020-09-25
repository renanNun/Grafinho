#include "grafo.h"

Grafo::Grafo(int ordem, bool direcionado,bool ponderado_aresta,bool ponderado_no)
{
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderado_aresta = ponderado_aresta;
    this->ponderado_no = ponderado_no;
    this->primeiro_no = this->ultimo_no = nullptr;
    this->numero_arestas = 0;
}

Grafo::~Grafo()
{
    No* prox_no = this->primeiro_no;

    while(prox_no != nullptr)
    {
        prox_no->removerTodasArestas();
        No* aux = prox_no->getProx();
        delete prox_no;
        prox_no = aux;
    }
}

//Getters
int Grafo::getOrdem()
{
    return this->ordem;
}

int Grafo::getNumeroArestas()
{
    return this->numero_arestas;
}

bool Grafo::getDirecionado()
{
    return this->direcionado;
}

bool Grafo::getPonderadoAresta()
{
    return this->ponderado_aresta;
}

bool Grafo::getPonderadoNo()
{
    return this->ponderado_no;
}

No* Grafo::getPrimeiroNo()
{
    return this->primeiro_no;
}

No* Grafo::getUltimoNo()
{
    return this->ultimo_no;
}

//Outros Métodos
void Grafo::aumentaNumArestas()
{
    this->numero_arestas++;
}

void Grafo::diminuiNumArestas()
{
    if(this->numero_arestas > 0)
        this->numero_arestas--;
}

No* Grafo::getNo(int id)
{
    if(this->primeiro_no != nullptr)
    {
        for(No* aux = this->primeiro_no; aux != nullptr; aux = aux->getProx())
                if(aux->getId() == id)
                    return aux;
    }

    return nullptr;
}

bool Grafo::existeNo(int id)
{
    if(this->primeiro_no != nullptr)
    {
        for(No* aux = this->primeiro_no; aux != nullptr; aux = aux->getProx())
                if(aux->getId() == id)
                    return true;
    }

    return false;
}

void Grafo::inserirNo(int id)
{
    if(!existeNo(id))
    {
        if(this->primeiro_no != nullptr)
        {
            No* no = new No(id);
            this->ultimo_no->setProxNo(no);
            this->ultimo_no = no;
        } else {
            this->primeiro_no = new No(id);
            this->ultimo_no = this->primeiro_no;
        }
    }
}

void Grafo::removerNo(int id)
{
    if(existeNo(id))
    {
        if(this->primeiro_no->getId() == id)
        {
            No* aux = this->primeiro_no;
            this->primeiro_no = this->primeiro_no->getProx();
            delete aux;
        } else {

            No* anterior;
            No* aux = this->primeiro_no;

            while(aux != nullptr)
            {
                if(aux->getId() == id)
                {
                    break;
                }

                anterior = aux;
                aux = aux->getProx();
            }

            if(this->ultimo_no == aux)
            {
                this->ultimo_no = anterior;
            }

            anterior->setProxNo(aux->getProx());

            No* p = this->primeiro_no;
            while(p != nullptr)
            {
                    p->removerAresta(id,direcionado,p);
            }

            delete aux;
        }
    }
}


void Grafo::inserirAresta(int id,int id_alvo,float peso)
{
    if(!existeNo(id))
        this->inserirNo(id);

    if(!existeNo(id_alvo))
        this->inserirNo(id);

    if(this->direcionado)
    {
        No* no = getNo(id);
        No* no_alvo = getNo(id_alvo);
        no->inserirAresta(id_alvo,peso);
        no->aumentaGrauSaida();
        no_alvo->aumentaGrauEntrada();
    } else {
        No* no = getNo(id);
        no->inserirAresta(id_alvo,peso);
        no->aumentaGrauEntrada();
    }
}

//Luan
int Grafo::grauMedioPorSomatorio()
{
    if(this->ordem != 0)
    {
        No* percorreGrafo = this->primeiro_no;
        float somatorioGraus = 0;

        while(percorreGrafo->getProx() != nullptr)
        {
            somatorioGraus += percorreGrafo->getPeso();
            percorreGrafo = percorreGrafo->getProx();
        }

        int grauMedio = (1.0/this->ordem) * somatorioGraus;
        return grauMedio;
    } else {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

//Luan
int Grafo::grauMedioPorAdjacencia()
{
    if(this->ordem != 0)
    {
        int grauMedio = (2) * (this->ordem/this->numero_arestas);
        return grauMedio;
    } else {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

//IMPRESSÃO
void Grafo::imprimir()
{
    cout << endl << "IMPRESSAO POR LISTA DE ADJACENCIA" << endl;
    cout << "\t\t ORDEM: " << this->ordem << endl;
    cout << "\t\t NUMERO DE ARESTAS: " << this->numero_arestas << endl;
    cout << "\t\t GRAU MEDIO DO GRAFO: " << this->grauMedioPorAdjacencia() << endl;
    cout << endl;

    for(No* no = this->primeiro_no; no != nullptr; no = no->getProx())
    {
        cout << no->getId();

        if(no->getPrimeiraAresta() != nullptr)
            cout << "--->";

        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProxAresta())
        {
            if(this->ponderado_aresta)
            {
                if(aresta->getProxAresta() != nullptr)
                    cout << aresta->getId() << "(" << aresta->getPeso() << ")--->";
                else
                    cout << aresta->getId();
            } else
            {
               if(aresta->getProxAresta() != nullptr)
                    cout << aresta->getId() << "--->";
               else
                    cout << aresta->getId();
            }
        }

        cout << endl;
    }
}
