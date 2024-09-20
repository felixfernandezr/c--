#ifndef ACTOR_H
#define ACTOR_H

#include "tiposGalardones.h"
#include <string>

class Actor
{
    private:
        std::string nombre;
        tiposGalardones * galardones;
        unsigned int cantidadGalardones;

    public:
        Actor(std::string nombre);
        ~Actor();
        std::string getNombre();
        unsigned int getCantidadGalardones();
        void agregarGalardon (tiposGalardones unGalardon);
        void eliminarGalardon (tiposGalardones unGalardon);
        unsigned int contarGalardon (tiposGalardones unGalardon);
        unsigned int contarGalardonRec(tiposGalardones unGalardon, unsigned int cantidadGalardones);
    private:
        void redimensionarGalardones(bool agrandar);

};

#endif // ACTOR_H
