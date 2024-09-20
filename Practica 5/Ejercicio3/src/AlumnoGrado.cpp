#include "AlumnoGrado.h"
#include <iostream>

AlumnoGrado::AlumnoGrado(std::string nombre) : Alumno(nombre) {}

AlumnoGrado::~AlumnoGrado() { std::cout<<"Destr GRADO"<<std::endl; }

double AlumnoGrado::calcularCuota(double valorCuota)
{
    unsigned int cantMats= this->getCantidadMaterias();
    if(cantMats < 4)
    {
        return valorCuota * cantMats;
    }
    else if(cantMats >= 4 && cantMats <= 6)
    {
        return (valorCuota * cantMats) * 0.9;
    }
    else if(cantMats > 6)
    {
        return (valorCuota * cantMats) * 0.85;
    }
}
