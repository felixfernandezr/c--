#include <iostream>
using namespace std;

int cocienteResta(int, int);

int restoResta(int, int);

int main()
{
    cout << ".  12 / 3 (4)   =  " << cocienteResta(12, 3) << endl;
    cout << ".  12 / -3 (-4) = " << cocienteResta(-12, 3) << endl;
    cout << ". -12 / 3 (-4)  = " << cocienteResta(12, -3) << endl;
    cout << ". -12 / -3 (4)  =  " << cocienteResta(-12, -3) << endl << endl;

    cout << ".  14 / 3 (2)   = " << restoResta(14, 3) << endl;
    cout << ".  -15 / 3 (0)  = " << restoResta(15, -3) << endl;
    cout << ".  16 / -3 (1)  = " << restoResta(-16, 3) << endl;
    cout << ".  -17 / -3 (2) = " << restoResta(-17, -3) << endl << endl;

    return 0;
}


int restoResta(int a, int b)
{

    if(a < 0)
    {
        a = -a;

        return restoResta(a, b);
    }
    else if(b < 0)
    {
        b = -b;

        return restoResta(a, b);
    }

    if (a < b)
    {
        return a;
    }
    else
    {
        return restoResta(a - b, b);
    }
}


int cocienteResta(int a, int b)
{
    if(a < 0)
    {
        a = -a;

        return -(1 + cocienteResta((a-b), b));
    }
    else if(b < 0)
    {
        b = -b;

        return -(1 + cocienteResta((a-b), b));
    }

    if(b == 0)
    {
        return 0;
    }

    if(a > 0)
    {
        return 1 + cocienteResta((a - b), b);
    }

}
