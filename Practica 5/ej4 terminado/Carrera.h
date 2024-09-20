#ifndef CARRERA_H
#define CARRERA_H
#include<string>
#include"Materia.h"
#include<vector>
#include<set>
class Carrera
{
    public:
        Carrera(std::string nombre);
        ~Carrera();
        Materia& crearMateria(std::string nombreMat, unsigned int cupoMat);
        Materia& obtenerMateria(std::string nombreMat);
        bool eliminarMateria(Materia& unaMateria);
        Alumno& anotarAlumno(std::string unNombre);
        bool desanotarAlumno(Alumno& unAlumno);
        bool inscribirCursada(Alumno& unAlumno, Materia& unaMateria);
        bool desinscribirCursada(Alumno& unAlumno, Materia& unaMateria);
        unsigned int cantidadMaterias();
        unsigned int cantidadAlumnado();
    private:
        std::string nombre;
        std::vector<Materia> materias;
        std::set<Alumno*> alumnado;
};

#endif // CARRERA_H
