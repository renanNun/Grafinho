#include "Prim.h"

Prim::Prim(Grafo *grafo)
{
    this->grafo = grafo;

}

Prim::~Prim() {}


void Prim::preencheLista()
{
    for(No* no = grafo->getPrimeiroNo(); no != nullptr; no->getProx())
    {
        for(Aresta* a = no->getPrimeiraAresta(); a != nullptr; a = a->getProxAresta())
        {
            ArestaDuasPontas* aux= new ArestaDuasPontas();
            aux->setPeso(a->getPeso());
            aux->setnoOrigem(no->getId());
            aux->setnoOrigem(a->getId());
            prim()->setProxAresta(aux);
        }
    }
}

void Prim::ordenar(ArestaDuasPontas **a,int n)
{
    int i, loc, j, k;
    ArestaDuasPontas *selected=NULL;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}

int Prim::binarySearch(ArestaDuasPontas **a, ArestaDuasPontas *item, int low, int high)
{
    if (high <= low)
    {
        return (item->getPeso() > a[low]->getPeso())?  (low + 1): low;
    }


    int mid = (low + high)/2;
    if(item->getPeso() == a[mid]->getPeso())
        return mid+1;

    if(item->getPeso() > a[mid]->getPeso())
        return binarySearch(a, item, mid+1, high);

    return binarySearch(a, item, low, mid-1);
}

ArestaDuasPontas** Prim::prim()
{
    No *noAtual=NULL;
    int aux;
    int tamSolucao=0;//conta o tamanho de primVet
    int cont=0;//conta o tamanho da lista de arestas adjacentes do noAtual
    noAtual=grafo->getListaNos();//nó atual de análise
    ArestaDuasPontas **primVet=new Aresta*[grafo->getOrdem()];//vetor de arestas de menor peso
    ArestaDuasPontas *arestaAdj=NULL;//lista de arestas adjacentes aos noAtuais, que são atualizados na interação
    ArestaDuasPontas **arestaVet=new Aresta*[grafo->getOrdem()];//auxilar para arestaAdj com o objetivo de ordenar
    //1º passo: transformar em um vetor de aresta
    //2º passo: pegar o vetor de arestas adjacentes e ordenar
    //3º passo: marcar o nó visitado
    //4º passo: pegar a primeira posiçãoo deste vetor
    //5º passo: atualizar o nó atual

    //desmarca os nós
    No *p = grafo->getListaNos();
    while(p != NULL)
    {
        p->desmarca();
        p = p->getProx();
    }

    while(noAtual->getMarca()==false&&tamSolucao<grafo->getOrdem()-1)
    {
        arestaAdj=noAtual->getAresta();//recebeu uma lista de arestas adjacentes
        for(Aresta *w=arestaAdj; w!=NULL; w=w->getProx())
        {
            if(tamSolucao==0) //primeira vez que for inserir no vetor de arestas adjacentes
            {
                arestaVet[cont]=new Aresta(w->getNoAdj(),w->getOrigem(),w->getPeso());
                cont++;
            }
            else //evitar a formação de ciclos
            {
                for(aux=0; aux<cont&&grafo->getNo(arestaVet[aux]->getNoAdj())!=grafo->getNo(w->getNoAdj()); aux++); //verificar se o nó adjacente da lista de arestaAdj já foi inserido como nó adjacente da solução primVet
                if(aux==cont) //percorreu e não encontrou no adjacente igual ao da arestaVet
                {
                    arestaVet[cont]=new Aresta(w->getNoAdj(),w->getOrigem(),w->getPeso());
                    cont++;
                }
                else
                {
                    if(arestaVet[aux]->getPeso()>w->getPeso()) //se uma aresta com o nó adjacente a um já pertencente ao vetor arestaVet tiver peso menor a aresta do vetor arestaVet, faço a substituição
                    {
                        arestaVet[aux]=new Aresta(w->getNoAdj(),w->getOrigem(),w->getPeso());
                    }
                }
            }
        }

        this->ordenar(arestaVet,cont);
        if(grafo->getNo(arestaVet[0]->getNoAdj())->getMarca()==true) //se a menor aresta já foi inserida, verifica a possibilidade de inserir até achar uma que ainda não tenha sido inserida, na lista de arestas de menor peso
        {
            for(aux=0; aux<tamSolucao && grafo->getNo(arestaVet[aux]->getNoAdj())->getMarca()==true; aux++);
            primVet[tamSolucao]=arestaVet[aux];
            tamSolucao++;
            noAtual->setMarca();
            noAtual=grafo->getNo(arestaVet[aux]->getNoAdj());
            for(int i=aux; i<cont-1; i++)
            {
                arestaVet[i]=arestaVet[i+1];
            }
            cont--;
        }
        else
        {
            primVet[tamSolucao]=arestaVet[0];
            tamSolucao++;
            noAtual->setMarca();
            noAtual=grafo->getNo(arestaVet[0]->getNoAdj());
            for(int i=0; i<cont-1; i++)
            {
                arestaVet[i]=arestaVet[i+1];
            }
            cont--;
        }

    }

    return primVet;
}

Grafo* Prim::gerar(float *soma)
{
    Grafo *h = new Grafo("", "", "", false, true); // Cria-se o grafo que irá receber as arestas encontradas por 'auxKruskal'.

    ArestaDuasPontas **listaPrim = prim();

    *soma = 0;
    for(int i = 0; i < grafo->getOrdem()-1; i++)   // Cria em 'h' as arestas com as mesmas características das presentes em 'arestasAGM'.
    {

        ArestaDuasPontas *w = listaPrim[i];
        //cout << w << " " << w->getNoAdj() << " " << w->getOrigem() << " " << w->getPeso() << endl;

        int origem = w->getOrigem();
        int fim = w->getNoAdj();
        float peso = w->getPeso();

        (*soma) += peso;

        h->setNo(origem);
        h->setNo(fim);
        h->setAresta(origem, fim, peso);
    }

    return h;
}


