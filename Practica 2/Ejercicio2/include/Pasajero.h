#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
#include "tiposDocumentos.h"

class Pasajero
{
    private:
        std::string apellidoNombre;
        tiposDocumentos tipoDocumento;
        unsigned int numeroDocumento;
        std::string ciudadResidencia;

    public:
        Pasajero();
        Pasajero(std::string, tiposDocumentos, unsigned int, std::string);
        ~Pasajero();
        std::string setApeNom(std::string);
        std::string getApeNom();
        std::string setTipoDoc(tiposDocumentos);
        std::string getTipoDoc();
        unsigned int setNumDoc(unsigned int);
        unsigned int getNumDoc();
        std::string setCiudRes(std::string);
        std::string getCiudRes();
};

#endif // PASAJERO_H
