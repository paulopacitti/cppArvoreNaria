#include "No.h"
#include <stdlib.h>
#include <iostream>

Arvore::Arvore(int tamanho)
{
    this->raiz = new No(tamanho);
}

Arvore::~Arvore()
{
    this->raiz->~No();
    delete this->raiz;
}


