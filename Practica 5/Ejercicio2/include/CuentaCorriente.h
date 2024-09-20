#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuenta.h"

class CuentaCorriente : public Cuenta
{
    private:
        double maximoSobregiro = 10000;

    public:
        CuentaCorriente(Cliente&, unsigned int);
        ~CuentaCorriente();
        double getMaximoSobregiro();
        void setMaximoSobregiro(double);
        void depositar(double);
        void extraer(double);
};

#endif // CUENTACORRIENTE_H
