#ifndef CAJAAHORRO_H
#define CAJAAHORRO_H
#include "Cuenta.h"

class CajaAhorro : public Cuenta
{
    public:
        CajaAhorro(Cliente&, unsigned int);
        ~CajaAhorro();
        void depositar(double);
        void extraer(double);
};

#endif // CAJAAHORRO_H
