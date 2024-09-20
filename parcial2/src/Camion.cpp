#include "Camion.h"

Camion::Camion(std::string patente, double costoKilometro): Vehiculo(patente)
{
    this->costoKilometro= costoKilometro;
}

void Camion::setCostoKilometro(double costo)
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
        this->costoKilometro= costo;
    }
}

double Camion::getCostoKilometro()
{
    return this->costoKilometro;
}

double Camion::calcularCosto()
{
    /**
    El costo se calcula multiplicando el kilometraje por el costoKilometro del Camión.
    */
    return this->getKilometraje() * this->getCostoKilometro();
}
