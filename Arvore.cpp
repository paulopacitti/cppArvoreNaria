#include "No.h"
#include "Arvore.h"


Arvore::Arvore(int tamanho)
{
    this->raiz = new No(tamanho);
}

Arvore::~Arvore()
{
    this->raiz->~No();
    delete this->raiz;
}

void Arvore::incluir(Elemento* e)
{
    this->raiz->addElemento(e);
}



