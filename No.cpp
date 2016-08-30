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
    for(int i=0; i<(qtdMax-1); i++)
    {
        this->vetElemento[i] = NULL;
    }
    for(int i=0; i<(qtdMax); i++)
    {
        this->vetPonteiro[i] = NULL;
    }

    delete vetElemento;
    delete vetPonteiro;
}

 Elemento* No::getElemento(unsigned int index) const
 {
    return this->vetElemento[index];
 }

 void No::setElemento(unsigned int index, Elemento* e)
 {
     vetElemento[index] = e;
 }

 No* No::getPonteiro(unsigned int index) const//retorna o pr�ximo elemento
 {
    return this->vetPonteiro[index];
 }

void No::setPonteiro(unsigned int i, No* n)
 {
     this->vetPonteiro[i] = n;
 }

bool No::verificaInclusao(Elemento* e)
{
    bool retorno = true;

    for(int i=0; i < (this->qtdMax - 1); i++)
    {
        switch(this->vetElemento[i]->compareTo(e))
        {
            case 0:     retorno = false;
                        break;
        }
    }
    return retorno;
}


bool No::addElemento(Elemento* e) // Incompleto!!!!
{
    int index = 0;
    bool retorno = false;

    if(this->isCompleto())
        return false;
    else
        if(!this->verificaInclusao(e))
            return false;
        else
        {
            this->setElemento((qtdMax -1), e);
            this->ordenarVetElemento();
            this->qtdElemento++;
            return true;
        }
}

 bool No::excluirElemento(Elemento* e) // Incompleto!!!
 {
     int index;

     if(!this->verificaInclusao(e))
        return false;
     else
     {
         for(int i=0; i < (this->qtdMax-1); i++)
         {
             if(this->vetElemento[i]->compareTo(e) == 0)
                index = i;
         }
         this->vetElemento[index] == NULL;
         this->ordenarVetElemento();
         this-qtdElemento--;
         return true;
     }


 }

bool No::isCompleto() const
{
    if(vetElemento[(qtdMax-1)] == NULL)
        return false;
    else
        return true;
}


void No::ordenarVetElemento()
{
    Elemento* iTemp = NULL;
    for (int i = 0; i < (qtdMax -1); i++)
    {
        for (int j = i + 1; j <= (this->qtdMax -1); j++)
        {
            if (this->vetElemento[j] < this->vetElemento[i])
            {
                iTemp = this->vetElemento[i];
                this->vetElemento[i] = this->vetElemento[j];
                this->vetElemento[j] = iTemp;
            }
        }
    }
}


unsigned int No::getQtdElemento() const
{
    return this->qtdElemento;
}

unsigned int No::getQtdMax() const
{
    return this->qtdMax;
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

    for(int i=0; i<(q-1); i++)
    {
        this->vetElemento[i] = NULL;
    }
}

void No::alocaVetPonteiro(int q)
{
    this->vetPonteiro = new No*[q];

    for(int i=0; i<(q-1); i++)
    {
        this->vetPonteiro[i] = NULL;
    }
}
