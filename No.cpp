#include "Elemento.h"
#include "No.h"


No::No(int qtdElementoPorNo)
{
    this->qtdMax = qtdElementoPorNo;
    this->qtdElemento= 0;
    this->alocaVetElemento(qtdElementoPorNo); //aloca vetor de elementos
    this->alocaVetPonteiro(qtdElementoPorNo + 1); //aloca vetor de ponteiros
}

No::~No()
{
    this->vetElemento = NULL;
    this->vetPonteiro = NULL;
}

 Elemento* No::getElemento(unsigned int index)
 {
    return this->vetElemento[index];
 }

 void No::setElemento(unsigned int index, Elemento* e)
 {
     vetElemento[index] = e;
 }

 No* No::getPonteiro(unsigned int index)
 {
    return this->vetPonteiro[index];
 }

void No::setPonteiro(unsigned int i, No* n)
 {
     this->vetPonteiro[i] = n;
 }

 unsigned int No::getQtdElemento() const
{
    return this->qtdElemento;
}

unsigned int No::getQtdMax() const
{
    return this->qtdMax;
}


void No::incluir(Elemento* e)
{
    int index = -1;

    if(!this->isCompleto())
    {
        this->setElemento((qtdMax-1), e);
        this->ordenarVetElemento();
    }
    else
    {
        index = this->qualNo(e);
        if(this->vetPonteiro[index] == NULL)
        {
            No* novoNo = new No(qtdMax);
            this->vetPonteiro[index] = novoNo;
            this->vetPonteiro[index]->incluir(e);
        }
        else
            this->vetPonteiro[index]->incluir(e);
    }

}

void No::excluir(Elemento* e) throw()
 {
    if(this->existe(e))
    {
        int index = -1;

        // verificar se existe nesse no
        for(int i=0;i < qtdMax-1;i++)
        {
            if(this->vetElemento[i]->compareTo(e) == 0)
                this->setElemento(i, e);
        }

        // tá em outro nó
        index = qualNo(e);
        if(index == -1)
            return;
        else
            this->vetPonteiro[index]->excluir(e);
    }
    else
        throw "Elemento não existe na árvore";
 }

bool No::existe(Elemento* e)
{
    int index = -1;

    // verificar se existe nesse no
    for(int i=0;i < qtdMax;i++)
    {
         if(this->vetElemento[i]->compareTo(e) == 0)
            return true;
    }

    // tá em outro nó
    index = qualNo(e);
    if(index == -1)
        return false;
    else
        this->vetPonteiro[index]->existe(e);
}

Elemento* No::pesquisar(Elemento* e) throw()
{
    int index = -1;

    if(this->existe(e))
    {
        for(int i=0;i < qtdMax;i++)
        {
            if(this->vetElemento[i]->compareTo(e) == 0)
                return this->vetElemento[i];
        }

    // tá em outro nó
        index = qualNo(e);
        if(index == -1)
            throw "Nó não existe";
        else
            this->vetPonteiro[index]->pesquisar(e);
    }
    else
        throw "Nó não existe";
}

bool No::isCompleto() const
{
    if(vetElemento[(qtdMax-1)] == NULL)
        return false;
    else
        return true;
}

int No::qualNo(Elemento* e) // busca o index de inserção, seja a do vetor de elementos
{                                     // ou do vetor de ponteiros
    bool achou = false;
    int index = 0;

    if(this->vetElemento[qtdMax-1]->compareTo(e) == -1)
        return qtdMax + 1;
    else
        if(this->vetElemento[0]->compareTo(e) == 1)
            return 0;
        else
        {
            for(int i=0;i < qtdMax;i++)
            {
                  if(this->vetElemento[i]->compareTo(e) == 1)
                        return index;
            }
        }
        return -1;
}


void No::ordenarVetElemento()
{
    Elemento* iTemp = NULL;
     for(int i=this->qtdMax-1; i >= 1; i--)
    {
        for(int j=0; j < i ; j++)
        {
            if(this->vetElemento[j]->compareTo(this->vetElemento[j+1]) == 1)
            {
                iTemp = this->vetElemento[j];
                this->vetElemento[j] = this->vetElemento[j+1];
                this->vetElemento[j+1] = iTemp;
            }
        }
    }
}


int No::getIndex(Elemento* e) const
{
    int index=-1; // se retorna -1 � pq n�o existe o Elemento no vetor

    for(int i=0; i < (this->qtdElemento-1); i++)
    {
        if(this->vetElemento[i]->compareTo(e) == 0)
            index = i;
    }
    return index;
}

void No::alocaVetElemento(int q)
{
    this->vetElemento = new Elemento*[q];

    for(int i=0; i<(q); i++)
    {
        this->vetElemento[i] = NULL;
    }
}

void No::alocaVetPonteiro(int q)
{
    this->vetPonteiro = new No*[q];

    for(int i=0; i<(q); i++)
    {
        this->vetPonteiro[i] = NULL;
    }
}
