#include <iostream>

using namespace std;

double potencia(double, int);

int main()
{
    cout << potencia(3, -4) << endl;
    cout << potencia(3, 4) << endl;

    return 0;
}

double potencia(double base, int exp)
{
   if (exp == 0 && base != 0)
        return 1;

    if (exp < 0)
        return 1 / base * potencia(base, exp + 1);

    return base * potencia(base, exp - 1);
}



