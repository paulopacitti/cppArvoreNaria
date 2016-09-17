#ifndef NO
#define NO
#include "Elemento.h"
#include <stdlib.h>
#include <iostream>
#include <string>

class No
{
    public:
        No(int qtdElementoPorNo);
        No(No* outro); // construtor de cópia
        virtual ~No();

        Elemento* getElemento(unsigned int index);
        void setElemento(unsigned int index, Elemento* e);
        No* getPonteiro(unsigned int index);
        void setPonteiro(unsigned int i, No* n);

        void incluir(Elemento* e);
        void excluir(Elemento* e) throw();
        Elemento* pesquisar(Elemento* e) throw();
        std::ostream& toString(std::ostream& o);
        No& operator=(const No& n);

        unsigned int getQtdElemento() const;
        unsigned int getQtdMax() const;
        bool isCompleto() const;
        bool isFolha();
        bool existe(Elemento* e);
        int getIndex(Elemento* e) const;


    private:
     Elemento** vetElemento;
     No** vetPonteiro;
     unsigned int qtdElemento;
     unsigned int qtdMax;

     void excluirPosicao(int index) throw();
     No* pesquisarNo(Elemento* e) throw();
     void alocaVetElemento(int q);
     void alocaVetPonteiro(int q);
     void ordenarVetElemento();

     int qualNo(Elemento* e);
};

#endif
