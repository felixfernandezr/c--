#include "Cliente.h"
#include <string>

Cliente::Cliente(std::string nombre, unsigned int cuil) : nombre(nombre), cuil(cuil) {}

Cliente::~Cliente() {}

unsigned int Cliente::getCuil() { return this->cuil; }

std::string Cliente::getNombre() { return this->nombre; }
