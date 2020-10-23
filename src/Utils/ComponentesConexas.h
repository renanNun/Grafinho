#ifndef GRAFO_COMPONENTES_CONEXAS_H
#define GRAFO_COMPONENTES_CONEXAS_H

#include <iostream>
#include "aresta.h"
#include "no.h"
#include "grafo.h"

class ComponentesConexas
{

public:
    ComponentesConexas(Grafo* grafo);
    ~ComponentesConexas();
    void vetorIdNos(int* idNos);
    int componenteConexa(int* indComp, int* idNos);


private:
    Grafo *grafo;
    void buscaProfCompConexa(int *indComp, int i, int numComp, int *idNos);
    int encontraIndice(int *idNos, int id);





};


#endif //GRAFO_COMPONENTES_CONEXAS_H
