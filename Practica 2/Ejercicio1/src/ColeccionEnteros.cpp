#include "ColeccionEnteros.h"

ColeccionEnteros::ColeccionEnteros()
{
    this -> reservado = this -> tamanioReserva;
    this -> utilizado = 0;
    this -> valores = new int [this -> tamanioReserva];

}

ColeccionEnteros::~ColeccionEnteros()
{
    delete [] this -> valores;
}

bool ColeccionEnteros::agregarInicio(int unValor)
{
    for (unsigned int i = this -> utilizado ; i > 0 ; i--)
    {
        this -> valores[i] = this -> valores[i - 1];
    }
    this -> valores[0] = unValor;
    this -> utilizado++;
    this -> redimensionar();

    return true;
}

bool ColeccionEnteros::agregarFinal(int unValor)
{
    this -> valores[this -> utilizado] = unValor;
    this -> utilizado++;
    this -> redimensionar();

    return true;
}

bool ColeccionEnteros::eliminarPrimero(int unValor)
{
    unsigned int i;

    for(i = 0 ; i <= this -> utilizado && this -> valores[i] != unValor ; i++);
    if(i < this -> utilizado)
    {
        for(; i < this -> utilizado ; i++)
        {
            this -> valores[i] = this -> valores[i + 1];
        }
        this -> utilizado--;
        this -> redimensionar();

        return true;
    }
    else if(i == this -> utilizado)
    {
        this -> utilizado--;
        this -> redimensionar();

        return true;
    }
    else
        return false;

}

    /*for(unsigned int i = 0 ; i < this -> utilizado ; i++)
    {
        if(this -> valores[i] == unValor)
        {
            for(; i < this -> utilizado; i++)
            {
                this -> valores[i] = this -> valores[i + 1];
            }
            this -> utilizado--;
            this -> redimensionar();
            return true;
        }
    }
}*/

bool ColeccionEnteros::eliminarUltimo(int unValor)
{
    unsigned int i;

    for(i = this -> utilizado ; i >= 0 && this -> valores[i] != unValor ; i--);
    if (i > 0)
    {
        for(; i < this -> utilizado ; i++)
        {
            this -> valores[i] = this -> valores[i + 1];
        }
        this -> utilizado--;
        this -> redimensionar();

        return true;
    }
    else
        return false;
}

unsigned int ColeccionEnteros::eliminarTodos(int unValor)
{
    int cont = 0;

    while(this -> eliminarPrimero(unValor))
    {
        cont++;
    }

    return cont;
}

    /*for(unsigned int i = 0 ; i < this -> utilizado ; i++)
    {
        if(this -> valores[i] == unValor)
        {
            for(unsigned int j = i ; j < this -> utilizado ; j++)
            {
                this -> valores[j] = this -> valores[j + 1];
            }
            this -> utilizado--;
            this -> redimensionar();
        }
    }

    return true;
}*/

unsigned int ColeccionEnteros::cantidadvalores(int unValor)
{
    int cont = 0;

    for(unsigned int i = 0 ; i < this -> utilizado ; i++)
    {
        if(this -> valores[i] == unValor)
        {
            cont++;
        }
    }

    return cont;
}

int ColeccionEnteros::operator [] (unsigned int i)
{
    return this -> valores[i];
}

void ColeccionEnteros::redimensionar()
{
    if(this -> reservado == this -> utilizado)
    {
        this -> reservado += this -> tamanioReserva;
        int * aux = new int [this ->  reservado];
        for (unsigned int i = 0 ; i < this -> utilizado ; i++)
        {
            aux[i] = this -> valores[i];
        }
        delete [] this -> valores;
        this -> valores = aux;
    }
    else if(this -> reservado - this -> utilizado > this -> tamanioReserva)
    {
        this -> reservado -= this -> tamanioReserva;
        int * aux = new int [this ->  reservado];
        for (unsigned int i = 0 ; i < this -> utilizado ; i++)
        {
            aux[i] = this -> valores[i];
        }
        delete [] this -> valores;
        this -> valores = aux;
    }
}



