#include "Pasajero.h"
#include "tiposDocumentos.h"
#include <string>

Pasajero::Pasajero()
{
    this -> apellidoNombre = "";
    this -> numeroDocumento = 0;
    this -> ciudadResidencia = "";
};

Pasajero::Pasajero(std::string apeNom, tiposDocumentos tDoc, unsigned int nDoc, std::string cRes)
{
    this -> apellidoNombre = apeNom;
    this -> tipoDocumento = tDoc;
    this -> numeroDocumento = nDoc;
    this -> ciudadResidencia = cRes;
}

Pasajero::~Pasajero()
{

}

    std::string Pasajero::setApeNom(std::string apeNom)
    {
        this -> apellidoNombre = apeNom;

        return this -> apellidoNombre;
    }

    std::string Pasajero::getApeNom()
    {
        return this -> apellidoNombre;
    }

    std::string Pasajero::setTipoDoc(tiposDocumentos tDoc)
    {
        this -> tipoDocumento = tDoc;
    }

    std::string Pasajero::getTipoDoc()
    {
        return tDocATexto(this -> tipoDocumento);
    }

    unsigned int Pasajero::setNumDoc(unsigned int nDoc)
    {
        this -> numeroDocumento = nDoc;
    }

    unsigned int Pasajero::getNumDoc()
    {
        return this -> numeroDocumento;
    }

    std::string Pasajero::setCiudRes(std::string cRes)
    {
        this -> ciudadResidencia = cRes;
    }

    std::string Pasajero::getCiudRes()
    {
        return this -> ciudadResidencia;
    }

