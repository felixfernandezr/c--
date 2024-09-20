#include "Universidad.h"
#include <iostream>

Universidad::Universidad(double cuota) : cuotaPorMateria(cuota) {}

Universidad::~Universidad() { std::cout<<"Destr UNIVERSIDAD"<<std::endl; }

void Universidad::inscribir(Alumno& unAlumno)
{
    if(!this->estaInscripto(unAlumno))
    {
        this->alumnos.insert(&unAlumno);
    }
    else
        throw "const char";
}

void Universidad::desinscribir(Alumno& unAlumno)
{
    if(this->estaInscripto(unAlumno))
    {
        this->alumnos.erase(&unAlumno);
    }
    else
        throw "const char";
}

unsigned int Universidad::cantidadAlumnos()
{
    return this->alumnos.size();
}

bool Universidad::estaInscripto(Alumno& unAlumno)
{
    auto it= this->alumnos.find(&unAlumno);
    if(it == this->alumnos.end())
    {
        return false;
    }
    else
        return true;
}

double Universidad::calcularIngresosCuota()
{
    double ingresosTotales= 0;
    auto it= this->alumnos.begin();
    while(it != this->alumnos.end())
    {
        ingresosTotales+= (*it)->calcularCuota(this->cuotaPorMateria);
        ++it;
    }

    return ingresosTotales;
}
