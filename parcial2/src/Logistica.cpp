#include "Logistica.h"

Logistica::Logistica() {}

void Logistica::agregarVehiculo(Vehiculo & unVehiculo)
{
    if(!this->estaVehiculo(unVehiculo))
    {
        this->flota.insert(&unVehiculo);
    }
    else
        throw "vehiculo ya existe";
}

void Logistica::eliminarVehiculo(Vehiculo& unVehiculo)
{
    /**
    Cuando intente eliminarse unVehiculo que no está en la flota, lanzar una excepción con un mensaje de texto.
    */
    if(this->estaVehiculo(unVehiculo))
    {
        this->flota.erase(&unVehiculo);
    }
    else
        throw "vehiculo no existe";
}

bool Logistica::estaVehiculo(Vehiculo & unVehiculo)
{
    auto it= this->flota.find(&unVehiculo);
    if(it == this->flota.end())
    {
        return false;
    }
    else
        return true;
}

double Logistica::calcularCostoTotal()
{
    /**
    Sumatoria de los costos de todos los vehículos de la flota
    */
    double costoTotal= 0;
    auto it= this->flota.begin();
    while(it != this->flota.end())
    {
        costoTotal+= (*it)->calcularCosto();
        ++it;
    }

    return costoTotal;
}
