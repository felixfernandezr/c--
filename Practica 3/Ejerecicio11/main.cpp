#include <iostream>

using namespace std;

void ordenar(int * arr[], int n)
{
    if (n == 1)
        return;

    int * aux;
    for(unsigned int i = 0 ; i < n-1 ; i++)
    {
        if(*arr[i] > *arr[i+1])
        {
            aux = *arr[i];
            *arr[i] = *arr[i+1];
            *arr[i] = aux;
        }
    }

    ordenar(arr, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 8;

    int a[n] = {54, 25, 62, 12, 76, 9, 87, 0};

    int * arr = new int [n];

    arr = a;

    ordenar(arr, n);

    for(unsigned int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    printArray(arr, n);

    return 0;
}
