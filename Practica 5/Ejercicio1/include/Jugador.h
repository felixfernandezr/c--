#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

class Jugador
{
    protected:
        std::string nombre;

    public:
        Jugador(std::string);
        ~Jugador();
        std::string getNombre();
};

#endif // JUGADOR_H
