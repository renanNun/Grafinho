#include "Grafo.h"

/**
    Construtor do Grafo
*/
Grafo::Grafo()
{
    this->ordem = 0;
    this->numArestas = 0;

    this->cabeca = nullptr;
    this->cauda = nullptr;
}

/**
    Destrutor do Grafo
*/
Grafo::~Grafo()
{
    No* t = this->cabeca;

    while(t != nullptr)
    {
        No* aux = t->getProx();
        delete t;
        t = aux;

    }

    this->cabeca = this->cauda = nullptr;
}

/**
    Função que carrega os parâmetros do Grafo
    @param: dir - representa se o Grafo é um Grafo Direcionado ou não
    @param: pondA - representa se o Grafo é Ponderado em suas Arestas
    @param: pondN - representa se o Grafo é ponderado em seus Nós
*/
void Grafo::carregarConfiguracoes(bool dir, bool pondA, bool pondN)
{
    this->direcionado = dir;
    this->ponderadoA = pondA;
    this->ponderadoN = pondN;
}

/**
    Getters
*/
int Grafo::getOrdem()
{
    return this->ordem;
}

int Grafo::getNumAretas()
{
    return this->numArestas;
}

bool Grafo::isDir()
{
    return this->direcionado;
}

bool Grafo::isPondA()
{
    return this->ponderadoA;
}

bool Grafo::isPondN()
{
    return this->ponderadoN;
}

/**
    Função responsável pela impressão do Grafo em forma de lista de Adjacência
*/
void Grafo::imprimirListaAdj()
{
    cout << "\tImpressão por Lista de Adjacência;" << endl;
    cout << "\tOrdem: " << getOrdem() << endl;
    cout << "\tNúmero de Arestas: " << getNumAretas() << endl;
    cout << endl;

    for(No* no = this->cabeca;  no != nullptr; no = no->getProx())
    {
        cout << no->getId();

        if(no->getAresta() != nullptr)
            cout << "--->";

        for(Aresta* a = no->getAresta(); a != nullptr; a = a->getProx())
        {
            if(isPondA())
            {
                if(a->getProx() != nullptr)
                    cout << a->getNoAdj() << " (" << a->getPeso() << ")--->";
                else
                    cout << a->getNoAdj();
            }
            else
            {
                if(a->getProx() != nullptr)
                    cout << a->getNoAdj() << "--->";
                else
                    cout << a->getNoAdj();
            }
        }

        cout << endl;
    }
}

/**
    Função responsável pela pesquisa de determinado nó em um Grafo, ela retorna se eles está presente ou não
    @param: id - A informação contida no Nó
*/
bool Grafo::existeNo(int id)
{
    No* no = this->cabeca;

    while(no != nullptr)
    {
        if(no->getId() == id)
        {
            return true;
            break;
        }
        no = no->getProx();
    }

    return false;
}

/**
    Função que verifica a existência de um Nó no Grafo ou não, ela retorna o proprio nó ou nullptr caso ele nao exista
    @param: id - Informação contina no Nó
*/
No* Grafo::buscaNo(int id)
{
    No* no = this->cabeca;

    while(no != nullptr)
    {
        if(no->getId() == id)
        {
            return no;
            break;
        }
        no = no->getProx();
    }

    return nullptr;
}

/**
    Função responsável por inserir um Nó no Grafo, os Nós são inseridos em uma lista encadeada, essa função os insere no final da lista
    @param: id - Informação contida no Nó
    @param: peso - peso do No
*/
void Grafo::inserirNo(int id, int peso)
{
    if(!existeNo(id))
    {
        No* novo = new No(id,peso);

        if(this->cabeca == nullptr)
        {
            this->cabeca = novo;
            this->cauda = this->cabeca;
            this->ordem++;
        }
        else
        {
            cauda->setProx(novo);
            cauda = novo;
            novo->setProx(nullptr);
            this->ordem++;
        }
    }
    else
    {
        //cout << "Nó já inserido!" << endl;
        return;
    }
}

void Grafo::removerNo(int id)
{
    No* p = this->cabeca;

    if(p == nullptr)
    {
        cout << "GRAFO VAZIO" << endl;
        return;
    }

    if(this->cabeca->getId() == id)
    {
        this->cabeca = this->cabeca->getProx();
        delete p;
    }
    else
    {
        No* aux = p->getProx();

        while(aux != nullptr)
        {
            if(aux->getId() == id)
            {
                break;
            }
            else
            {
                p = aux;
                aux = aux->getProx();
            }
        }

        if(this->cauda != nullptr)
        {
            if(this->cauda == aux)
            {
                this->cauda = p;
            }
            p->setProx(aux->getProx());
            delete aux;
        }
    }
    removeAdjacencias(id);
}


void Grafo::removeAdjacencias(int id)
{
    No* p = this->cabeca;

    while (p != nullptr)
    {
        p->removerAresta(id);
        p = p->getProx();
    }
}

/**
    Função responsável por inserir as Arestas entre os Nós
    @param: idOrigem - O Nó de origem da aresta
    @param: idDestino - O Nó de destino da aresta
    @param: peso - o Custo da aresta
*/
void Grafo::inserirAresta(int idOrigem, int idDestino, int peso)
{
    No* origem = buscaNo(idOrigem);
    No* destino = buscaNo(idDestino);

    if(origem != nullptr && destino != nullptr)
    {
        if(this->direcionado)
        {
            origem->inserirAresta(idDestino,peso);
            this->numArestas++;
        }
        else
        {
            origem->inserirAresta(idDestino,peso);
            destino->inserirAresta(idOrigem,peso);
            this->numArestas++;
        }
    }
    else
    {
        cout << "Nó não existe! " << endl << endl;
        return;
    }
}

/**
    Função responsável por remover Arestas
    @param: idOrigem - O no de onde parte a aresta
    @param: idDestino - O no onde a aresta se direciona
*/
void Grafo::removerAresta(int idOrigem, int idDestino)
{
    if(!existeNo(idOrigem) && existeNo(idDestino))
    {
        cout << "\nIDs Inválidos!" << endl;
        return;
    }

    No* origem = buscaNo(idOrigem);
    No* destino = buscaNo(idDestino);

    if(origem != nullptr && destino != nullptr)
    {
        origem->removerAresta(destino->getId());
        destino->removerAresta(origem->getId());
        this->numArestas--;
    }
}

/**
    Métodos para representação do Grafo em Matriz de Adjacência
*/
/**
    Retorna a Matriz de Adjacência de um Grafo
*/
int** Grafo::getMatrizAdj()
{
    int** matrizAdj;
    int n = this->ordem;
    int origem, destino;

    /*INICIANDO A MATRIZ*/
    matrizAdj = new int* [n];
    for(int i = 0; i < n; i++)
    {
        matrizAdj[i] = new int[n];
        for(int j = 0; j < n; j++)
            matrizAdj[i][j] = -1;
    }

    /*Preenchendo a Matriz com o peso das arestas*/
    for(No* no = this->cabeca; no != nullptr ; no = no->getProx())
    {
        origem = getPosicaoMatriz(no->getId());

        for(Aresta* a = no->getAresta(); a != nullptr; a = a->getProx())
        {
            destino = this->getPosicaoMatriz(a->getNoAdj());
            matrizAdj[origem][destino] = a->getPeso();
        }
    }
    return matrizAdj;
}

/**
    Retorna a posição de determinado Nó na matriz
    @param: id - informação contida no Nó
*/
int Grafo::getPosicaoMatriz(int id)
{
    int c = 0;
    for(No* no = this->cabeca; no != nullptr; no = no->getProx())
    {
        if(no->getId() == id)
        {
            return c;
        }
        c++;
    }

    return -1;
}

bool Grafo::visitado(int id,int* vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        if(vetor[i] == id)
            return true;
    return false;
}

void Grafo::buscaEmProfundidade(int id)
{
    bool* vetorColoracao = new bool[this->ordem];
    No* p = this->cabeca;

    for(int i = 0; p != nullptr && i < this->ordem; i++)
    {
        p->visitado = i;
        vetorColoracao[i] = 0;
        p = p->getProx();
    }

    int nivel = 0;
    No* pai = nullptr;
    p = buscaNo(id);

    cout << "BUSCA EM PROFUNDIDADE A PARTIR DO NÓ " << id << endl << endl;

    if(p != nullptr)
    {
        buscaEmProfundidadeF(p,vetorColoracao,pai,nivel);
    } else {
        cout << "Nó não encontrado" << endl;
        return;
    }

    delete [] vetorColoracao;
}

void Grafo::buscaEmProfundidadeF(No* v, bool* vetorColoracao, No* pai,int nivel)
{
    if(v == nullptr)
        return;
    if(nivel == 0)
        cout << "No: " << v->getId() << " Pai: NULL Nivel: " << nivel << endl;
    else
        cout << "No: " << v->getId() << " Pai: " << pai->getId() << " Nivel: " << nivel << endl;

    vetorColoracao[v->visitado] = 1;
    Aresta* a = v->getAresta();

    while( a != nullptr)
    {
        No* aux = buscaNo(a->getNoAdj());
        if(vetorColoracao[aux->visitado] == 0)
            buscaEmProfundidadeF(aux,vetorColoracao,v,nivel+1);
        a = a->getProx();
    }
}

void Grafo::buscaEmLargura(int id)
{
    int* vetorColoracao = new int[this->ordem]; //Fila de armazenagem dos nos percorridos
    bool* vetorColoracaoB = new bool [this->ordem];
    bool* vetorColoracaoC = new bool [this->ordem];

    No* p = this->cabeca;

    for(int i = 0; p != nullptr && i < this->ordem; i++)
    {
        p->visitado = i;
        vetorColoracaoB[i] = 0;
        vetorColoracaoC[i] = 0;
        p = p->getProx();
    }

    p = buscaNo(id);

    if(p != nullptr)
    {
        buscaEmLarguraF(p,vetorColoracao,vetorColoracaoB,vetorColoracaoC);

    } else {
        cout << "No não encontrado!" << endl;
        return;
    }
    cout << "FIM" << endl;

    delete [] vetorColoracao;
    delete [] vetorColoracaoB;
    delete [] vetorColoracaoC;
}

void Grafo::buscaEmLarguraF(No* pai, int* vetorColoracao, bool* vetorColoracaoB, bool* vetorColoracaoC)
{
    int nivel = 0;
    int controleFila = 0;
    int controleImpressao = 0;
    int controleNivel = 0;

    cout << "No: " << pai->getId() << " Pai: NULL Nivel: " << nivel << endl;

    vetorColoracao[controleFila] = pai->getId();
    vetorColoracaoB[pai->visitado] = 1;
    vetorColoracaoC[pai->visitado] = 1;
    nivel++;

    Aresta* a = pai->getAresta();
    while(1)
    {
        while (a != nullptr)
        {
            No* aux = buscaNo(a->getNoAdj());
            if(vetorColoracaoC[aux->visitado] == 0)
            {
                cout << "No: " << aux->getId() << " Pai: " << pai->getId() << " Nivel: " << nivel << endl;
                vetorColoracao[controleFila] = aux->getId();
                controleFila++;
            }

            vetorColoracaoC[aux->visitado] = 1;
            a = a->getProx();
        }

        if(controleImpressao == controleNivel)
        {
            controleNivel = controleFila-1;
            nivel++;
        }
        controleImpressao++;

        if(controleFila == controleNivel)
            break;

        pai = buscaNo(vetorColoracao[controleImpressao]);
        vetorColoracaoB[pai->visitado] = 1;
        a = pai->getAresta();

        No* check = buscaNo(a->getNoAdj());
        while(a != nullptr && vetorColoracaoB[check->getId()] == 1)
            a = a->getProx();
    }
}

/**
    TENTATIVA DE ARRUMAR A BUSCA EM LARGURA

    BuscaEmLargura
   escolha uma raiz s de G
   marque s
   insira s em F
   enquanto F não está vazia faça
      seja v o primeiro vértice de F
      para cada w ∈ listaDeAdjacência de v faça
         se w não está marcado então
            visite aresta entre v e w
            marque w
            insira w em F
         senao se w ∈ F entao
            visite aresta entre v e w
         fim se
      fim para
      retira v de F
   fim enquanto

*/
void Grafo::BEL(int id)
{
    No* p = this->cabeca;

    for(int i = 0; p != nullptr && i < this->ordem; i++)
    {
        p->visitado = 0;
        p = p->getProx();
    }

    p = buscaNo(id);

    p->visitado = 1;

    FilaEncadeada* F;

    F->enfileira(p->getId());

    while(!F->vazia())
    {
        Aresta* a = p->getAresta();
        for(No* n = buscaNo(a->getNoAdj()); a != nullptr; a = a->getProx())
        {
            if(n->visitado != 1)
            {

            }
        }
    }

}
