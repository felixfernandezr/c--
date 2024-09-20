#include "Camioneta.h"

Camioneta::Camioneta(std::string patente, double costoService10K) : Vehiculo(patente)
{
    this->costoService10K= costoService10K;
}

void Camioneta::setCostoService10K(double costo)
{
    /**
    Cuando el parámetro sea negativo, lanzar una excepción con un mensaje de texto.
    */
    if(costo < 0)
    {
        throw "valor menor a 0";
    }
    else
    {
        this->costoService10K= costo;
    }
}

double Camioneta::getCostoService10K()
{
    return this->costoService10K;
}

double Camioneta::calcularCosto()
{
    /**
    El costo de mantenimiento depende de un service que se le hace a la camioneta cada 10.000 Km.
    Es decir, a partir de 10.000 y con menos de 20.000 se paga 1 costoService10K.
    De 20.000 y con menos de 30.000 se pagan 2 costoService10K.
    De 30.000 y con menos de 40.000 se pagan 3 costoService10K.
    Y así sucesivamente.
    */
    int tipoService= this->getKilometraje() / 10000;

    return this->getCostoService10K() * tipoService;
}
