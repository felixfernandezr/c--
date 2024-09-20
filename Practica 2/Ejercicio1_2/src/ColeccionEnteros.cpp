#include "ColeccionEnteros.h"

ColeccionEnteros::ColeccionEnteros()
{
    this->valores = new int [this->tamanoReserva];
    this->reservado = this->tamanoReserva;
    this->utilizado = 0;
}

ColeccionEnteros::~ColeccionEnteros()
{
    delete [] this->valores;
}

bool ColeccionEnteros::agregarInicio(int unValor)
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

bool ColeccionEnteros::agregarFinal(int unValor)
{
    this->valores[this->utilizado] = unValor;
    this->utilizado++;
    this->redimensionar();
    return true;
}

bool ColeccionEnteros::eliminarPrimero(int unValor)
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

bool ColeccionEnteros::eliminarUltimo(int unValor)
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

unsigned int ColeccionEnteros::eliminarTodos(int unValor)
{
    unsigned int cont = 0;
    while(this->eliminarPrimero(unValor))
    {
        cont++;
    }
    return cont;
}

unsigned int ColeccionEnteros::cantidadValores()
{
    return this->utilizado;
}

int ColeccionEnteros::operator[] (unsigned int i)
{
    return this->valores[i];
}

void ColeccionEnteros::redimensionar()
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

