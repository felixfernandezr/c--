#ifndef ALUMNO _H
#define ALUMNO _H
#include<string>
class Alumno
{
    public:
        Alumno (std::string nombre);
         ~Alumno ();
        std::string getNombre();
    private:
        std::string nombre;
};

#endif // ALUMNO _H
