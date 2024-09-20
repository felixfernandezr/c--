#include <iostream>

#include "ColeccionEnteros.h"


int main()
{
    ColeccionEnteros c;
    c.agregarInicio(30);
    c.agregarInicio(20);
    c.agregarInicio(10);
    c.agregarFinal(40);
    c.agregarFinal(50);
    c.agregarFinal(40);
    c.agregarFinal(60);
    c.agregarFinal(60);
    c.agregarFinal(60);
    c.agregarFinal(60);
    c.agregarFinal(60);

    std::cout  << "Reservado = " << c.getReservado() << std::endl;
    std::cout  << "Utilizado = " << c.getUtilizado() << std::endl;

    for (unsigned int i=0; i<c.cantidadValores(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    std::cout << (c.eliminarUltimo(40) ? "Exito eliminando 40" : "Error eliminando 40") << std::endl;

    std::cout << "Reservado = " << c.getReservado() << std::endl;
    std::cout << "Utilizado = " << c.getUtilizado() << std::endl;

    for (unsigned int i=0; i<c.cantidadValores(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;


    std::cout << (c.eliminarPrimero(80) ? "Exito eliminando 80" : "Error eliminando 80") << std::endl;
    std::cout << (c.eliminarPrimero(10) ? "Exito eliminando 10" : "Error eliminando 10") << std::endl;
    std::cout << (c.eliminarPrimero(20) ? "Exito eliminando 20" : "Error eliminando 20") << std::endl;
    std::cout << (c.eliminarPrimero(30) ? "Exito eliminando 30" : "Error eliminando 30") << std::endl;
    std::cout << (c.eliminarPrimero(40) ? "Exito eliminando 40" : "Error eliminando 40") << std::endl;
    std::cout << "Eliminó el 60 x = " << c.eliminarTodos(60) << std::endl;

    std::cout << "Reservado = " << c.getReservado() << std::endl;
    std::cout << "Utilizado = " << c.getUtilizado() << std::endl;

    for (unsigned int i=0; i<c.cantidadValores(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;


    c.agregarFinal(51);
    c.agregarFinal(52);
    c.agregarFinal(53);
    c.agregarFinal(54);
    c.agregarFinal(55);

    std::cout << "Reservado = " << c.getReservado() << std::endl;
    std::cout << "Utilizado = " << c.getUtilizado() << std::endl;

    for (unsigned int i=0; i<c.cantidadValores(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
