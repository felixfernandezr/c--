#include "EquipoFutbol.h"
#include <string>

EquipoFutbol::EquipoFutbol(std::string nom) : Equipo(nom) {}

EquipoFutbol::~EquipoFutbol() {}

bool EquipoFutbol::agregarIntegrante(Jugador& unJugador)
{
    auto pos= this->integrantes.find(&unJugador);

    if(pos == this->integrantes.end())
    {
        this->integrantes.insert(&unJugador);

        return true;
    }
    else
        return false;
}

bool EquipoFutbol::eliminarIntegrante(Jugador& unJugador)
{
    auto pos= this->integrantes.find(&unJugador);

    if(pos == this->integrantes.end())
    {
        return false;
    }
    else
    {
        this->integrantes.erase(&unJugador);

        return true;
    }
}
