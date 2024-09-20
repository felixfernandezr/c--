#include <iostream>

using namespace std;

void invertir (int *, unsigned int);

int main()
{
    unsigned int tam = 5;

    int a[tam] = {1,2,3,4,5};

    int * arrint = new int [tam];

    arrint = a;

    for(unsigned int i = 0 ; i < tam ; i++)
    {
        cout << arrint[i] << " ";
    }

    invertir(arrint, tam);

    cout << endl;

    for(unsigned int i = 0 ; i < tam ; i++)
    {
        cout << arrint[i] << " ";
    }

    return 0;
}

void invertir (int * a, unsigned int s)
{
  if (s > 1)
  {
    int temp = a[0];
    a[0] = a[s - 1];
    a[s - 1] = temp;

    invertir(a + 1, s - 2);
  }
}
