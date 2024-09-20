#ifndef DUPLA_H
#define DUPLA_H


template <class T> class Dupla
{
    private:
        T x;
        T y;

    public:
        Dupla(T x, T y);
        T & operator[](unsigned int i);
};

template <class T> Dupla<T>::Dupla(T x, T y)
{
    this -> x = x;
    this -> y = y;
}

template <class T> T& Dupla<T>::operator[](unsigned int i)
{
    switch(i)
    {
        case 0: return this -> x;
        case 1: return this -> y;
        default: throw;
    }
}


#endif // DUPLA_H
