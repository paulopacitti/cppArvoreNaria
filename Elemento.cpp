#include "Elemento.h"

Elemento::Elemento(const int& v)
{
	this->setValor(v);
}

int Elemento::getValor()
{
	return this->valor;
}

void Elemento::setValor(const int& v)
{
	this->valor = v;
}

int Elemento::compareTo(Elemento* e)
{
	if(this->valor > e->getValor())
		return 1;
	if(this->valor < e->getValor())
		return -1;
	else
		return 0;
}
