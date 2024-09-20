#include <iostream>
#include <tau/tau.h>
#include "Equipo.h"
#include "EquipoBasquet.h"
#include "EquipoFutbol.h"

TAU_MAIN()

TEST(TestEquipos, test1)
{
    EquipoFutbol a = EquipoFutbol("Banfield");
    CHECK(a.cantidadIntegrantes() == 0);
}
