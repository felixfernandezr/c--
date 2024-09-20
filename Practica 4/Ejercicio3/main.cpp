#include <tau/tau.h>
#include <string>

#include "Coleccion.h"

TAU_MAIN()


TEST(TestColeccionEnteros, agregados) {
    Coleccion <int> c;
    CHECK(c.cantidadValores()==0);
    c.agregarInicio(20);
    CHECK(c.cantidadValores()==1);
    CHECK(c.getUtilizado()==1);
    CHECK(c[0]==20);
    c.agregarInicio(10);
    CHECK(c.cantidadValores()==2);
    CHECK(c.getUtilizado()==2);
    CHECK(c[0]==10);
    CHECK(c[1]==20);

    c.agregarInicio(5);
    CHECK(c.cantidadValores()==3);
    CHECK(c.getUtilizado()==3);
    CHECK(c[0]==5);
    CHECK(c[1]==10);
    CHECK(c[2]==20);

    c.agregarFinal(30);
    CHECK(c.cantidadValores()==4);
    CHECK(c.getUtilizado()==4);
    CHECK(c[0]==5);
    CHECK(c[1]==10);
    CHECK(c[2]==20);
    CHECK(c[3]==30);

    c.agregarFinal(40);
    c.agregarFinal(50);
    c.agregarFinal(60);
    c.agregarFinal(70);
    CHECK(c.cantidadValores()==8);
    CHECK(c.getUtilizado()==8);
    CHECK(c[0]==5);
    CHECK(c[1]==10);
    CHECK(c[2]==20);
    CHECK(c[3]==30);
    CHECK(c[4]==40);
    CHECK(c[5]==50);
    CHECK(c[6]==60);
    CHECK(c[7]==70);
}

TEST(TestColeccionEnteros, eliminados) {
    Coleccion <int> c;
    c.agregarFinal(30);
    c.agregarFinal(30);
    c.agregarFinal(30);
    c.agregarFinal(40);
    c.agregarFinal(40);
    c.agregarFinal(50);
    c.agregarFinal(50);
    c.agregarFinal(60);
    c.agregarFinal(70);
    CHECK(c.cantidadValores()==9);
    CHECK(c.eliminarPrimero(10)==false);
    CHECK(c.eliminarPrimero(30)==true);
    CHECK(c.cantidadValores()==8);
    CHECK(c[0]==30);
    CHECK(c[1]==30);
    CHECK(c[2]==40);
    CHECK(c[3]==40);
    CHECK(c[4]==50);
    CHECK(c[5]==50);
    CHECK(c[6]==60);
    CHECK(c[7]==70);
    CHECK(c.eliminarUltimo(70)==true);
    CHECK(c.eliminarUltimo(70)==false);
    CHECK(c[0]==30);
    CHECK(c[1]==30);
    CHECK(c[2]==40);
    CHECK(c[3]==40);
    CHECK(c[4]==50);
    CHECK(c[5]==50);
    CHECK(c[6]==60);
    CHECK(c.eliminarTodos(70)==0);
    CHECK(c.eliminarTodos(50)==2);
    CHECK(c.eliminarTodos(60)==1);
    CHECK(c[0]==30);
    CHECK(c[1]==30);
    CHECK(c[2]==40);
    CHECK(c[3]==40);
    CHECK(c.cantidadValores()==4);
}

TEST(TestColeccionEnteros, reservas) {
    Coleccion <int> c;
    c.agregarFinal(1);
    c.agregarFinal(2);
    c.agregarFinal(3);
    c.agregarFinal(4);
    c.agregarFinal(5);
    c.agregarFinal(6);
    c.agregarFinal(7);
    c.agregarFinal(8);
    c.agregarFinal(9);
    CHECK(c.cantidadValores()==9);
    CHECK(c.getReservado()==10);
    c.agregarFinal(10);
    CHECK(c.cantidadValores()==10);
    CHECK(c.getReservado()==15);
    CHECK(c.eliminarPrimero(9)==true);
    CHECK(c.eliminarPrimero(8)==true);
    CHECK(c.cantidadValores()==8);
    CHECK(c.getReservado()==15);
    CHECK(c.eliminarPrimero(7)==true);
    CHECK(c.cantidadValores()==7);
    CHECK(c.getReservado()==10, "Se esperaba que la reserva fuera 10");
}


/*
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
*/
