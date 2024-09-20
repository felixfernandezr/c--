#ifndef CUENTA_H
#define CUENTA_H
#include <set>
#include <vector>
#include <string>
#include "Cliente.h"

class Cuenta
{
    private:
        std::set<Cliente*> titulares;
        unsigned int numero;

    protected:
        std::vector<double> movimientos;

    public:
        Cuenta(Cliente&, unsigned int);
        ~Cuenta();
        std::string getCsvClientesCuiles();
        unsigned int getNumero();
        double obtenerSaldo();
        void agregarTitular(Cliente&);
        void eliminarTitular(Cliente&);
};

#endif // CUENTA_H
