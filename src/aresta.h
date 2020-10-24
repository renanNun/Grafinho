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
    Aresta();
    Aresta(int id_alvo);
    Aresta(int no, float peso);
    Aresta(int no, int noOrigem, float peso);

    virtual ~Aresta();

    int getId_alvo();
    int getId_Origem();
    float getPeso();
    Aresta* getProxAresta();

    void setProxAresta(Aresta* aresta);
    void setPeso(float peso);
    void setId_origem(int novo_id_Origem);
    void setId_alvo(int novo_id_alvo);

private:
    int id_alvo;
    int id_Origem;
    Aresta* prox;
    float peso;

};

#endif // ARESTA_H
