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

    a.incluir(e);
    a.incluir(f);
    a.incluir(g);
    a.excluir(e);
    a.excluir(f);
    a.excluir(g);
}
