#include "Alumno .h"
using namespace std;
Alumno ::Alumno (string nombre)
{
    this->nombre=nombre;
}

Alumno ::~Alumno ()
{
    //dtor
}

string Alumno::getNombre()
{
    return this->nombre;
}
