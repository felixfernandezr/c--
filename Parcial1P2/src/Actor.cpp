#include "Actor.h"

Actor::Actor(std::string nombre)
{
    this -> nombre = nombre;
}

Actor::~Actor()
{
}

std::string Actor::getNombre()
{
    return this -> nombre;
}

unsigned int Actor::getCantidadGalardones()
{
}

void Actor::agregarGalardon (tiposGalardones unGalardon)
{
}

void Actor::eliminarGalardon (tiposGalardones unGalardon)
{
}

unsigned int Actor::contarGalardon (tiposGalardones unGalardon)
{
    // return this->contarGalardonRec(unGalardon, this->cantidadGalardones);
}

unsigned int Actor::contarGalardonRec(tiposGalardones unGalardon, unsigned int cantidadGalardones)
{
}

void Actor::redimensionarGalardones(bool agrandar)
{
}
