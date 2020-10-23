#include "Floyd.h"
#define INT_MAX 9999

Floyd::Floyd(Grafo* g,float** matrizAdj)
{
    this->n = g->getOrdem();
    A = new float*[n+1];
    B = new int*[n+1];

    for(int i = 0; i < n; i++)
    {
        A[i] = new float[n+1];
        B[i] = new int[n+1];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(matrizAdj[i][j] == -1)
                A[i][j] = INT_MAX;
            else
                A[i][j] = matrizAdj[i][j];
        }


    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }

    this->printSolucao(A);
}

Floyd::~Floyd()
{}


void Floyd::printSolucao(float** dist)
{
    for(int i = 0; i < n; i++)
    {
        cout << endl;
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INT_MAX)

                cout << "INFINITO";

            else
                cout << dist[i][j] << " ";
        }
    }
}
