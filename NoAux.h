#ifndef NOAUX_H
#define NOAUX_H


class NoAux
{
    public:
        NoAux(int id);
        virtual ~NoAux();

        int getId();
        void setProx(NoAux* p);
        NoAux* getProx();

    private:
        int id;
        NoAux* prox;
};

#endif // NOAUX_H
