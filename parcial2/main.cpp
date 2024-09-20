/**
Desarrollar los métodos de los archivos CPP con el código fuente que corresponda.
En algunos métodos, se dan las instrucciones mediante comentarios.
Dentro de la carpeta del proyecto, se encuentra el diagrama UML.
La estructura de clases y las declaraciones ya están incluidas.
Hacer el desarrollo siguiendo la metodología TDD.

Quienes recuperen recursividad, realizar el ejercicio del archivo "recursividad.h" y con un test dedicado a probarla.

Al finalizar, eliminar de la carpeta del proyecto, las carpetas BIN y OBJ.
Luego, comprimir todo el proyecto en un archivo .zip con tu apellido como nombre de archivo (Ej. Simpson.zip).
Adjuntarlo en el link correspondiente del Classroom.

Tiempo: 2hs.



*/
#include <tau/tau.h>
#include <iostream>

TAU_MAIN()

#include "Logistica.h"
#include "Camion.h"
#include "Camioneta.h"
#include "recursividad.h"

TEST(Parcial2, Bar)
{
    CHECK(1);
}

TEST(Parcial2, testCamion)
{
    Camion a= Camion("jknbh123", 150);
    CHECK(a.getCostoKilometro() == 150);
    CHECK(a.getPatente() == "jknbh123");
    CHECK(a.getKilometraje() == 0);

    a.setKilometraje(100);
    CHECK(a.getKilometraje() == 100);
    CHECK(a.calcularCosto() == 15000);

    a.setCostoKilometro(200);
    CHECK(a.getCostoKilometro() == 200);
    CHECK(a.calcularCosto() == 20000);

    try
    {
        a.setCostoKilometro(-10);
    }
    catch(const char* p)
    {
        std::cout<<"##ERROR##: EL COSTO POR KILOMETRO NO PUEDE SER NEGATIVO"<<std::endl;
    }


}

TEST(Parcial2, testCamioneta)
{
    Camioneta a= Camioneta("jknbh321", 10000);
    CHECK(a.getCostoService10K() == 10000);
    CHECK(a.getPatente() == "jknbh321");
    CHECK(a.getKilometraje() == 0);

    a.setKilometraje(100);
    CHECK(a.getKilometraje() == 100);
    CHECK(a.calcularCosto() == 0);

    a.setKilometraje(10000);
    CHECK(a.calcularCosto() == 10000);

    a.setKilometraje(25300);
    CHECK(a.calcularCosto() == 20000);

    a.setKilometraje(32781.532);
    CHECK(a.calcularCosto() == 30000);

    a.setCostoService10K(20000);
    CHECK(a.getCostoService10K() == 20000);
    CHECK(a.calcularCosto() == 60000);

    try
    {
        a.setCostoService10K(-10);
    }
    catch(const char* p)
    {
        std::cout<<"##ERROR##: EL COSTO DEL SERVICE NO PUEDE SER NEGATIVO"<<std::endl;
    }
}

TEST(Parcial2, testLogistica)
{
    Camion a= Camion("asd123", 100);
    Camion b= Camion("qwe456", 200);
    Camion c= Camion("zxc678", 300);
    Camioneta d= Camioneta("yui321", 10000);
    Camioneta e= Camioneta("vbn654", 20000);
    Camioneta f= Camioneta("jkl987", 30000);

    Logistica aa= Logistica();

    aa.agregarVehiculo(a);
    aa.agregarVehiculo(b);
    aa.agregarVehiculo(c);
    aa.agregarVehiculo(d);
    aa.agregarVehiculo(e);
    CHECK(aa.estaVehiculo(f) == false);
    CHECK(aa.estaVehiculo(a) == true);
    CHECK(aa.estaVehiculo(b) == true);
    CHECK(aa.estaVehiculo(c) == true);
    CHECK(aa.estaVehiculo(d) == true);
    CHECK(aa.estaVehiculo(e) == true);

    try
    {
        aa.agregarVehiculo(a);
    }
    catch(const char* p)
    {
        std::cout<<"##ERROR##: EL VEHICULO YA ESTA REGISTRADO EN LA FLOTA."<<std::endl;
    }

    try
    {
        aa.eliminarVehiculo(f);
    }
    catch(const char* p)
    {
        std::cout<<"##ERROR##: EL VEHICULO NO EXISTE NO SE PUEDE ELIMINAR"<<std::endl;
    }

    aa.agregarVehiculo(f);
    CHECK(aa.estaVehiculo(f) == true);

    a.setKilometraje(100);
    b.setKilometraje(100);
    c.setKilometraje(100);
    CHECK(a.calcularCosto() == 10000);
    CHECK(b.calcularCosto() == 20000);
    CHECK(c.calcularCosto() == 30000);

    d.setKilometraje(42000);
    e.setKilometraje(12000);
    f.setKilometraje(17523.87);
    CHECK(d.calcularCosto() == 40000);
    CHECK(e.calcularCosto() == 20000);
    CHECK(f.calcularCosto() == 30000);

    CHECK(aa.calcularCostoTotal() == 150000);

    f.setKilometraje(222);
    CHECK(f.calcularCosto() == 0);
    CHECK(aa.calcularCostoTotal() == 120000);
}
