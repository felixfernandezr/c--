#ifndef VIAJE_H
#define VIAJE_H
#include <string>
#include "Pasajero.h"

class Viaje
{
    private:
        std::string ciudadOrigen;
        std::string ciudadDestino;
        unsigned int cantidadLugaresTotales;
        Pasajero ** ocupacion;


    public:
        Viaje(std::string cOri, std::string cDes, unsigned int cLugares);
        ~Viaje();
        std::string getCiudadOrigen();
        std::string getCiudadDestino();
        unsigned int getCantidadLugaresTotal();
        unsigned int venderPasaje(std::string, tiposDocumentos, unsigned int, std::string);
        bool devolverPasajes(Pasajero &);
        bool devolverPasaje(unsigned int);
        bool esLugarOcupado(unsigned int);
        unsigned int obtenerPasajesVendidos();
        Pasajero * operator [] (unsigned int);
};

#endif // VIAJE_H
