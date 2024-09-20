#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>

class Alumno
{
    private:
        unsigned int cantidadMaterias= 0;
        std::string nombre;

    public:
        Alumno(std::string);
        ~Alumno();
        unsigned int getCantidadMaterias() { return this->cantidadMaterias; }
        std::string getNombre() { return this->nombre; }
        void inscribirMateria();
        void desinscribirMateria();
        virtual double calcularCuota(double);
};

#endif // ALUMNO_H
