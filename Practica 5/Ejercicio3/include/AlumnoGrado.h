#ifndef ALUMNOGRADO_H
#define ALUMNOGRADO_H
#include <string>
#include "Alumno.h"

class AlumnoGrado : public Alumno
{
    public:
        AlumnoGrado(std::string);
        ~AlumnoGrado();
        double calcularCuota(double) override;
};

#endif // ALUMNOGRADO_H
