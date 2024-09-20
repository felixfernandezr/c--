#include "Carrera.h"
#include<vector>
#include<set>
Carrera::Carrera(std::string nombre)
{
    this->nombre=nombre;
    std::set<Alumno*> alumnado;
    std::vector<Materia> materias;
}

Carrera::~Carrera()
{
    for(auto it=this->materias.begin();it!=this->materias.end();it++)
    {
        (*it).~Materia();
    }
    this->materias.clear();
}
Materia& Carrera::crearMateria(std::string nombreMat, unsigned int cupoMat)
{
    this->materias.push_back(Materia(nombreMat,cupoMat));
    return this->materias[this->materias.size()-1];
}
Materia& Carrera::obtenerMateria(std::string nombreMat)
{
    for(auto it=this->materias.begin();it!=this->materias.end();it++)
    {
        if((*it).getNombreMateria()==nombreMat)
        {
            return (*it);
        }
    }
    throw "Materia inexistente";
}
bool Carrera::eliminarMateria(Materia& unaMateria)
{
    std::string nombreMat=unaMateria.getNombreMateria();
    try{
        this->obtenerMateria(nombreMat);
    }catch(const char *p){
        return false;
    }
    unsigned int i=0;
    for(auto it=this->materias.begin();it!=this->materias.end();it++)
        {
            if((&(*it))==&unaMateria)
               {
                   this->materias.erase(this->materias.begin()+i);
                   return true;
               }
            i++;
        }
}
Alumno& Carrera::anotarAlumno(std::string unNombre)
{
    Alumno* a=new Alumno(unNombre);
    this->alumnado.insert(a);
    return *a;
}
bool Carrera::desanotarAlumno(Alumno& unAlumno)
{
    auto pos=this->alumnado.find(&unAlumno);
    if(pos!=this->alumnado.end())
    {
        this->alumnado.erase(pos);
        return true;
    }
    return false;
}
bool Carrera::inscribirCursada(Alumno& unAlumno, Materia& unaMateria)
{
    if(unaMateria.inscribir(unAlumno))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Carrera::desinscribirCursada(Alumno& unAlumno, Materia& unaMateria)
{
    if(unaMateria.desinscribir(unAlumno))
    {
        return true;
    }
    else
    {
        return false;
    }

}
unsigned int Carrera::cantidadMaterias()
{
    return this->materias.size();
}
unsigned int Carrera::cantidadAlumnado()
{
    return this->alumnado.size();
}
