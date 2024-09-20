#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>
#include <set>
#include "Jugador.h"

class Equipo
{
    protected:
        std::string nombre;
        std::set<Jugador*> integrantes;

    public:
        Equipo(std::string);
        ~Equipo();
        std::string getNombre();
        unsigned int cantidadIntegrantes();
        std::string csvIntegranes();
};

#endif // EQUIPO_H
