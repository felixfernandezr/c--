#include <iostream>
#include "Viaje.h"
using namespace std;

int main()
{
    Viaje v = Viaje("Buenos Aires", "Mar del Plata", 23);

    cout << v.getCiudadOrigen() << endl;
    cout << v.getCiudadDestino() << endl;
    cout << v.getCantidadLugaresTotal() << endl;

    cout << "Vender pasaje: " << v.venderPasaje("Raul Perez", DNI, 18595626, "Palermo") << endl;
    cout << "Vender pasaje: " << v.venderPasaje("Jesica Perez", DNI, 40123626, "Palermo") << endl;
    cout << "Vender pasaje: " << v.venderPasaje("Mirta Perez", DNI, 20594626, "Palermo") << endl;
    cout << "Vender pasaje: " << v.venderPasaje("Raul Jr Perez", DNI, 44588926, "Palermo") << endl;
    cout << "Vender pasaje: " << v.venderPasaje("Carlos Perez", DNI, 38595626, "Palermo") << endl << endl;

    cout << v.esLugarOcupado(2) << " (ID = 2)" << endl;
    cout << v.esLugarOcupado(4) << " (ID = 5)" << endl;
    cout << endl;

    Pasajero* a = v[4];

    cout << a -> getApeNom() << endl;

    cout << v.devolverPasaje(2) << endl;
    cout << v.devolverPasajes(a) << endl;
    cout << v.esLugarOcupado(2) << " (ID = 2)" << endl;
    cout << v.esLugarOcupado(4) << " (ID = 4)" << endl << endl;

    cout << v.obtenerPasajesVendidos() << endl;
    cout << endl;
    cout << v.esLugarOcupado(2) << " (ID = 2)" << endl;
    cout << v.esLugarOcupado(4) << " (ID = 4)" << endl;
    cout << endl;
    cout << "Vender pasaje: " << v.venderPasaje("Jesica Perez", DNI, 40123626, "Palermo") << endl;
    cout << endl;
    cout << v.esLugarOcupado(2) << " (ID = 2)" << endl;
    cout << v.esLugarOcupado(4) << " (ID = 4)" << endl;
    cout << v.obtenerPasajesVendidos() << endl;
    cout << endl;





    return 0;
}
