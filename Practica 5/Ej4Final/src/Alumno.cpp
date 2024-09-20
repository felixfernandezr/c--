#include "Alumno.h"

Alumno::Alumno(std::string nombre)
{
    this->nombre=nombre;
}

Alumno ::~Alumno ()
{
    //dtor
}

std::string Alumno::getNombre()
{
    return this->nombre;
}
