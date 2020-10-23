#include "Prim.h"

void Prim::ordenar(Aresta **a,int n)
{
    int i, loc, j, k;
    Aresta *selected=NULL;

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

int Prim::binarySearch(Aresta **a, Aresta *item, int low, int high)
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

Grafo * Prim::gerar(float *soma)
{
    Grafo *h = new Grafo(NULL,false,true,false); // Cria-se o grafo que irá receber as arestas encontradas por 'auxKruskal'.

    Aresta **listaPrim = prim();

    *soma = 0;
    for(int i = 0; i < grafo->getOrdem()-1; i++)   // Cria em 'h' as arestas com as mesmas características das presentes em 'arestasAGM'.
    {

        Aresta *w = listaPrim[i];
        //cout << w << " " << w->getNoAdj() << " " << w->getOrigem() << " " << w->getPeso() << endl;

        int origem = w->getId_Origem();
        int fim = w->getId_alvo();
        float peso = w->getPeso();

        (*soma) += peso;

        h->inserirNo(origem);
        h->inserirNo(fim);
        h->inserirAresta(origem, fim, peso);
    }

    return h;
}


 Aresta** Prim::prim(){
            No *noAtual=NULL;
            int aux;
            int tamSolucao=0;
            int cont=0;
            noAtual=grafo->getListaNos();
            Aresta **primVet=new Aresta*[grafo->getOrdem()];
            Aresta *arestaAdj=NULL;
            Aresta **arestaVet=new Aresta*[grafo->getOrdem()];

            No *p = grafo->getListaNos();
            while(p != NULL){
                p->desmarca();
                p = p->getProx();
            }

            while(noAtual->getMarca()==false&&tamSolucao<grafo->getOrdem()-1){
                arestaAdj=noAtual->getAresta();//recebeu uma lista de arestas adjacentes
                for(Aresta *w=arestaAdj;w!=NULL;w=w->getProxAresta()){
                    if(tamSolucao==0){//primeira vez que for inserir no vetor de arestas adjacentes
                        arestaVet[cont]=new Aresta(w->getId_alvo(),w->getId_Origem(),w->getPeso());
                        cont++;
                    }
                    else{//evitar a formação de ciclos
                        for(aux=0;aux<cont&&grafo->getNo(arestaVet[aux]->getId_alvo())!=grafo->getNo(w->getId_alvo());aux++);//verificar se o nó adjacente da lista de arestaAdj já foi inserido como nó adjacente da solução primVet
                        if(aux==cont){//percorreu e não encontrou no adjacente igual ao da arestaVet
                            arestaVet[cont]=new Aresta(w->getId_alvo(),w->getId_Origem(),w->getPeso());
                            cont++;
                        }
                        else{
                            if(arestaVet[aux]->getPeso()>w->getPeso()){//se uma aresta com o nó adjacente a um já pertencente ao vetor arestaVet tiver peso menor a aresta do vetor arestaVet, faço a substituição
                                arestaVet[aux]=new Aresta(w->getId_alvo(),w->getId_Origem(),w->getPeso());
                            }
                        }
                    }
                }

                this->ordenar(arestaVet,cont);
                if(grafo->getNo(arestaVet[0]->getId_alvo())->getMarca()==true){//se a menor aresta já foi inserida, verifica a possibilidade de inserir até achar uma que ainda não tenha sido inserida, na lista de arestas de menor peso
                    for(aux=0;aux<tamSolucao && grafo->getNo(arestaVet[aux]->getId_alvo())->getMarca()==true;aux++);
                    primVet[tamSolucao]=arestaVet[aux];
                    tamSolucao++;
                    noAtual->setMarca();
                    noAtual=grafo->getNo(arestaVet[aux]->getId_alvo());
                    for(int i=aux;i<cont-1;i++){
                        arestaVet[i]=arestaVet[i+1];
                    }
                    cont--;
                }
                else{
                    primVet[tamSolucao]=arestaVet[0];
                    tamSolucao++;
                    noAtual->setMarca();
                    noAtual=grafo->getNo(arestaVet[0]->getId_alvo());
                    for(int i=0;i<cont-1;i++){
                        arestaVet[i]=arestaVet[i+1];
                    }
                    cont--;
                }

            }

            return primVet;
        }
