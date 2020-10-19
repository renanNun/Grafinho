#include "dijkstra.h"
#define INFINITO 500000

Dijkstra::Dijkstra(Grafo* g,int no_inicial)
{
    this->graph = g;
    this->no_inicial = no_inicial;

    vertices = new int[graph->getOrdem()];
    distancias = new int[graph->getOrdem()];
    predecessores = new int[graph->getOrdem()];
    abertos = new int[graph->getOrdem()];

    algoritmo();
}

Dijkstra::~Dijkstra()
{
    delete [] vertices;
    delete [] distancias;
    delete [] predecessores;
    delete [] abertos;
}

void Dijkstra::iniciaIndices()
{
    No* no = graph->getPrimeiroNo();
    for(int i = 0; i < graph->getOrdem() && no != nullptr; i++)
    {
        no->i = i;
        no = no->getProx();
    }
}

void Dijkstra::algoritmo()
{
    No* p = this->graph->getPrimeiroNo();

    iniciaIndices();

    while(p != nullptr)
    {
        vertices[p->i] = p->getId();

        if(p->getId() == this->no_inicial)
        {
            distancias[p->i] = 0;
            predecessores[p->i] = p->getId();
        } else {
            distancias[p->i] = INFINITO;
            predecessores[p->i] = -1;
        }

        abertos[p->i] = -1;
        p = p->getProx();
    }

    p = graph->getPrimeiroNo();
    Aresta* adjacente;

    int numeroNosAbertos = graph->getOrdem();
    int indiceComMenorEstimativa;

    while(numeroNosAbertos > 0)
    {
        indiceComMenorEstimativa = buscaIndiceComMenorEstimativa(distancias,abertos,graph->getOrdem());

        if(abertos[indiceComMenorEstimativa] == -1)
        {
            abertos[indiceComMenorEstimativa] = 1;

            adjacente = graph->getNo(vertices[indiceComMenorEstimativa])->getPrimeiraAresta();

            while(adjacente != nullptr)
            {
                No* aux = graph->getNo(adjacente->getId());
                if(distancias[indiceComMenorEstimativa] + adjacente->getPeso() < distancias[aux->i])
                {
                    distancias[aux->i] = distancias[indiceComMenorEstimativa] + adjacente->getPeso();
                    predecessores[aux->i] = vertices[indiceComMenorEstimativa];
                }
                adjacente = adjacente->getProxAresta();
            }
        }
        numeroNosAbertos--;
    }

    cout << "DISTANCIAS MINIMAS DO VERTICE" << no_inicial << "PARA O RESTANTE DOS VERTICES DO GRAFO: " << endl;

    for(int i = 0; i < graph->getOrdem(); i++)
    {
        cout << " PARA O VERTICE: " << vertices[i] << " = " << distancias[i] << endl;
    }
}

int Dijkstra::buscaIndiceComMenorEstimativa(int* distancias, int* abertos,int tam)
{
    int menor;
    int indice = 0;

    for(int i = 0; i < tam; i++)
    {
        if(abertos[i] == -1)
            menor = distancias[i];
    }

    for(int i = 0; i < tam; i++)
    {
        if(abertos[i] == -1)
        {
            if(distancias[i] < menor)
            {
                menor = distancias[i];
                indice = i;
            }
        }
    }

    return indice;
}
