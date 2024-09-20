#include <string>
#include <iostream>
#include "Alumno.h"

Alumno::Alumno(std::string nombre) : nombre(nombre) {}

Alumno::~Alumno() { std::cout<<"Destr ALUMNO"<<std::endl; }

void Alumno::inscribirMateria()
{
    this->cantidadMaterias++;
}

void Alumno::desinscribirMateria()
{
    this->cantidadMaterias--;
}

double Alumno::calcularCuota(double valorCuota)
{
    return this->cantidadMaterias * valorCuota;
}
