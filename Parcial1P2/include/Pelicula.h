#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include "Actor.h"

class Pelicula
{
    private:
        std::string titulo;
        unsigned int anioEstreno;
        Actor * elenco[100];

    public:
        Pelicula(std::string titulo, unsigned int anioEstreno);
        ~Pelicula();
        unsigned int getAnioEstreno();
        std::string getTitulo();
        bool actua (Actor & unActor);
        bool agregarActor (Actor & unActor);
        bool eliminarActor (Actor & unActor);
        Actor * operator[] (unsigned int i);
        unsigned int cantidadElenco();
    private:
        unsigned int contarElencoRec(Actor ** arr);
};

#endif // PELICULA_H
