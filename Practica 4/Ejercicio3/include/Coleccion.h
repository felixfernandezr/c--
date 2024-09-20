#ifndef COLECCION_H
#define COLECCION_H


template <class T> class Coleccion
{
    private:
        unsigned int reservado;
        unsigned int utilizado;
        const unsigned int tamanoReserva = 5;
        const unsigned int maximoDesperdicio = 8;
        int * valores;

    public:
        Coleccion();
        ~Coleccion();

        unsigned int getReservado() { return this->reservado ;}
        unsigned int getUtilizado() { return this->utilizado ;}
        unsigned int getTamanoReserva() { return this->tamanoReserva ;}
        unsigned int getMaximoDesperdicio() { return this->maximoDesperdicio ;}

        bool agregarInicio(int unValor);
        bool agregarFinal(int unValor);
        bool eliminarPrimero(int unValor);
        bool eliminarUltimo(int unValor);
        unsigned int eliminarTodos(int unValor);
        unsigned int cantidadValores();
        T& operator[] (unsigned int i);
    private:
        void redimensionar();

};

template <class T> Coleccion<T>::Coleccion()
{
    this->valores = new int [this->tamanoReserva];
    this->reservado = this->tamanoReserva;
    this->utilizado = 0;
}

template <class T> Coleccion<T>::~Coleccion()
{
    delete [] this->valores;
}

template <class T> bool Coleccion<T>::agregarInicio(int unValor)
{
    for (unsigned int i=this->utilizado; i>0; i--)
    {
        this->valores[i] = this->valores[i-1];
    }
    this->valores[0] = unValor;
    this->utilizado++;
    this->redimensionar();
    return true;
}

template <class T> bool Coleccion<T>::agregarFinal(int unValor)
{
    this->valores[this->utilizado] = unValor;
    this->utilizado++;
    this->redimensionar();
    return true;
}

template <class T> bool Coleccion<T>::eliminarPrimero(int unValor)
{
    unsigned int i;
    for (i=0; i<this->utilizado && this->valores[i]!=unValor; i++);
    if (i==this->utilizado)
    {
        return false;
    }
    for (; i<this->utilizado; i++)
    {
        this->valores[i]=this->valores[i+1]; // En la última pos, copia basura (pero es parte de la reserva)
    }
    this->utilizado--;
    this->redimensionar();
    return true;
}

template <class T> bool Coleccion<T>::eliminarUltimo(int unValor)
{
    unsigned int i;
    for (i=this->utilizado ; i>0 && this->valores[i]!=unValor; i--);
    if (this->valores[i]!=unValor)
    {
        return false;
    }
    for (; i<this->utilizado; i++)
    {
        this->valores[i]=this->valores[i+1]; // En la última pos, copia basura (pero es parte de la reserva)
    }
    this->utilizado--;
    this->redimensionar();
    return true;
}

template <class T> unsigned int Coleccion<T>::eliminarTodos(int unValor)
{
    unsigned int cont = 0;
    while(this->eliminarPrimero(unValor))
    {
        cont++;
    }
    return cont;
}

template <class T> unsigned int Coleccion<T>::cantidadValores()
{
    return this->utilizado;
}

template <class T> T& Coleccion<T>::operator[] (unsigned int i)
{
    return this->valores[i];
}

template <class T> void Coleccion <T>::redimensionar()
{
    if(this->reservado == this->utilizado)
    {
        // Sin espacio, hay que agrandar
        this->reservado += this->tamanoReserva;
        int * aux = new int [this->reservado];
        for (unsigned int i=0; i<this->utilizado ; i++)
        {
            aux[i] = this->valores[i];
        }
        delete [] this->valores;
        this->valores = aux;
    }
    else if (this->reservado-this->utilizado >= this->maximoDesperdicio)
    {
        this->reservado -= this->tamanoReserva;
        int * aux = new int [this->reservado];
        for (unsigned int i=0; i<this->utilizado ; i++)
        {
            aux[i] = this->valores[i];
        }
        delete [] this->valores;
        this->valores = aux;
    }
}

#endif // COLECCION_H
