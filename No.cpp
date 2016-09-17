#include "Elemento.h"
#include "No.h"
#include <string>
#include <iostream>


No::No(int qtdElementoPorNo)
{
    this->qtdMax = qtdElementoPorNo;
    this->qtdElemento= 0;
    this->alocaVetElemento(qtdElementoPorNo); //aloca vetor de elementos
    this->alocaVetPonteiro(qtdElementoPorNo + 1); //aloca vetor de ponteiros
}

No::No(No* outro)
{
    this->qtdMax = outro->getQtdMax();
    this->qtdElemento = outro->getQtdElemento();
    this->vetElemento = outro->vetElemento;
    this->vetPonteiro = outro->vetPonteiro;
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

    if(this->qtdElemento == 0)
    {
        this->vetElemento[0] = e;
        this->qtdElemento++;
    }
    else
        if(!this->isCompleto())
        {
            this->setElemento((qtdElemento), e);
            this->qtdElemento++;
            this->ordenarVetElemento();
        }
        else
        {
            index = this->qualNo(e);
            index--;
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

void No::excluir(Elemento* e) throw() //excluí e rearranja
 {
    No* aux;
    int index;
    if(this->existe(e))
    {
        aux = this->pesquisarNo(e);
        index = aux->getIndex(e);
        aux->excluirPosicao(index);
    }
    else
        throw "Elemento não existe na árvore";
 }

void No::excluirPosicao(int index) throw() //excluí e rearranja
 {
        if(this->isFolha())
        {
            this->qtdElemento--;
            for(int c = index; c < this->qtdElemento; c++)
                this->vetElemento[c] = this->vetElemento[c+1];

            return;
        }
        else
        {
            if(this->vetPonteiro[index+1] != NULL) // pega o menor elemento da direita
            {
                this->vetElemento[index] = this->vetPonteiro[index+1]->vetElemento[0];

                this->vetPonteiro[index+1]->qtdElemento--;
                if(this->vetPonteiro[index+1]->getQtdElemento() == 0)
                {
                    this->vetPonteiro[index+1] = NULL;
                    return;
                }

                this->vetPonteiro[index+1]->excluirPosicao(0);
            }
            else
            {
                if(this->vetElemento[index] != NULL) // pega o maior elemento da esquerda
                {
                    this->vetElemento[index] = this->vetPonteiro[index]->vetElemento[(this->vetPonteiro[index]->getQtdElemento()) - 1];

                    this->vetPonteiro[index]->qtdElemento--;
                    if(this->vetPonteiro[index]->getQtdElemento() == 0)
                    {
                        this->vetPonteiro[index] = NULL;
                        return;
                    }

                    this->vetPonteiro[index]->excluirPosicao(this->vetPonteiro[index]->getQtdElemento());
                }
            }
        }
 }

bool No::existe(Elemento* e)
{
    int index = -1;

    // verificar se existe nesse no
    for(int i=0;i < this->qtdElemento;i++)
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

No* No::pesquisarNo(Elemento* e) throw()
{
    int index = -1;

    if(this->existe(e))
    {
        for(int i=0;i < qtdMax;i++)
        {
            if(this->vetElemento[i]->compareTo(e) == 0)
                return this;
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

int No::qualNo(Elemento* e) // busca o nó de inserção, seja a do vetor de elementos
{                                     // ou do vetor de ponteiros
    int index = 0;

    if(this->vetElemento[qtdMax-1]->compareTo(e) == -1)
        return qtdMax + 1;
    else
        if(this->vetElemento[0]->compareTo(e) == 1)
            return 1;
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
    int aux = this->qtdElemento;
    Elemento* iTemp = NULL;
    for(int i=0; i < aux;i++)
    {
        for(int j=i+1; j < aux ; j++)
        {
            if(this->vetElemento[i]->compareTo(this->vetElemento[j]) == 1)
            {
                iTemp = this->vetElemento[i];
                this->vetElemento[i] = this->vetElemento[j];
                this->vetElemento[j] = iTemp;
            }
        }
    }
}

std::ostream& No::toString(std::ostream& o)
{
    std::string novoNo = " ( ";
    std::string aux = " ";
     std::string aux1 = "";

    if(this->qtdElemento == 0)
    {
        o << "";
        return o;
    }
    if(this->isFolha())
    {
        o << novoNo;
        for(int i = 0; i<this->getQtdElemento(); i++)
        {
            o << this->vetElemento[i]->getValor();
            o << aux;
        }
        o << ") ";
    }
    else
    {
        for(int i = 0; i<this->getQtdElemento(); i++)
        {
            if(this->vetPonteiro[i] != NULL)
            {
                this->vetPonteiro[i]->toString(o);
            }

            if(i == 0)
                o << novoNo;

            o << this->vetElemento[i]->getValor();
            o << aux;
            if(i == this->getQtdElemento() -1)
                o << ") ";
        }
        if(this->vetPonteiro[this->getQtdElemento()] != NULL)
            this->vetPonteiro[this->getQtdElemento()]->toString(o);
    }

    return o;
}

bool No::isFolha()
{
    bool retorno = true;
    for(int i=0; i <= qtdElemento; i++)
    {
        if(this->vetPonteiro[i] != NULL)
            retorno = false;
    }

    return retorno;
}


int No::getIndex(Elemento* e) const
{
    int index=-1; // se retorna -1 � pq n�o existe o Elemento no vetor

    for(int i=0; i < (this->qtdElemento); i++)
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

No& No::operator=(const No& n)
{
    No* novo;
    novo = new No(n);
    return *novo;
}
