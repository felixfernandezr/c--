#include "EquipoBasquet.h"
#include <string>

EquipoBasquet::EquipoBasquet(std::string nom) : Equipo(nom) {}

EquipoBasquet::~EquipoBasquet() {}

bool EquipoBasquet::agregarIntegrante(Jugador& unJugador)
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

bool EquipoBasquet::eliminarIntegrante(Jugador& unJugador)
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

