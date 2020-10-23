#include "ComponentesConexas.h"

ComponentesConexas::ComponentesConexas(Grafo* grafo)
{
    this->grafo = grafo;
}
ComponentesConexas:: ~ComponentesConexas() {}


void  ComponentesConexas::buscaProfCompConexa(int *indComp, int i, int numComp, int *idNos)
{
    {

        indComp[i] = numComp;
        No *n = grafo->getNo(idNos[i]);


        for(Aresta *a = n->getAresta(); a != nullptr; a = a->getProxAresta())
        {
            i = encontraIndice(idNos, a->getId_alvo());
            if(indComp[i] == -1)
            {
                buscaProfCompConexa(indComp, i, numComp, idNos);
            }
        }
    }
}

int  ComponentesConexas::encontraIndice(int *idNos, int id)
{
    int i;
    for(i = 0; i < grafo->getOrdem(); i++)
    {
        if(idNos[i] == id)
        {
            break;
        }
    }
    return i;
}


void ComponentesConexas::vetorIdNos(int* idNos)
{
    No *n;
    int i;
    for(n = grafo->getPrimeiroNo(), i = 0; n != nullptr; n = n->getProx(), i++)
    {
        idNos[i] = n->getId();
    }

}

int ComponentesConexas::componenteConexa(int* indComp, int* idNos)
{
    vetorIdNos(idNos);
    if(grafo->getDirecionado()== false)
    {
        int numComp = 0;
        for(int i = 0; i < grafo->getOrdem(); i++)
        {
            indComp[i] = -1;
        }
        for(int i = 0; i < grafo->getOrdem(); i++)
        {
            if(indComp[i] == -1)
            {
                buscaProfCompConexa(indComp, i, numComp++, idNos);
            }
        }

        return numComp;
    }

    return -1;
}
