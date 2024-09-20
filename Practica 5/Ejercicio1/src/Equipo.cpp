#include "Equipo.h"
#include <string>
#include <set>

Equipo::Equipo(std::string nom)
{
    std::set<Jugador*> integrantes;
    this->nombre= nom;
}

Equipo::~Equipo() {}

std::string Equipo::getNombre() { return this->nombre; }

unsigned int Equipo::cantidadIntegrantes()
{
    return this->integrantes.size();
}

std::string Equipo::csvIntegranes()
{
    std::string csvi= "";
    for(auto it= this->integrantes.begin() ; it!= this->integrantes.end() ; ++it)
    {
        csvi= csvi + (*it)->getNombre() + ",";
    }

    if (!csvi.empty()) {
        csvi.pop_back();
    }

    return csvi;
}
