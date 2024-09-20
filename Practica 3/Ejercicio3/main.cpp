#include <iostream>

using namespace std;

int productoSuma(int, int);


int main()
{
    cout << ".  8 x 9(72):    " << productoSuma(8,9) << endl;
    cout << ". -8 x 9(-72):  " << productoSuma(-8,9) << endl;
    cout << ".  8 x -9(-72): " << productoSuma(8,-9) << endl;
    cout << ". -8 x -9(72):   " << productoSuma(-8,-9) << endl;
    return 0;
}


int productoSuma(int a, int b)
{
    if(b > 0)
    {
        return a + productoSuma(a, (b - 1));
    }
    else if(b < 0)
    {
        a = -a;
        b = -b;
        return a + productoSuma(a, (b - 1));
    }
    else
        return 0;
}
