#include "AlumnoPregrado.h"
#include <iostream>

AlumnoPregrado::AlumnoPregrado(std::string nombre) : Alumno(nombre) {}

AlumnoPregrado::~AlumnoPregrado() { std::cout<<"Destr PREGRADO"<<std::endl; }

double AlumnoPregrado::calcularCuota(double valorCuota)
{
    unsigned int cantMats= this->getCantidadMaterias();
    if(cantMats < 5)
    {
        return valorCuota * cantMats;
    }
    else
    {
        return valorCuota * 5;
    }
}
