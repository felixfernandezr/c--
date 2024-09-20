#ifndef ALUMNOPOSGRADO_H
#define ALUMNOPOSGRADO_H
#include <string>
#include "Alumno.h"

class AlumnoPosgrado : public Alumno
{
    public:
        AlumnoPosgrado(std::string);
        ~AlumnoPosgrado();
        double calcularCuota(double) override;
};

#endif // ALUMNOPOSGRADO_H
