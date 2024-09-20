#ifndef TUPLA_H
#define TUPLA_H


template <class T, unsigned int N> class Tupla
{
    private:
        T valores[N];

    public:
        Tupla();
        T & operator[](unsigned int i);
};

template <class T, unsigned int N> Tupla<T,N>::Tupla()
{
}

template <class T, unsigned int N> T& Tupla<T,N>::operator[](unsigned int i)
{
    if(i < 0 || i > N)
    {
        throw;
    }

    return this -> valores[i];
}


#endif // TUPLA_H
