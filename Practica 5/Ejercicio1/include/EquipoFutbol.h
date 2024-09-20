#ifndef EQUIPOFUTBOL_H
#define EQUIPOFUTBOL_H
#include <string>
#include "Equipo.h"

class EquipoFutbol : public Equipo
{
    public:
        const unsigned int cupo= 11;

    public:
        EquipoFutbol(std::string);
        ~EquipoFutbol();
        bool agregarIntegrante(Jugador&);
        bool eliminarIntegrante(Jugador&);
};

#endif // EQUIPOFUTBOL_H
