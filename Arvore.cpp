#include "No.h"
#include "Arvore.h"
#include <iostream>


Arvore::Arvore(int tamanho) throw()
{
    if(tamanho > 0)
    {
        this->raiz = new No(tamanho);
        this->n = tamanho;
    }

    else
        throw "Tamanho tem que ser maior que 0";
}

Arvore::~Arvore()
{
    this->raiz->~No();
    delete this->raiz;
}

void Arvore::incluir(Elemento* e) throw()
{
    this->raiz->incluir(e);
}

void Arvore::excluir(Elemento* e) throw()
{
    try
    {
        this->raiz->excluir(e);
    }
    catch(void* e)
    {
         std::cout << "Arvore não existe";
    }

}



