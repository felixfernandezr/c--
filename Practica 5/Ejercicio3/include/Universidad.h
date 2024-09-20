#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include <set>
#include <string>
#include "Alumno.h"
#include "AlumnoPosgrado.h"
#include "AlumnoPregrado.h"
#include "AlumnoGrado.h"

class Universidad
{
    private:
        std::set<Alumno*> alumnos;
        double cuotaPorMateria;

    public:
        Universidad(double);
        ~Universidad();
        void setCuotaPorMateria(double val) { cuotaPorMateria= val; }
        double getCuotaPorMateria() { return cuotaPorMateria; }
        void inscribir(Alumno&);
        void desinscribir(Alumno&);
        unsigned int cantidadAlumnos();
        bool estaInscripto(Alumno&);
        double calcularIngresosCuota();
};

#endif // UNIVERSIDAD_H
