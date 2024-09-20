#include <iostream>
#include<tau-dev/tau/tau.h>
#include "Carrera.h"

TAU_MAIN()
TEST(TestAlumno, Alumno)
{
    Alumno a("L");
    CHECK(a.getNombre()=="L");
}
TEST(TestMateria, Materia)
{
    Materia m("unaMateria",6);
    CHECK(m.cantidadInscriptos()==0);
    CHECK(m.csvInscriptos()=="");
    CHECK(m.cupoDisponible()==6);

    Alumno a("L");
    CHECK(m.inscribir(a));
    CHECK(m.cantidadInscriptos()==1);
    CHECK(m.csvInscriptos()=="L");
    CHECK(m.cupoDisponible()==5);

    Alumno b("G");
    m.inscribir(b);
    CHECK(m.cantidadInscriptos()==2);
    CHECK(m.csvInscriptos()=="G,L");
    CHECK(m.cupoDisponible()==4);

    Alumno c("T");
    m.inscribir(c);
    CHECK(m.cantidadInscriptos()==3);
    CHECK(m.csvInscriptos()=="T,G,L");
    CHECK(m.cupoDisponible()==3);

    Alumno d("B");
    CHECK(m.inscribir(d));
    CHECK(m.cantidadInscriptos()==4);
    CHECK(m.csvInscriptos()=="B,T,G,L");
    CHECK(m.cupoDisponible()==2);

    Alumno e("E");
    m.inscribir(e);
    CHECK(m.cantidadInscriptos()==5);
    CHECK(m.csvInscriptos()=="E,B,T,G,L");
    CHECK(m.cupoDisponible()==1);

    Alumno h("H");
    CHECK(m.inscribir(h));
    CHECK(m.cantidadInscriptos()==6);
    CHECK(m.csvInscriptos()=="H,E,B,T,G,L");
    CHECK(m.cupoDisponible()==0);

    Alumno f("No");
    m.inscribir(f);
    CHECK(m.cantidadInscriptos()==6);
    CHECK(m.csvInscriptos()=="H,E,B,T,G,L");
    CHECK(m.cupoDisponible()==0);

    m.desinscribir(e);
    CHECK(m.cantidadInscriptos()==5);
    CHECK(m.csvInscriptos()=="H,B,T,G,L");
    CHECK(m.cupoDisponible()==1);

    CHECK(m.desinscribir(a));

    CHECK(m.cantidadInscriptos()==4);
    CHECK(m.csvInscriptos()=="H,B,T,G");
    CHECK(m.cupoDisponible()==2);

    m.inscribir(b);
    CHECK(m.cantidadInscriptos()==4);
    CHECK(m.csvInscriptos()=="H,B,T,G");
    CHECK(m.cupoDisponible()==2);

    CHECK(m.desinscribir(f)==false);

    CHECK(m.cantidadInscriptos()==4);
    CHECK(m.csvInscriptos()=="H,B,T,G");
    CHECK(m.cupoDisponible()==2);
}
TEST (TestCarrera, Carrera)
{
    Carrera c("Biologia");
    CHECK(c.cantidadAlumnado()==0);
    CHECK(c.cantidadMaterias()==0);

    Materia& m=c.crearMateria("IBMC",10);
    CHECK(c.cantidadMaterias()==1);
    CHECK(c.obtenerMateria("IBMC").getNombreMateria()=="IBMC");
    try{
        c.obtenerMateria("No");
        CHECK(1==0);
    }catch(const char* p)
    {
        CHECK(1);
    }
    CHECK(c.eliminarMateria(m));
    CHECK(c.cantidadMaterias()==0);
    CHECK(c.eliminarMateria(m)==false);

    Alumno& a=c.anotarAlumno("L");
    CHECK(c.cantidadAlumnado()==1);
    CHECK(c.desanotarAlumno(a));
    CHECK(c.cantidadAlumnado()==0);
    CHECK(c.desanotarAlumno(a)==false);

    Alumno& b=c.anotarAlumno("G");
    Materia& o=c.crearMateria("Otra",2);
    CHECK(c.cantidadAlumnado()==1);
    CHECK(c.cantidadMaterias()==1);

    CHECK(c.inscribirCursada(b,o));
    CHECK(o.cantidadInscriptos()==1);
    CHECK(o.cupoDisponible()==1);
    CHECK(o.csvInscriptos()=="G");

    Alumno& e=c.anotarAlumno("C");
    CHECK(c.inscribirCursada(e,o));
    CHECK(o.cantidadInscriptos()==c.cantidadAlumnado());
    CHECK(o.cantidadInscriptos()==2);
    CHECK(o.cupoDisponible()==0);
    CHECK(o.csvInscriptos()=="C,G"||o.csvInscriptos()=="G,C");

    Alumno& d=c.anotarAlumno("D");
    CHECK(c.inscribirCursada(d,o)==false);
    CHECK(o.cantidadInscriptos()==2);
    CHECK(o.cupoDisponible()==0);
    CHECK(o.csvInscriptos()=="C,G"||o.csvInscriptos()=="G,C");

    c.desinscribirCursada(b,o);
    CHECK(o.cantidadInscriptos()==1);
    CHECK(o.cupoDisponible()==1);
    CHECK(o.csvInscriptos()=="C");

    c.desinscribirCursada(e,o);
    CHECK(o.cantidadInscriptos()==0);
    CHECK(o.cupoDisponible()==2);
    CHECK(o.csvInscriptos()=="");

    (c.desinscribirCursada(b,o)==false);
}

