#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(std::string titulo, unsigned int anioEstreno)
{
    this -> titulo = titulo;
    this -> anioEstreno = anioEstreno;

    this -> elenco[0] = nullptr;
}

Pelicula::~Pelicula()
{
}

unsigned int Pelicula::getAnioEstreno()
{
    return this -> anioEstreno;
}

std::string Pelicula::getTitulo()
{
    return this -> titulo;
}

bool Pelicula::actua (Actor & unActor)
{
    for(unsigned int i = 0 ; this -> elenco[i] != nullptr ; i++)
    {
        if(this -> elenco[i] == &unActor)
        {
            return true;
        }
    }

    return false;
}

bool Pelicula::agregarActor (Actor & unActor)
{
    unsigned int i;

    if(this -> actua(unActor))
    {
        return false;
    }

    for(i = 0 ; this -> elenco[i] != nullptr ; i++);

    this -> elenco[i] = &unActor;
    this -> elenco[i + 1] = nullptr;

    return true;
}

bool Pelicula::eliminarActor (Actor & unActor)
{
    unsigned int i;

    if(!this -> actua(unActor))
    {
        return false;
    }

    for(i = 0 ; this -> elenco[i] != &unActor ; i++);

    for(; this -> elenco[i] != nullptr ; i++)
    {
        this -> elenco[i] = this -> elenco[i + 1];
    }

    return true;
}

Actor * Pelicula::operator[] (unsigned int i)
{
    if(i >= 0 && i < this -> cantidadElenco())
    {
        return this -> elenco[i];
    }
    else
        return nullptr;
}

unsigned int Pelicula::cantidadElenco()
{
    return this->contarElencoRec(this->elenco);
}

unsigned int Pelicula::contarElencoRec(Actor ** arr)
{
    if(arr[0] == nullptr)
    {
        return 0;
    }
    else
        return 1 + contarElencoRec(arr + 1);
}

/*
||=== Build: Debug in Parcial2201 (compiler: GNU GCC Compiler) ===|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp||In member function 'bool Pelicula::actua(Actor&)':|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|29|error: request for member 'getNombre' in '((Pelicula*)this)->Pelicula::elenco[i]', which is of pointer type 'Actor*' (maybe you meant to use '->' ?)|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp||In member function 'bool Pelicula::agregarActor(Actor&)':|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|44|error: request for member 'getNombre' in '((Pelicula*)this)->Pelicula::elenco[i]', which is of pointer type 'Actor*' (maybe you meant to use '->' ?)|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp||In member function 'bool Pelicula::eliminarActor(Actor&)':|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|60|error: request for member 'getNombre' in '((Pelicula*)this)->Pelicula::elenco[i]', which is of pointer type 'Actor*' (maybe you meant to use '->' ?)|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|69|warning: no return statement in function returning non-void [-Wreturn-type]|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp||In member function 'bool Pelicula::actua(Actor&)':|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|36|warning: control reaches end of non-void function [-Wreturn-type]|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp||In member function 'bool Pelicula::agregarActor(Actor&)':|
C:\Users\Presentacion\Desktop\Parcial2201\src\Pelicula.cpp|52|warning: control reaches end of non-void function [-Wreturn-type]|
||=== Build failed: 3 error(s), 3 warning(s) (0 minute(s), 0 second(s)) ===|
*/
