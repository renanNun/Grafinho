#include "Floyd.h"
#define INFINITO 999

Floyd::Floyd(Grafo * G)
{
    if(G->getPonderadoAresta())
    {
        ordem= G->getOrdem();

        int dist [ordem][ordem];

        No* head=G->getPrimeiroNo();

        for(int i=0; i<ordem; i++)
        {
            head->i=i;
        }

        for (int i = 0; i < ordem; i++)
            for (int j = 0; j < ordem; j++)
            {
                if(G->getNoInt(i)->existeArestaEntreBool(j))
                {
                    Aresta* aresta= G->getNoInt(i)->existeArestaEntre(j);
                    dist[i][j] = aresta->getPeso();
                }
                else
                    dist[i][j]=INFINITO;
            }

        for (int k = 0; k < ordem; k++)
        {

            for (int i = 0; i < ordem; i++)
            {

                for (int j = 0; j < ordem; j++)
                {

                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        cout<<"Following matrix shows the shortest distances between every pair of vertices \n";
        for (int i = 0; i < ordem; i++)
        {
            for (int j = 0; j < ordem; j++)
            {
                if (dist[i][j] == INFINITO)
                    cout<<"%7s"<< "Infinito";
                else
                    cout<<"%7d"<< dist[i][j];
            }
            cout<<"\n";
        }



    }
    else
    {
        cout<< "O algoritmo de Floyd precisa de um grafo com arestas direcionados para ser executado";

    }

}

