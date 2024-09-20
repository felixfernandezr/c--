#include "CuentaCorriente.h"
#include <vector>

CuentaCorriente::CuentaCorriente(Cliente& titular, unsigned int numero) : Cuenta(titular, numero) {}

CuentaCorriente::~CuentaCorriente() {}

double CuentaCorriente::getMaximoSobregiro() { return this->maximoSobregiro; }

void CuentaCorriente::setMaximoSobregiro(double monto) { this->maximoSobregiro= monto; }

void CuentaCorriente::depositar(double monto)
{
    double montoFin= (monto*0.94);

    this->movimientos.push_back(montoFin);
}

void CuentaCorriente::extraer(double monto)
{
    double montoFin = -(monto*1.06);

    if((this->obtenerSaldo() + montoFin) > -(this->getMaximoSobregiro()))
    {
        this->movimientos.push_back(montoFin);
    }
    else
        throw "asdasd";
}
