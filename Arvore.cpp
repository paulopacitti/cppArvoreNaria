#include "No.h"
#include "Arvore.h"
#include <iostream>


Arvore::Arvore(int tamanho) throw()
{
    if(int tamanho > 0)
        this->raiz = new No(tamanho);
    else
        throw "Tamanho tem que ser maior que 0";
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

void Arvore::excluir(Elemento* e)
{
    try
    {
        this->raiz->excluirElemento(e);
    }
    catch
    {
        cout << "Arvore não existe";
    }
}



