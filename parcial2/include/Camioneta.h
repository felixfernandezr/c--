#ifndef _CAMIONETA_H
#define _CAMIONETA_H

#include <string>
#include "Vehiculo.h"

class Camioneta: public Vehiculo {
    private:
        double costoService10K;
    public:
        Camioneta(std::string patente, double costoService10K);
        void setCostoService10K(double costo);
        double getCostoService10K();
        double calcularCosto();
};

#endif //_CAMIONETA_H
