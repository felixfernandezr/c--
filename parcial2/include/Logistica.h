#ifndef _LOGISTICA_H
#define _LOGISTICA_H
#include <set>
#include "Vehiculo.h"

class Logistica {
    private:
        std::set <Vehiculo *> flota;
    public:
        Logistica();
        void agregarVehiculo(Vehiculo &unVehiculo);
        void eliminarVehiculo(Vehiculo &unVehiculo);
        bool estaVehiculo(Vehiculo &unVehiculo);
        double calcularCostoTotal();
};

#endif //_LOGISTICA_H
