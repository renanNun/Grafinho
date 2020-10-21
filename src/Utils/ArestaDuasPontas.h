#ifndef ARESTADUASPONTAS_H
#define ARESTADUASPONTAS_H

#include "../no.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Luan Reis Ciribelli
*   versão: 1.0
*/
class ArestaDuasPontas
{
public:
    ArestaDuasPontas();
    ~ArestaDuasPontas();
    int getnoOrigem();
    void setnoOrigem(int id);
    int getnoAdj();
    void setnoAdj(int id);
    float getPeso();
    void setPeso(float peso);
    bool getVistado();
    void setVistado(bool x);
    ArestaDuasPontas* getProx();
    void setProx(ArestaDuasPontas* p);

private:
    int noOrigem;
    int noAdj;
    ArestaDuasPontas* prox;
    float peso;
    bool visitado;



};

#endif // ARESTADUASPONTAS_H
