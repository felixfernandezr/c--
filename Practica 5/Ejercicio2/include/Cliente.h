#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente
{
    private:
        std::string nombre;
        unsigned int cuil;

    public:
        Cliente(std::string, unsigned int);
        ~Cliente();
        unsigned int getCuil();
        std::string getNombre();
};

#endif // CLIENTE_H
