#include "Materia.h"
#include <set>
Materia::Materia(std::string nom, unsigned int cupo)
{
    this->nombre= nom;
    this->cupo= cupo;
    std::set<Alumno*> inscriptos;
}
Materia::~Materia()
{
}
std::string Materia::getNombreMateria()
{
    return this->nombre;
}
unsigned int Materia::getCupo()
{
    return this->cupo;
}
bool Materia::inscribir(Alumno& unAlumno)
{
    if(this->cupoDisponible() > 0)
    {
        this->inscriptos.insert(&unAlumno);
        return true;
    }

    return false;
}
bool Materia::desinscribir(Alumno& unAlumno)
{
    auto pos=this->inscriptos.find(&unAlumno);

    if(pos == this->inscriptos.end())
    {
        return false;
    }
    else
    {
        this->inscriptos.erase(pos);
        return true;
    }
}
unsigned int Materia::cantidadInscriptos()
{
    return this->inscriptos.size();
}
unsigned int Materia::cupoDisponible()
{
    return (this->cupo - this->cantidadInscriptos());
}
std::string Materia::csvInscriptos()
{
    std::string csvIns= "";
    for(auto it= this->inscriptos.begin() ; it!= this->inscriptos.end() ; ++it)
    {
        csvIns = csvIns + (*it)->getNombre() + ",";
    }

    if (!csvIns.empty()) {
        csvIns.pop_back();
    }

    return csvIns;
}
