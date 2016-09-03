#ifndef NO
#define NO
#include "Elemento.h"
#include <stdlib.h>

class No
{
    public:
        No(int qtdElementoPorNo); //tamanho do vetor de Elemento, lembrando que o vetor de ponteiros é sempre uma posição maior
        virtual ~No(); //destrutor

        Elemento* getElemento(unsigned int index) const;//retorna a Elemento de uma determinada Elemento
        void setElemento(unsigned int index, Elemento* e);

        No* getPonteiro(unsigned int index) const;//retorna o próximo elemento
        void setPonteiro(unsigned int i, No* n);

        bool addElemento(Elemento* e);
        bool excluirElemento(Elemento* e) throw();

        unsigned int getQtdElemento() const;
        unsigned int getQtdMax() const;
        bool isCompleto() const;
        bool existe(Elemento* e);
        int getIndex(Elemento* e) const;


    private:
     Elemento** vetElemento; //são dois * porque é um vetor de ponteiro
     No** vetPonteiro; //vetor de ponteiros
     unsigned int qtdElemento; //qtd de Elementos que o vetor realmente tem
     unsigned int qtdMax; //tamanho vetor


     void alocaVetElemento(int q);
     void alocaVetPonteiro(int q);
     void ordenarVetElemento();

     int qualNo(Elemento* e);
     int whereNo(Elemento* e);
};

#endif
