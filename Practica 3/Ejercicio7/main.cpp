#include <iostream>

using namespace std;

double potencia(double, int);

int main()
{
    //cout << potencia(3, -4) << endl;
    cout << potencia(3, 3) << endl;

    return 0;
}

double potencia(double base, int exp)
{
    if (exp == 0 && base != 0)
    {
        return 1;
    }
    else if (exp == 1)
    {
        return base;
    }
    else
    {
        double p = potencia(base, exp/2);
        p = p * p;
        if (exp % 2 != 0)
        {
            p = p * base;
        }
        return p;
    }
}
