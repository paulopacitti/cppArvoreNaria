#ifndef ELEMENTO
#define ELEMENTO

class Elemento
{
    private:
        int valor; // char valor [50]; ou o que for

    public:
    	Elemento(const int& v);

    	int getValor();
        void setValor(const int& v);
        int compareTo (Elemento* e);
};
#endif
