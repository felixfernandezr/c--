#include <string>
#include "Alumno.h"

Alumno::Alumno(std::string nom)
{
    this -> nombre = nom;
}

Alumno::~Alumno() {}

std::string Alumno::getNombre()
{
    return this -> nombre;
}
