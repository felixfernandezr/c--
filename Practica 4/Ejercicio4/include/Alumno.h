#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>

class Alumno
{
    private:
        std::string nombre;

    public:
        Alumno(std::string);
        ~Alumno();
        std::string getNombre();
};

#endif // ALUMNO_H
