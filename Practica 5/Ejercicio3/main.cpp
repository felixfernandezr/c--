#include <iostream>
#include <tau/tau.h>
#include "Universidad.h"

TAU_MAIN()

TEST(Testsis, testAlumno)
{
    Alumno a= Alumno("Roberto");

    CHECK(a.getNombre() == "Roberto");
    CHECK(a.getCantidadMaterias() == 0);

    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    CHECK(a.getCantidadMaterias() == 3);
    CHECK(a.calcularCuota(1000.5) == 3001.5);

    a.desinscribirMateria();
    a.desinscribirMateria();
    CHECK(a.getCantidadMaterias() == 1);
    CHECK(a.calcularCuota(1000.5) == 1000.5);
}

TEST(Testsis, testUniversidad)
{
    Alumno a= Alumno("Roberto");
    Alumno b= Alumno("Norberto");
    Alumno c= Alumno("Ruberto");
    Alumno d= Alumno("Eriberto");

    Universidad aa= Universidad(4500);
    CHECK(aa.getCuotaPorMateria() == 4500);
    aa.setCuotaPorMateria(5000);
    CHECK(aa.getCuotaPorMateria() == 5000);

    CHECK(aa.cantidadAlumnos() == 0);

    CHECK(aa.estaInscripto(a) == false);
    aa.inscribir(a);
    CHECK(aa.estaInscripto(a) == true);

    CHECK(aa.cantidadAlumnos() == 1);

    try
    {
        aa.inscribir(a);
    }
    catch(const char* p)
    {
        std::cout<<"Error: El alumno ya esta inscripto."<<std::endl;
    }

    aa.desinscribir(a);
    CHECK(aa.cantidadAlumnos() == 0);

    try
    {
        aa.desinscribir(a);
    }
    catch(const char* p)
    {
        std::cout<<"Error: El alumno no existe."<<std::endl;
    }

    aa.inscribir(a);
    aa.inscribir(b);
    aa.inscribir(c);
    CHECK(aa.cantidadAlumnos() == 3);
    CHECK(aa.estaInscripto(a) == true);
    CHECK(aa.estaInscripto(b) == true);
    CHECK(aa.estaInscripto(c) == true);
    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    b.inscribirMateria();
    b.inscribirMateria();
    b.inscribirMateria();
    c.inscribirMateria();
    c.inscribirMateria();
    c.inscribirMateria();
    CHECK(a.getCantidadMaterias() == 3);
    CHECK(b.getCantidadMaterias() == 3);
    CHECK(c.getCantidadMaterias() == 3);

    CHECK(aa.calcularIngresosCuota() == 45000);
}

TEST(Testsis, testCarreras)
{
    Universidad aa= Universidad(5000);

    AlumnoPregrado a= AlumnoPregrado("Roberto");
    aa.inscribir(a);

    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    CHECK(a.calcularCuota(5000) == 25000);
    a.inscribirMateria();
    a.inscribirMateria();
    a.inscribirMateria();
    CHECK(a.calcularCuota(5000) == 25000);

    AlumnoGrado b= AlumnoGrado("Norberto");
    aa.inscribir(b);

    b.inscribirMateria();
    b.inscribirMateria();
    b.inscribirMateria();
    CHECK(b.calcularCuota(5000) == 15000);
    b.inscribirMateria();
    b.inscribirMateria();
    CHECK(b.calcularCuota(5000) == 22500);
    b.inscribirMateria();
    b.inscribirMateria();
    b.inscribirMateria();
    CHECK(b.calcularCuota(5000) == 34000);

    AlumnoPosgrado c= AlumnoPosgrado("Ruberto");
    aa.inscribir(c);
    c.inscribirMateria();
    c.inscribirMateria();
    c.inscribirMateria();
    CHECK(c.calcularCuota(5000) == 15000);
    c.inscribirMateria();
    c.inscribirMateria();
    CHECK(c.calcularCuota(5000) == 17500);
    c.inscribirMateria();
    c.inscribirMateria();
    c.inscribirMateria();
    CHECK(c.calcularCuota(5000) == 28000);

    CHECK(aa.calcularIngresosCuota() == 87000);

    //aa.~Universidad();

}



