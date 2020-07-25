#include "FilaEncadeada.h"

FilaEncadeada::FilaEncadeada()
{
    this->cabeca = nullptr;
    this->cauda = nullptr;
}

FilaEncadeada::~FilaEncadeada()
{
    NoAux* v = this->cabeca;

    while( this->cabeca != nullptr)
    {
        this->cabeca = v->getProx();
        delete v;
        v = this->cabeca;
    }
    this->cauda = nullptr;

    free(v);
}

bool FilaEncadeada::vazia()
{
    return this->cabeca = this->cauda = nullptr;
}

int FilaEncadeada::getInicio()
{
    return this->cabeca->getId();
}

void FilaEncadeada::enfileira(int id)
{
    NoAux* v = new NoAux(id);

    if(this->cauda == nullptr)
        this->cabeca = v;
    else
        this->cauda->setProx(v);
    this->cauda = v;
}

int FilaEncadeada::desenfileira()
{
    NoAux* v;
    if(this->cabeca != nullptr)
    {
        v = this->cabeca;
        this->cabeca = v->getProx();

        if(this->cabeca == nullptr)
            this->cauda = nullptr;
        int info = v->getId();
        delete v;
        return info;
    }
    else
    {
        //cout << "FILA VAZIA! " << endl;
        exit(-3);
    }
}

void FilaEncadeada::imprime()
{
    if(this->cabeca != nullptr)
    {
        for(NoAux* v = this->cabeca; v != nullptr; v = v->getProx())
        {
            cout << v->getId() << " ";
        }
        cout << this->cauda->getId();
    }

}
