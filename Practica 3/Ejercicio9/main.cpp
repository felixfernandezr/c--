#include <iostream>

using namespace std;

int valorMaxValor(int *, int);
int* valorMaxPosi(int *, int);

int main()
{
    int a[6] = {1,2,5,29,3,0};

    int * b = new int [6];

    int * e = new int [9];

    int * c = new int;

    *c = 5;

    cout << b[2] << endl;
    cout << e[2] << endl;

    b = a;
    e = a;

    cout << &b[2] << endl;
    cout << &e[2] << endl;

    cout << valorMaxValor(b, 5) << endl;
    cout << valorMaxPosi(b, 5) << endl;

    return 0;
}

int valorMaxValor(int * arr, int tam)
{
    int maxi = 0;

    if(tam == 1)
    {
        maxi = arr[0];
        return maxi;
    }
    else
        return maxi = arr[tam] > valorMaxValor(arr, tam - 1) ? arr[tam] : valorMaxValor(arr, tam - 1);
}

int* valorMaxPosi(int * arr, int tam)
{
    int maxi = 0;

    if(tam == 1)
    {
        maxi = arr[0];
        return &maxi;
    }
    else
    {
        maxi = arr[tam] > valorMaxValor(arr, tam - 1) ? arr[tam] : valorMaxValor(arr, tam - 1);

        return &maxi;
    }
}
