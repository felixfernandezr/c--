#ifndef ALUMNOPREGRADO_H
#define ALUMNOPREGRADO_H
#include <string>
#include "Alumno.h"

class AlumnoPregrado : public Alumno
{
    public:
        AlumnoPregrado(std::string);
        ~AlumnoPregrado();
        double calcularCuota(double) override;
};

#endif // ALUMNOPREGRADO_H
