#include "Carrera.h"
#include <set>
#include <vector>

Carrera::Carrera(std::string nombreCarr)
{
    this -> nombre = nombreCarr;
    std::set<Alumno*> alumnado;
    std::vector<Materia> materias;
}
Carrera::~Carrera()
{

}
Materia& Carrera::crearMateria(std::string nombreMat, unsigned int cupo)
{
    this->materias.push_back(Materia(nombreMat, cupo));
    return this->materias[this->materias.size() - 1];
}
Materia& Carrera::obtenerMateria(std::string nombreMat)
{
    for(auto it= this->materias.begin() ; it!= this->materias.end() ; ++it)
    {
        if((it)->getNombreMateria() == nombreMat)
        {
            return (*it);
        }
    }
    throw "##ERROR## No existe la materia ##ERROR##";
}
bool Carrera::eliminarMateria(Materia& unaMateria)
{
    try
    {
        obtenerMateria(unaMateria.getNombreMateria());
    }
    catch(const char *p)
    {
        return false;
    }

    unsigned int i=0;
    for(auto it= this->materias.begin() ; it != this->materias.end() ; ++it)
    {
        if((&(*it)) == &unaMateria)
        {
            this->materias.erase(this->materias.begin()+i);
            return true;
        }
        i++;
    }
}
Alumno& Carrera::anotarAlumno(std::string nombreAlu)
{
    Alumno* a= new Alumno(nombreAlu);

    this->alumnado.insert(a);

    return *a;
}
bool Carrera::desanotarAlumno(Alumno& unAlumno)
{
    auto pos= this->alumnado.find(&unAlumno);

    if(pos== this->alumnado.end())
    {
        return false;
    }
    else
    {
        this->alumnado.erase(pos);
        return true;
    }
}
bool Carrera::inscribirCursada(Alumno& unAlumno, Materia& unaMateria)
{
    unaMateria.inscribir(unAlumno);
}
bool Carrera::desinscribirCursada(Alumno& unAlumno, Materia& unaMateria)
{
    unaMateria.desinscribir(unAlumno);
}
unsigned int Carrera::cantidadMaterias()
{
    return this -> materias.size();
}
unsigned int Carrera::cantidadAlumnado()
{
    return this -> alumnado.size();
}
