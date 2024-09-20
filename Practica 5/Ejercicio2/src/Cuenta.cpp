#include <set>
#include <vector>
#include <string>
//#include <numeric>
#include "Cuenta.h"


Cuenta::Cuenta(Cliente& unTitular, unsigned int numero)
{
    this->titulares.insert(&unTitular);
    this->numero= numero;
}

Cuenta::~Cuenta() {}

unsigned int Cuenta::getNumero() { return this->numero; }

std::string Cuenta::getCsvClientesCuiles()
{
    std::string csv= "";
    for(auto it= this->titulares.begin(); it != this->titulares.end(); ++it)
    {
        csv = csv + (*it)->getNombre() + "," + std::to_string((*it)->getCuil()) + "\n";
    }

    if (!csv.empty()) {
        csv.pop_back();
    }

    return csv;
}

double Cuenta::obtenerSaldo()
{
    //double saldoFinal = std::accumulate(this->movimientos.begin(), this->movimientos.end(), 0);
    auto it= this->movimientos.begin();
    double saldoFinal= 0;
    while(it!= this->movimientos.end())
    {
        saldoFinal+= (*it);
        ++it;
    }

    return saldoFinal;
}

void Cuenta::agregarTitular(Cliente& unCliente)
{
    auto pos= this->titulares.find(&unCliente);

    if(pos == this->titulares.end())
    {
        this->titulares.insert(&unCliente);
    }
    else
        throw "El cliente cuil n° ya es titular de la cuenta";
}

void Cuenta::eliminarTitular(Cliente& unCliente)
{
    if( this->titulares.size() == 1)
    {
        throw "asdads";
    }
    else
        this->titulares.erase(&unCliente);
}
