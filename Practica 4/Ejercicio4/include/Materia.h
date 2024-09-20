#ifndef MATERIA_H
#define MATERIA_H
#include <string>
#include <set>
#include "Alumno.h"

class Materia
{
    private:
        std::string nombre;
        unsigned int cupo;
        std::set<Alumno *> inscriptos;

    public:
        Materia(std::string, unsigned int);
        ~Materia();
        std::string getNombre();
        bool inscribir(Alumno &);
        bool desinscribir(Alumno &);
        unsigned int cantdadInscriptos();
        unsigned int cupoDisponible();
        std::string csvInscriptos();
};

#endif // MATERIA_H
