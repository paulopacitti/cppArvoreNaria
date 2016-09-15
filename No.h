#ifndef NO
#define NO
#include "Elemento.h"
#include <stdlib.h>

class No
{
    public:
        No(int qtdElementoPorNo);
        virtual ~No();

        Elemento* getElemento(unsigned int index);
        void setElemento(unsigned int index, Elemento* e);
        No* getPonteiro(unsigned int index);
        void setPonteiro(unsigned int i, No* n);

        void incluir(Elemento* e);
        void excluir(Elemento* e) throw();
        Elemento* pesquisar(Elemento* e) throw();

        unsigned int getQtdElemento() const;
        unsigned int getQtdMax() const;
        bool isCompleto() const;
        bool existe(Elemento* e);
        int getIndex(Elemento* e) const;


    private:
     Elemento** vetElemento; //s�o dois * porque � um vetor de ponteiro
     No** vetPonteiro; //vetor de ponteiros
     unsigned int qtdElemento; //qtd de Elementos que o vetor realmente tem
     unsigned int qtdMax; //tamanho vetor


     void alocaVetElemento(int q);
     void alocaVetPonteiro(int q);
     void ordenarVetElemento();

     int qualNo(Elemento* e);
};

#endif
