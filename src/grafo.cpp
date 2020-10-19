#include "grafo.h"

/**
    Construtor da Classe Grafo.cpp
    @param ordem: Número total de nós do grafo
    @param direcionado: Se o Grafo é direcionado ou não
    @param ponderado_aresta: Se o Grafo possui peso nas aretas
    @param ponderado_no: Se o Grafo possui peso nos vértices
    autor: Renan Nunes da Costa Gonçalves
*/
Grafo::Grafo(int ordem, bool direcionado,bool ponderado_aresta,bool ponderado_no)
{
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderado_aresta = ponderado_aresta;
    this->ponderado_no = ponderado_no;
    this->primeiro_no = this->ultimo_no = nullptr;
    this->numero_arestas = 0;

    this->matriz_adjacencia = nullptr;
    this->getMatrizAdj();
}

/**
    Destrutor da classe Grafo.cpp
    autor: Renan Nunes da Costa Gonçalves
*/
Grafo::~Grafo()
{
    this->deleteMatrizAdj();

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
/**
    Função que aumenta o número de arestas do Grafo
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::aumentaNumArestas()
{
    this->numero_arestas++;
}

/**
    Função que diminui o número de arestas do Grafo
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::diminuiNumArestas()
{
    if(this->numero_arestas > 0)
        this->numero_arestas--;
}

/**
    Função que retorna um nó dado um id
    @param id: informação contida no No
    autor: Renan Nunes da Costa Gonçalves
*/
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

/**
    Função que verifica a existencia de um Nó dado um id
    @param id: informação contida no Id
    autor: Renan Nunes da Costa Gonçalves
*/
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

/**
    Função que insere um Nó no grafo
    @param id: Informação continda no No
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::inserirNo(int id)
{
    if(!existeNo(id))
    {
        if(this->primeiro_no != nullptr)
        {
            No* no = new No(id);
            this->ultimo_no->setProxNo(no);
            this->ultimo_no = no;
        }
        else
        {
            this->primeiro_no = new No(id);
            this->ultimo_no = this->primeiro_no;
        }
    }
}

/**
    Função responsável por remover um Nó no grafo
    @param id: informação contida no No
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::removerNo(int id)
{
    if(existeNo(id))
    {
        if(this->primeiro_no->getId() == id)
        {
            No* aux = this->primeiro_no;
            this->primeiro_no = this->primeiro_no->getProx();
            delete aux;
        }
        else
        {

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

/**
    Função responsável por inserir uma aresta no Grafo
    @param id: informação do Nó
    @param id_alvo: informação do Nó alvo
    @param peso: custo da aresta
    autor: Renan Nunes da Costa Gonçalves
*/
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
    }
    else
    {
        No* no = getNo(id);
        no->inserirAresta(id_alvo,peso);
        no->aumentaGrauEntrada();
    }
}


/**
    Função responsável por retornar o Grau médio do Grafo pro somatório
    autor: Luan Reis Ciribelli
*/
int Grafo::grauMedioPorSomatorio()
{
    if(this->ordem != 0)
    {
        No* percorreGrafo = this->primeiro_no;
        int somatorioGraus = 0;

        if(!this->direcionado)
        {
            while(percorreGrafo->getProx() != nullptr)
            {
                somatorioGraus += percorreGrafo->getGrauEntrada();
                percorreGrafo = percorreGrafo->getProx();
            }
        }
        else
        {
            while(percorreGrafo->getProx() != nullptr)
            {
                somatorioGraus += percorreGrafo->getGrauSaida();
                percorreGrafo = percorreGrafo->getProx();
            }


        }


        int grauMedio = somatorioGraus/this->ordem;
        return grauMedio;
    }
    else
    {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

/**
    Função responsável por retornar o Grau médio por somatório de adjacências
    autor: Luan Reis Ciribelli
*/
int Grafo::grauMedioPorAdjacencia()
{
    if(this->ordem != 0)
    {
        int grauMedio = (2) * (this->numero_arestas/this->ordem);
        return grauMedio;
    }
    else
    {
        cout << "Nao e possível calcular o grau medio sem nos no grafo";
        return -1;
    }
}

bool fechoTriadico(No *a, No  *b)
{

    if (!a->existeArestaEntreBool(b->getId()))
    {

        return false;
    }
    else
    {

        return true;
    }


}

double coeficienteDeAgrupamento()
{
    return 0;

}

/**
    Função responsável por realizar a busca em profundidade
    @param id_inicial: informação do Nó origem
    @param id_alvo: informação do Nó alvo
    autor: Renan Nunes da Costa Gonçalves
*/
bool Grafo::depthFirstSearch(int id_inicial)
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

    cout << "BUSCA EM PROFUNDIDADE A PARTIR DO NO " << id_inicial << endl << endl;


    if(no != nullptr)
    {
        depthFirstSearchF(no,vetor_coloracao,pai,0);
    }
    else
    {
        cout << "NO NAO ENCONTRADO" << endl;
        return false;
    }

    delete [] vetor_coloracao;
    return true;
}

/**
    Função Responsável por auxiliar a busca em profundidade
    @param:
    @param:
    @param:
    @param:
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::depthFirstSearchF(No* no, bool* vetor_coloracao, No* pai, int nivel)
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

/**
    Função Responsável por busca em largura
    @param output_file: arquivo de saída
    autor: Renan Nunes da Costa Gonçalves
*/
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

/**
    Função responsável pela impressão do Grafo em forma de lista de adjacência
    autor: Renan Nunes da Costa Gonçalves
*/
void Grafo::imprimir()
{
    cout << endl << "IMPRESSAO POR LISTA DE ADJACENCIA" << endl;
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
            }
            else
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

void Grafo::imprimirMatriz()
{
    cout << endl << "IMPRESSAO POR MATRIZ DE ADJACENCIA" << endl;
    cout << endl;
    int a,b;
    for( No* no = this->primeiro_no; no != nullptr; no = no->getProx())
    {
        a = getPosicaoMatriz(no->getId());
        cout << endl;
        cout << "(" << no->getId() << ") ";
        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProxAresta())
        {
            //cout << "ENTROU" << endl;
            b = getPosicaoMatriz(aresta->getId());
            cout << this->matriz_adjacencia[a][b] << " | ";
        }
    }

}

void Grafo::getMatrizAdj()
{
    this->matriz_adjacencia = new bool*[this->ordem];
    for(int i = 0; i < this->ordem; i++)
    {
        //cout << " " << i;
        this->matriz_adjacencia[i] = new bool[this->ordem];
        for(int j = 0; j < this->ordem; j++)
        {
            this->matriz_adjacencia[i][j] = 0;
        }
    }
}

void Grafo::adicionaArestaMatriz(int i, int j)
{
    matriz_adjacencia[this->getPosicaoMatriz(i)][this->getPosicaoMatriz(j)] = true;
}

void Grafo::deleteMatrizAdj()
{
    for(int i = 0; i < this->ordem; i++)
    {
        for(int j = 0; j < this->ordem; j++)
        {
            delete [] matriz_adjacencia[i];
        }
        delete [] matriz_adjacencia;
    }
}

int Grafo::getPosicaoMatriz(int id)
{
    int c = 0;

    for(No* no = this->primeiro_no; no != nullptr; no = no->getProx())
    {
        if(no->getId() == id)
        {
            return c;
        }
        c++;
    }

    return -1;
}

