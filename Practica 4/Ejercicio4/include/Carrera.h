#ifndef CARRERA_H
#define CARRERA_H
#include <string>
#include <vector>
#include <set>
#include "Materia.h"

class Carrera
{
    private:
        std::string nombre;
        std::vector<Materia *> materias;
        std::set<Alumno *> alumnado;

    public:
        Carrera(std::string);
        ~Carrera();
        Materia & crearMateria(std::string, unsigned int);
        Materia & obtenerMateria(std::string);
        bool eliminarMateria(Materia &);
        Alumno & anotarAlumno(std::string);
        bool desanotarAlumno(Alumno &);
        bool inscribirCursada(Alumno &, Materia &);
        bool desinscribirCursada(Alumno &, Materia &);
        unsigned int cantidadMaterias();
        unsigned int cantidadAlumnado();
};

#endif // CARRERA_H
