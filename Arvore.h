#ifndef ARVORE_H
#define ARVORE_H
#include "No.h"
#include <stdlib.h>
#include <iostream>
class Arvore
{
    public:
        Arvore(int tamanho) throw();
        virtual ~Arvore();
        void incluir(Elemento* e)throw();
        void excluir(Elemento* e) throw();
        friend std::ostream& operator<< (std::ostream& saida, Arvore a); //printa a árvore com cout<<arvore

    private:
        No* raiz;
        int n;
};

extern std::ostream& operator<< (std::ostream& saida, Arvore a); //indica que esta função está solta no cpp

#endif // ARVORE_H

