#ifndef EQUIPOBASQUET_H
#define EQUIPOBASQUET_H
#include <string>
#include "Equipo.h"

class EquipoBasquet : public Equipo
{
    public:
        const unsigned int cupo= 11;

    public:
        EquipoBasquet(std::string);
        ~EquipoBasquet();
        bool agregarIntegrante(Jugador&);
        bool eliminarIntegrante(Jugador&);
};

#endif // EQUIPOBASQUET_H
