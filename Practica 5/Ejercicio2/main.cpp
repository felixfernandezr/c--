#include <iostream>
#include <tau/tau.h>
#include <vector>
#include "Cuenta.h"
#include "CajaAhorro.h"
#include "CuentaCorriente.h"

TAU_MAIN()

TEST(Testsis, testCliente)
{
    Cliente* a;
    a= new Cliente("Ramon", 12345);
    CHECK(a->getCuil() == 12345);
    CHECK((*a).getNombre() == "Ramon");
}

TEST(Testsis, testCuenta)
{
    Cliente b= Cliente("Roberto", 12344);
    Cliente c= Cliente("Norberto", 12343);
    Cliente d= Cliente("Eriberto", 12342);
    Cliente e= Cliente("Ruberto", 12341);

    Cuenta aa= Cuenta(b, 0001);
    aa.agregarTitular(c);
    aa.agregarTitular(d);
    try
    {
        aa.agregarTitular(c);
    }
    catch(const char* p)
    {
        std::cout << "Error: El cliente ya aparece como titular de la cuenta." << std::endl;
    }
    //CHECK(aa.obtenerSaldo() == 10);
    CHECK(aa.getCsvClientesCuiles() == "Eriberto,12342\nNorberto,12343\nRoberto,12344");
    aa.eliminarTitular(d);
    aa.eliminarTitular(b);
    CHECK(aa.getCsvClientesCuiles() == "Norberto,12343");
    try
    {
        aa.eliminarTitular(c);
    }
    catch(const char* p)
    {
        std::cout << "Error: Una cuenta debe tener como minimo un titular." << std::endl;
    }
}

TEST(Testsis, testCajaAhorro)
{
    Cliente b= Cliente("Roberto", 12344);
    Cliente c= Cliente("Norberto", 12343);
    Cliente d= Cliente("Eriberto", 12342);
    Cliente e= Cliente("Ruberto", 12341);

    CajaAhorro aa= CajaAhorro(b, 0001);

    aa.agregarTitular(c);
    aa.agregarTitular(d);
    CHECK(aa.getCsvClientesCuiles() == "Eriberto,12342\nNorberto,12343\nRoberto,12344");

    aa.eliminarTitular(d);
    aa.eliminarTitular(b);
    CHECK(aa.getCsvClientesCuiles() == "Norberto,12343");

    aa.depositar(30);
    aa.depositar(24.5);
    aa.depositar(25.5);
    aa.depositar(20);
    CHECK(aa.obtenerSaldo() == 100);
    aa.extraer(50);
    CHECK(aa.obtenerSaldo() == 50);
    try
    {
        aa.extraer(60);
    }
    catch(const char* p)
    {
        std::cout << "Error: El saldo luego de una extraccion no puede ser negativo." << std::endl;
    }
    CHECK(aa.obtenerSaldo() == 50);
}

TEST(Testsin, testCuentaCorriente)
{
    Cliente b= Cliente("Roberto", 12344);
    Cliente c= Cliente("Norberto", 12343);
    Cliente d= Cliente("Eriberto", 12342);
    Cliente e= Cliente("Ruberto", 12341);

    CuentaCorriente aa= CuentaCorriente(b, 0001);

    aa.agregarTitular(c);
    aa.agregarTitular(d);
    CHECK(aa.getCsvClientesCuiles() == "Eriberto,12342\nNorberto,12343\nRoberto,12344");

    aa.eliminarTitular(d);
    aa.eliminarTitular(b);
    CHECK(aa.getCsvClientesCuiles() == "Norberto,12343");

    aa.depositar(100);
    CHECK(aa.obtenerSaldo() == 94);

    aa.extraer(100);
    CHECK(aa.obtenerSaldo() == -12);

    try
    {
        aa.extraer(100000);
    }
    catch(const char* p)
    {
        std::cout << "Error: El monto a extraer no puede sobrepasar el monto de sobregiro." << std::endl;
    }
    CHECK(aa.obtenerSaldo() == -12);
}


