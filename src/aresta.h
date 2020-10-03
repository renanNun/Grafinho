#ifndef ARESTA_H
#define ARESTA_H

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Renan Nunes da Costa Gonçalves
*   versão: 1.0
*/
class Aresta
{
    public:
        Aresta(int id_alvo);
        virtual ~Aresta();

        int getId();
        Aresta* getProxAresta();
        float getPeso();

        void setProxAresta(Aresta* aresta);
        void setPeso(float peso);

    private:
        int id_alvo;
        Aresta* prox;
        float peso;
};

#endif // ARESTA_H
