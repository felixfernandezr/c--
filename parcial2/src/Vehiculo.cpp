#include "Vehiculo.h"

Vehiculo::Vehiculo(std::string patente)
{
    /**
    Todos los vehículos se construyen con kilometraje cero.
    */
    this->kilometraje= 0;
    this->patente= patente;
}

double Vehiculo::getKilometraje()
{
    return this->kilometraje;
}

std::string Vehiculo::getPatente()
{
    return this->patente;
}

void Vehiculo::setKilometraje(double km)
{
    /**
    Cuando el parámetro sea negativo, lanzar una excepción con un mensaje de texto.
    */
    this->kilometraje= km;
}
