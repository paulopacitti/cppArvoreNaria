#ifndef ARVORE_H
#define ARVORE_H
#include "No.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
class Arvore
{
    public:
        Arvore(int tamanho) throw();
        No* raiz;
        virtual ~Arvore();
        void incluir(Elemento* e)throw();
        bool excluir(Elemento* e) throw();
        void printArvore() throw();
        friend std::ostream& operator<< (std::ostream& saida, Arvore a); //printa a �rvore com cout<<arvore

    private:
        No* raiz;
        int tamanho;
        void incluirAux(No* raiz, Elemento* e) throw();
        bool isFolha(No* raiz) const throw();
        No* pesquisar(No* raiz, No** ant, Elemento* e) const throw();
        void limpaArvoreAux(No* raiz) throw();
        No* getMaisPerto(No* raiz, Elemento* e) throw();
        void printArvoreAux(No* raiz) throw();
        No* rearranja(No* raiz, No* origem, unsigned int i, unsigned int atual) throw();
        bool excluirAux(No* raiz, Elemento* e) throw();
        std::ostream& auxPrint(ostream& saida, No* raiz) throw();
};

extern std::ostream& operator<< (std::ostream& saida, Arvore a); //indica que esta fun��o est� solta no cpp

#endif // ARVORE_H
