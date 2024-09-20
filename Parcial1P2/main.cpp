#include <tau/tau.h>

#include "Actor.h"
#include "Pelicula.h"

TAU_MAIN()


TEST(TestClasePelicula, asdasd)
{
    Pelicula p = Pelicula("Mars Attack", 1997);
    CHECK(p.getAnioEstreno() == 1997);
    CHECK(p.getTitulo() == "Mars Attack");
    CHECK(p[0] == nullptr);
    CHECK(p[23] == nullptr);

    Actor a = Actor("Brad Pitt");
    Actor b = Actor("Angelina Jolie");
    Actor c = Actor("Ben Stiller");
    Actor d = Actor("Dwayne Johnson");

    Actor e = Actor("Brad Pitt");
    Actor f = Actor("Angelina Jolie");
    Actor g = Actor("Ben Stiller");
    Actor h = Actor("Dwayne Johnson");

    CHECK(p.agregarActor(a) == true);
    CHECK(p.actua(a) == true);
    CHECK(p[0] -> getNombre() == "Brad Pitt");
    CHECK(p[1] == nullptr);
    CHECK(p.agregarActor(a) == false);
    CHECK(p.agregarActor(e) == true);
    CHECK(p.cantidadElenco() == 1);

    CHECK(p.agregarActor(b) == true);
    CHECK(p.actua(b) == true);
    CHECK(p[1] -> getNombre() == "Angelina Jolie");
    CHECK(p[2] == nullptr);
    CHECK(p.agregarActor(b) == false);
    CHECK(p.agregarActor(f) == false);
    CHECK(p.cantidadElenco() == 2);

    CHECK(p.agregarActor(c) == true);
    CHECK(p.actua(c) == true);
    CHECK(p[2] -> getNombre() == "Ben Stiller");
    CHECK(p[3] == nullptr);
    CHECK(p.agregarActor(c) == false);
    CHECK(p.agregarActor(g) == false);
    CHECK(p.cantidadElenco() == 3);

    CHECK(p.agregarActor(d) == true);
    CHECK(p.actua(d) == true);
    CHECK(p[3] -> getNombre() == "Dwayne Johnson");
    CHECK(p[4] == nullptr);
    CHECK(p.agregarActor(d) == false);
    CHECK(p.agregarActor(h) == false);
    CHECK(p.cantidadElenco() == 4);

    CHECK(p.eliminarActor(a) == true);
    CHECK(p.eliminarActor(a) == false);
    CHECK(p.eliminarActor(e) == false);
    CHECK(p.cantidadElenco() == 3);
    CHECK(p.actua(a) == false);

    CHECK(p[0] -> getNombre() == "Angelina Jolie");
    CHECK(p[1] -> getNombre() == "Ben Stiller");
    CHECK(p[2] -> getNombre() == "Dwayne Johnson");
    CHECK(p[3] == nullptr);
    CHECK(p[4] == nullptr);

    CHECK(p.eliminarActor(b) == true);
    CHECK(p.actua(b) == false);
    CHECK(p.cantidadElenco() == 2);
    CHECK(p[2] == nullptr);
    CHECK(p.eliminarActor(b) == false);

    CHECK(p.eliminarActor(c) == true);
    CHECK(p.actua(c) == false);
    CHECK(p.cantidadElenco() == 1);
    CHECK(p[1] == nullptr);
    CHECK(p.eliminarActor(c) == false);

    CHECK(p.eliminarActor(d) == true);
    CHECK(p.actua(d) == false);
    CHECK(p.cantidadElenco() == 0);
    CHECK(p[0] == nullptr);
    CHECK(p.eliminarActor(d) == false);
}
