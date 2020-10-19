#include "Floyd.h"
#define infinito=999999

Floyd::Floyd(Grafo * G)
{
    if(G->getPonderadoAresta())
    {
        ordem= G->getOrdem();

        int dist [ordem][ordem];
        for (int i = 0; i < ordem; i++)
            for (int j = 0; j < ordem; j++)
            {
                if(G->getNo(i)->existeArestaEntreBool(j))
                {
                    Aresta* aresta= G->getNo(i)->existeArestaEntre(j);
                    dist[i][j] = aresta->getPeso();
                }

                else
                    dist[i][j]=infinito;
            }

        for (int k = 0; k < ordem; k++)
        {

            for (i = 0; i < ordem; i++)
            {
                /
                for (j = 0; j < ordem; j++)
                {

                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        imprimirMatrizSolucao(dist);
    }
    else
    {
        cout<< "O algoritmo de Floyd precisa de um grafo com arestas direcionados para ser executado";

    }

}

Floyd::imprimirMatrizSolucao(int dist[][ordem])
{


    cout<<"Following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (dist[i][j] == infinito)
                cout<<"%7s"<< "Infinito";
            else
                cout<<"%7d"<< dist[i][j];
        }
        cout<<"\n";
    }


}
