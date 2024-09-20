#include <iostream>
#include "ColeccionEnteros.h"
using namespace std;

int main()
{

    ColeccionEnteros arrent = ColeccionEnteros();

    cout << arrent.agregarInicio(1) << endl;
    arrent.agregarInicio(3);
    arrent.agregarInicio(4);
    arrent.agregarFinal(4);
    arrent.agregarFinal(4);
    arrent.agregarFinal(6);
    arrent.agregarFinal(8);
    arrent.agregarFinal(10);

    for(unsigned int i = 0 ; i < 8 ; i++)
    {
        cout << "arrent[" << i << "] = " <<arrent[i] << endl;
    }

    arrent.eliminarPrimero(6);
    cout << endl;

    for(unsigned int i = 0 ; i < 8 ; i++)
    {
        cout << "arrent[" << i << "] = " <<arrent[i] << endl;
    }

    arrent.eliminarUltimo(4);
    cout << endl;

    for(unsigned int i = 0 ; i < 8 ; i++)
    {
        cout << "arrent[" << i << "] = " <<arrent[i] << endl;
    }


    return 0;
}
