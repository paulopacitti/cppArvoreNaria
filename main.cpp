#include <iostream>
#include "Arvore.h"

using namespace std;

int main()
{
    int tamanho;

    cout << "Digite o tamanho da arvore: ";
    cin >> tamanho;

    Arvore a(tamanho);
    Elemento* e = new Elemento(0);
    Elemento* f = new Elemento(1);
    Elemento* g = new Elemento(-2);
    Elemento* h = new Elemento(10);
    Elemento* i = new Elemento(8);
    Elemento* j = new Elemento(-3);

    a.incluir(e);
    a.incluir(f);
    a.incluir(g);
    a.incluir(h);
    a.incluir(i);
    a.incluir(j);

   // a.excluir(e);
  //  a.excluir(f);
  //  a.excluir(g);

    cout << a;
}
