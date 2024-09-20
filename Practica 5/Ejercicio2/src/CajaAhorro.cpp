#include "CajaAhorro.h"
#include <iostream>

CajaAhorro::CajaAhorro(Cliente& titular, unsigned int numero) : Cuenta(titular, numero) {}

CajaAhorro::~CajaAhorro() {}

void CajaAhorro::depositar(double monto)
{
    this->movimientos.push_back(monto);
}

void CajaAhorro::extraer(double monto)
{
    if((this->obtenerSaldo() - monto) > 0)
    {
        this->depositar(-monto);
    }
    else
        throw "asdasd";
}
