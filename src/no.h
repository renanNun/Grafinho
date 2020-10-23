#ifndef NO_H
#define NO_H
#include "aresta.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Renan Nunes da Costa Gonçalves
*   versão: 1.0
*/
class No
{
public:
    No(int id);
    virtual ~No();

    Aresta* getPrimeiraAresta();
    Aresta* getUltimaAresta();
    int getId();
    int getGrauEntrada();
    int getGrauSaida();
    float getPeso();
    No* getProx();

    void setProxNo(No* no);
    void setPeso(float peso);

    bool buscaAresta(int id_alvo);
    void inserirAresta(int id_alvo,float peso);
    void removerTodasArestas();
    int removerAresta(int id,bool direcionado, No* no_alvo);
    void aumentaGrauEntrada();
    void diminuiGrauEntrada();
    void aumentaGrauSaida();
    void diminuiGrauSaida();
    void setId(int newId);
    Aresta* existeArestaEntre(int id_alvo);

    bool existeArestaEntreBool(int id_alvo);


    int i; //Variavel para DFS e BFS

    // Funções Prim

    bool getMarca();
    void setMarca();
    void desmarca();
    Aresta* getAresta();


private:
    Aresta* primeira_aresta;
    Aresta* ultima_aresta;
    int id;
    unsigned int grau_entrada;
    unsigned int grau_saida;
    float peso;
    No* prox;
    bool marca; //Para o Prim
};

#endif // NO_H
