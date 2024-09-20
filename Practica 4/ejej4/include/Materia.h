#ifndef MATERIA_H
#define MATERIA_H
#include"Alumno.h"
#include<set>
class Materia
{
    public:
        Materia(std::string nombre, unsigned int cupo);
         ~Materia();
        bool inscribir (Alumno& unAlumno);
        bool desinscribir (Alumno& unAlumno);
        unsigned int cantidadInscriptos();
        unsigned int cupoDisponible();
        std::string csvInscriptos();
        std::string getNombreMateria();
        unsigned int getCupo();
    private:
        std::string nombre;
        unsigned int cupo;
        std::set<Alumno*> inscriptos;
};

#endif // MATERIA_H
