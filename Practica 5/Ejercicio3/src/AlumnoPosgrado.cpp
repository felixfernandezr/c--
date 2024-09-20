#include "AlumnoPosgrado.h"
#include <iostream>

AlumnoPosgrado::AlumnoPosgrado(std::string nombre) : Alumno(nombre) {}

AlumnoPosgrado::~AlumnoPosgrado() { std::cout<<"Destr POSGRADO"<<std::endl; }

double AlumnoPosgrado::calcularCuota(double valorCuota)
{
    unsigned int cantMats= this->getCantidadMaterias();
    if(cantMats <= 3)
    {
        return valorCuota * cantMats;
    }
    else if(cantMats > 3)
    {
        return (valorCuota * cantMats) * 0.7;
    }
}
