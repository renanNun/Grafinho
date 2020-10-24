#include "Kruskal.h"

Kruskal::Kruskal(Grafo* grafo)
{
    this->grafo = grafo;
    this->listaDeArestas = new ListaAresta();

    kruskal();
}

void Kruskal::kruskal()
{
    int v = this->grafo->getOrdem();
    int m = this->grafo->getNumeroArestas();
    Aresta* resultado = new Aresta[v];
    int e = 0;
    int i = 0;

    /*PREENCHENDO LISTA DE ARESTAS*/
    for(No* no = grafo->getPrimeiroNo(); no != nullptr; no = no->getProx())
    {
        for(Aresta* a = no->getPrimeiraAresta(); a != nullptr; a = a->getProxAresta())
            listaDeArestas->insereAresta(no->getId(),a->getId_alvo(),a->getPeso());
    }
    cout << "KRUSKAL" << endl;
    quickSort(0,m);
}

float Kruskal::comparacao(Aresta* a,Aresta* b)
{
    return a->getPeso() > b->getPeso();
}

void Kruskal::quickSort(int inicio, int fim)
{
    Aresta vetorDeArestas[listaDeArestas->getTamanho()];
    int cont = listaDeArestas->getTamanho();

    Aresta* a = listaDeArestas->getPrimeiro();
    for(int i = 0; i < cont && a != nullptr; i++)
    {
        Aresta* aux = a;
        if(aux != nullptr)
            vetorDeArestas[i] = *aux;
        a = a->getProxAresta();
    }

    auxQuickSort(vetorDeArestas,inicio,fim);
    cout << "SEM CONDICAO DE PARADA" << endl;
    for(int i = 0; i < cont; i++)
        cout << " " << vetorDeArestas[i].getPeso();
}

void Kruskal::auxQuickSort(Aresta vetor[],int inicio,int fim)
{
    int i,j;
    float pivo;
    Aresta aux;

    i = inicio;
    j = fim-1;

    pivo = vetor[(inicio + fim) / 2].getPeso();
    //cout << "PIRVO " << pivo << endl;
    while(i <= j)
    {
        while(vetor[i].getPeso() < pivo && i < fim)
        {
            i++;
        }
        while(vetor[j].getPeso() > pivo && j > inicio)
        {
            j--;
        }

        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }

    if(j > inicio)
    {
        auxQuickSort(vetor,inicio,j+1);
        cout << "J > INICIO" << endl;
    }
    if(i < fim)
    {
        auxQuickSort(vetor,i,fim);
        cout << "I < FIM" << endl;
    }

}

/*
Kruskal::Kruskal(Grafo *grafo)
{
    this->grafo = grafo;
    listaDeArestas = new ListaAresta();
    this->numeroDeNos = grafo->getOrdem();
    parent = new No[numeroDeNos];
    No* no = grafo->getPrimeiroNo();

    for(int i = 0; i < numeroDeNos && no != nullptr; i++)
    {
        no->i = i;
        parent[i] = no->getId();
        no = no->getProx();
    }

    algoritmo();
}

Kruskal:: ~Kruskal() {
    delete parent;
    delete listaDeArestas;
}

void Kruskal::quickSort(ListaAresta* vetor,int inicio, int fim, int tam)
{
    Aresta vetorAuxiliar[tam];

    int cont = tam;

    Aresta* aresta = vetor->getPrimeiro();

    for(int i = 0; i < cont; i++)
    {
        Aresta* auxiliar = aresta;
        if(auxiliar != nullptr)
            vetorAuxiliar[i] = *auxiliar;
        aresta = aresta->getProxAresta();
    }

    cout << "ANTES DO AUXILIAR" << endl;
    //auxiliarQuickSort(vetorAuxiliar,inicio,fim);
    cout << "APOIS O AUXILIAR" << endl;
    ListaAresta* listaX =  new ListaAresta();

    for(int i = (cont-1); i >=0; i--)
    {
        Aresta* aux = &vetorAuxiliar[i];
        listaX->insereAresta(aux->getId_alvo(),aux->getId_Origem(),aux->getPeso());
        vetor->removeAresta(aux->getId_alvo(),aux->getId_Origem());
    }

    Aresta* y = listaX->getPrimeiro();
    ListaAresta* listaY = new ListaAresta();
    cout << "Y" << endl;
    while(y != nullptr)
    {
        listaY->insereAresta(y->getId_alvo(),y->getId_Origem(),y->getPeso());
        y = y->getProxAresta();
    }
    listaY->imprime();
    Aresta* z = listaY->getPrimeiro();

    while(z != nullptr)
    {
        vetor->insereAresta(z->getId_alvo(),z->getId_Origem(),z->getPeso());
        z = z->getProxAresta();
    }

    delete listaX;
    delete listaY;
}

void Kruskal::auxiliarQuickSort(Aresta* vetor,int inicio,int fim)
{
    int i,j;
    float pivo;
    Aresta aux;

    i = inicio;
    j = fim-1;

    pivo = vetor[(inicio + fim) / 2].getPeso();

    while(i <= j)
    {
        while(vetor[i].getPeso() < pivo && i < fim)
            i++;
        while(vetor[j].getPeso() > pivo && j > inicio)
            j--;

        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    cout << "APOS O WHILE" << endl;
    if(j > inicio)
        auxiliarQuickSort(vetor,inicio,j+1);
    if(i < fim)
        auxiliarQuickSort(vetor,i,fim);
}

void Kruskal::algoritmo()
{
    //Primeiro Iniciamos a lista de arestas
    for(No* no = grafo->getPrimeiroNo(); no != nullptr; no = no->getProx())
    {
        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProxAresta())
        {
            listaDeArestas->insereAresta(aresta->getId_alvo(),no->getId(),aresta->getPeso());
        }
    }
    //listaDeArestas->imprime();
    /*MUDAR PARENT PARA NO E DEVE FUNCIONAR*/
/*quickSort(listaDeArestas,0,numeroDeNos,listaDeArestas->getTamanho());
//cout << "QUICKSORT" << endl;
//listaDeArestas->imprime();
float custo = 0;

int x;
int y;
Aresta* aresta;
while(!listaDeArestas->vazia())
{
    aresta = listaDeArestas->getPrimeiro();
    listaDeArestas->removeAresta(aresta->getId_alvo(),aresta->getId_Origem());

    x = find_set(aresta->getId_Origem());
    y = find_set(aresta->getId_alvo());

    if(x != y)
    {
        cout << aresta->getId_Origem() << "-" << aresta->getId_alvo() << ":" <<aresta->getPeso() << endl;
        custo += aresta->getPeso();
        union_set(aresta->getId_Origem(),aresta->getId_alvo());
    }
}

cout << "O CUSTO É " << custo << endl;

}

int Kruskal::find_set(int i)
{
if(i == parent[retornaIndices(i)].getId())
    return i;
else
    return find_set(parent[retornaIndices(i)].getId());
}

void Kruskal::union_set(int u,int v)
{
parent[retornaIndices(u)] = parent[retornaIndices(v)];
}

int Kruskal::retornaIndices(int i)
{
No* no = this->grafo->getPrimeiroNo();
for(int j = 0; j < numeroDeNos && no != nullptr; j++)
{
    if(i == no->getId())
        return no->i;
    no = no->getProx();
}
return -1;
}*/
