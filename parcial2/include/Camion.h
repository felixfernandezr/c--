#ifndef _CAMION_H
#define _CAMION_H

#include <string>
#include "Vehiculo.h"

class Camion: public Vehiculo {
    private:
        double costoKilometro;
    public:
        Camion(std::string patente, double costoKilometro);
        void setCostoKilometro(double costo);
        double getCostoKilometro();
        double calcularCosto();
};

#endif //_CAMION_H
