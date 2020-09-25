#include "grafo.h"

Grafo::Grafo(int ordem, bool direcionado,bool ponderado_aresta,bool ponderado_no)
{
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderado_aresta = ponderado_aresta;
    this->ponderado_no = ponderado_no;
    this->primeiro_no = this->ultimo_no = nullptr;
    this->numero_arestas = 0;
}

Grafo::~Grafo()
{
    No* prox_no = this->primeiro_no;

    while(prox_no != nullptr)
    {
        prox_no->removerTodasArestas();
        No* aux = prox_no->getProx();
        delete prox_no;
        prox_no = aux;
    }
}

//Getters
int Grafo::getOrdem()
{
    return this->ordem;
}

int Grafo::getNumeroArestas()
{
    return this->numero_arestas;
}

bool Grafo::getDirecionado()
{
    return this->direcionado;
}

bool Grafo::getPonderadoAresta()
{
    return this->ponderado_aresta;
}

bool Grafo::getPonderadoNo()
{
    return this->ponderado_no;
}

No* Grafo::getPrimeiroNo()
{
    return this->primeiro_no;
}

No* Grafo::getUltimoNo()
{
    return this->ultimo_no;
}

//Outros Métodos
void Grafo::aumentaNumArestas()
{
    this->numero_arestas++;
}

void Grafo::diminuiNumArestas()
{
    if(this->numero_arestas > 0)
        this->numero_arestas--;
}

No* Grafo::getNo(int id)
{
    if(this->primeiro_no != nullptr)
    {
        for(No* aux = this->primeiro_no; aux != nullptr; aux = aux->getProx())
                if(aux->getId() == id)
                    return aux;
    }

    return nullptr;
}

bool Grafo::existeNo(int id)
{
    if(this->primeiro_no != nullptr)
    {
        for(No* aux = this->primeiro_no; aux != nullptr; aux = aux->getProx())
                if(aux->getId() == id)
                    return true;
    }

    return false;
}

void Grafo::inserirNo(int id)
{
    if(!existeNo(id))
    {
        if(this->primeiro_no != nullptr)
        {
            No* no = new No(id);
            this->ultimo_no->setProxNo(no);
            this->ultimo_no = no;
        } else {
            this->primeiro_no = new No(id);
            this->ultimo_no = this->primeiro_no;
        }
    }
}

void Grafo::removerNo(int id)
{
    if(existeNo(id))
    {
        if(this->primeiro_no->getId() == id)
        {
            No* aux = this->primeiro_no;
            this->primeiro_no = this->primeiro_no->getProx();
            delete aux;
        } else {

            No* anterior;
            No* aux = this->primeiro_no;

            while(aux != nullptr)
            {
                if(aux->getId() == id)
                {
                    break;
                }

                anterior = aux;
                aux = aux->getProx();
            }

            if(this->ultimo_no == aux)
            {
                this->ultimo_no = anterior;
            }

            anterior->setProxNo(aux->getProx());

            No* p = this->primeiro_no;
            while(p != nullptr)
            {
                    p->removerAresta(id,direcionado,p);
            }

            delete aux;
        }
    }
}


void Grafo::inserirAresta(int id,int id_alvo,float peso)
{
    if(!existeNo(id))
        this->inserirNo(id);

    if(!existeNo(id_alvo))
        this->inserirNo(id);

    if(this->direcionado)
    {
        No* no = getNo(id);
        No* no_alvo = getNo(id_alvo);
        no->inserirAresta(id_alvo,peso);
        no->aumentaGrauSaida();
        no_alvo->aumentaGrauEntrada();
    } else {
        No* no = getNo(id);
        no->inserirAresta(id_alvo,peso);
        no->aumentaGrauEntrada();
    }
}

//Luan
int Grafo::grauMedioPorSomatorio()
{
    if(this->ordem != 0)
    {
        No* percorreGrafo = this->primeiro_no;
        float somatorioGraus = 0;

        while(percorreGrafo->getProx() != nullptr)
        {
            somatorioGraus += percorreGrafo->getPeso();
            percorreGrafo = percorreGrafo->getProx();
        }

        int grauMedio = (1.0/this->ordem) * somatorioGraus;
        return grauMedio;
    } else {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

//Luan
int Grafo::grauMedioPorAdjacencia()
{
    if(this->ordem != 0)
    {
        int grauMedio = (2) * (this->ordem/this->numero_arestas);
        return grauMedio;
    } else {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

//BUSCA EM PROFUNDIDADE
bool Grafo::depthFirstSearch(int id_inicial,int id_alvo)
{
    bool* vetor_coloracao = new bool[this->ordem];
    No* no = this->primeiro_no;

    for(int i = 0; i < this->ordem && no != nullptr; i++)
    {
        no->i = i;
        vetor_coloracao[i] = 0;
        no = no->getProx();
    }

    int nivel;
    No* pai = nullptr;
    no = getNo(id_inicial);

    cout << "BUSCA EM PROFUNDIDADE A PARTIR DO NO " << id_inicial << " AO NO " << id_alvo << endl << endl;


    if(no != nullptr)
    {
        depthFirstSearchF(no,vetor_coloracao,pai,0,id_alvo);
    } else {
        cout << "NO NAO ENCONTRADO" << endl;
        return false;
    }

    delete [] vetor_coloracao;
    return true;
}

/**
    ARRUMAR PONTO DE PARADA DE MODO QUE ELE SÓ VÁ ATÉ O NÓ QUE ESTAMOS PROCURANDO
    RESPONSÁVEL: LUAN
*/
void Grafo::depthFirstSearchF(No* no, bool* vetor_coloracao, No* pai, int nivel, int id_alvo)
{
    if(no == nullptr)
        return;

    if(nivel == 0)
    {
        //cout << "debug" << endl;
        cout << "NO: " <<  no->getId() << " PAI: NULL NIVEL: " << nivel << endl;
    }
    else
    {
        //cout << "debug" << endl;
        cout << "NO: " <<  no->getId() << " PAI: " << pai->getId() << " NIVEL: " << nivel << endl;
    }

    vetor_coloracao[no->i] = 1;
    Aresta* aresta = no->getPrimeiraAresta();

    while(aresta != nullptr)
    {
        No* aux = getNo(aresta->getId());
        if(vetor_coloracao[aux->i] == 0)
            depthFirstSearchF(aux,vetor_coloracao,no,nivel+1,id_alvo);
        aresta = aresta->getProxAresta();
    }
}

//BUSCA EM LARGURA
void Grafo::breathFirstSearch(ofstream& output_file)
{
   queue<No*> fila; //FILA

   No* no = this->primeiro_no; //PRIMEIRO NO DO GRAFO

   bool* visitado = new bool[this->ordem]; //VETOR DE MARCAÇÃO

   for(int i = 0; i < this->ordem && no != nullptr; i++)
   {
       visitado[i] = false;
       no->i = i;
       no = no->getProx();
   }

   no = this->primeiro_no; //VOLTAMOS PARA O PRIMEIRO NO DO GRAFO
   visitado[no->i] = 1;

   fila.push(no);

   No* aux;
   Aresta* aresta;

    output_file << "BUSCA EM LARGURA " << endl << endl;

   while(!fila.empty())
   {
       aux = fila.front();
       fila.pop();
       aresta = aux->getPrimeiraAresta();
       output_file << aux->getId() << ", ";

       while(aresta != nullptr)
       {
           No* no_aux = getNo(aresta->getId());
           if(visitado[no_aux->i] == 0)
           {
               visitado[no_aux->i] = 1;
               fila.push(no_aux);
           }

           aresta = aresta->getProxAresta();
       }
   }

}

//IMPRESSÃO
void Grafo::imprimir()
{
    cout << endl << "IMPRESSAO POR LISTA DE ADJACENCIA" << endl;
    cout << "\t\t ORDEM: " << this->ordem << endl;
    cout << "\t\t NUMERO DE ARESTAS: " << this->numero_arestas << endl;
    cout << "\t\t GRAU MEDIO DO GRAFO: " << this->grauMedioPorAdjacencia() << endl;
    cout << endl;

    for(No* no = this->primeiro_no; no != nullptr; no = no->getProx())
    {
        cout << no->getId();

        if(no->getPrimeiraAresta() != nullptr)
            cout << "--->";

        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProxAresta())
        {
            if(this->ponderado_aresta)
            {
                if(aresta->getProxAresta() != nullptr)
                    cout << aresta->getId() << "(" << aresta->getPeso() << ")--->";
                else
                    cout << aresta->getId();
            } else
            {
               if(aresta->getProxAresta() != nullptr)
                    cout << aresta->getId() << "--->";
               else
                    cout << aresta->getId();
            }
        }

        cout << endl;
    }
}

