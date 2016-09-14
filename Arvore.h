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
        void printArvore() throw();
        friend std::ostream& operator<< (std::ostream& saida, Arvore a); //printa a árvore com cout<<arvore

    private:
        No* raiz;
        int n;

        void incluirAux(No* raiz, Elemento* e) throw();
        bool isFolha(No* raiz) const throw();
        No* pesquisar(No* raiz, No** ant, Elemento* e) const throw();
        void limpaArvoreAux(No* raiz) throw();
        No* getMaisPerto(No* raiz, Elemento* e) throw();
        void printArvoreAux(No* raiz) throw();
        No* rearranja(No* raiz, No* origem, unsigned int i, unsigned int atual) throw();
        bool excluirAux(No* raiz, Elemento* e) throw();
        friend std::ostream& operator<< (std::ostream& saida, Arvore a);
};

extern std::ostream& operator<< (std::ostream& saida, Arvore a); //indica que esta função está solta no cpp

#endif // ARVORE_H

