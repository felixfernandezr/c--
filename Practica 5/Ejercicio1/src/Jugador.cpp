#include "Jugador.h"
#include <string>

Jugador::Jugador(std::string nom)
{
    this->nombre= nom;
}

Jugador::~Jugador() {}

std::string Jugador::getNombre() { return this->nombre; }
