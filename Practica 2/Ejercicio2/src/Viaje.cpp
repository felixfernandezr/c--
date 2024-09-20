#include "Viaje.h"
#include <string>
#include "Pasajero.h"
#include <iostream>

Viaje::Viaje(std::string cOri, std::string cDes, unsigned int cLugares)
{
    this -> ciudadOrigen = cOri;
    this -> ciudadDestino = cDes;
    this -> cantidadLugaresTotales = cLugares;
    this -> ocupacion = new Pasajero*[cantidadLugaresTotales];

    for(unsigned int i = 0 ; i < cantidadLugaresTotales ; i++)
    {
        this -> ocupacion[i] = nullptr;
    }
}

Viaje::~Viaje()
{
    for(unsigned int i = 0 ; i < this -> cantidadLugaresTotales ; i++)
    {
        this -> ocupacion[i] =  nullptr;
    }

    delete [] this -> ocupacion;
}

std::string Viaje::getCiudadOrigen()
{
    return this -> ciudadOrigen;
}

std::string Viaje::getCiudadDestino()
{
    return this -> ciudadDestino;
}

unsigned int Viaje::getCantidadLugaresTotal()
{
    return this -> cantidadLugaresTotales;
}


unsigned int Viaje::venderPasaje(std::string apeNom, tiposDocumentos tDoc, unsigned int nDoc, std::string cRes)
{
    for( unsigned int i = 0 ; i < this -> cantidadLugaresTotales ; i++ )
    {
        if(this -> ocupacion[i] == nullptr)
        {
            this -> ocupacion[i] = new Pasajero(apeNom, tDoc, nDoc, cRes);

            return i + 1;
        }
        else if(i == (this -> cantidadLugaresTotales - 1) && this -> ocupacion[i] != nullptr)
        {
            return 0;
        }
    }
}


bool Viaje::devolverPasajes(Pasajero& unPasajero)
{
    std::cout << "Devolver pasaje: ";

    for( unsigned int i = 0 ; i < this -> cantidadLugaresTotales ; i++ )
    {
        if(this -> ocupacion[i] -> getApeNom() == unPasajero.getApeNom() && this -> ocupacion[i] -> getNumDoc() == unPasajero.getNumDoc())
        {
            this -> ocupacion[i] = nullptr;

            return true;
        }
    }

    return false;
}

bool Viaje::devolverPasaje(unsigned int nroLugar)
{
    std::cout << "Devolver pasaje: ";

    nroLugar--;

    this -> ocupacion[nroLugar] = nullptr;

    return true;
}


bool Viaje::esLugarOcupado(unsigned int numAsiento)
{
    std::cout << "Lugar ocupado: ";
    numAsiento--;
    if(this -> ocupacion[numAsiento] == nullptr)
    {
        return false;
    }

    return true;
}

unsigned int Viaje::obtenerPasajesVendidos()
{
unsigned int cantOcupados = 0;

    std::cout << "Obtener Pasajes: ";
    for( unsigned int i = 0 ; i < this -> cantidadLugaresTotales ; i++)
    {
        if(this -> ocupacion[i] != nullptr)
        {
            cantOcupados++;
        }
    }

    return cantOcupados;
}

Pasajero * Viaje::operator [] (unsigned int numLug)
{
    numLug--;

    return this -> ocupacion[numLug];
}


