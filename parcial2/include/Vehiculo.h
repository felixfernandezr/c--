#ifndef _VEHICULO_H
#define _VEHICULO_H

#include <string>

class Vehiculo {
    private:
        double kilometraje;
        std::string patente;
    public:
        Vehiculo(std::string patente);
        double getKilometraje();
        std::string getPatente();
        void setKilometraje(double km);
        virtual double calcularCosto() = 0;
};

#endif //_VEHICULO_H
