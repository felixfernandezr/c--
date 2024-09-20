#include <iostream>
#include <string>
using namespace std;

unsigned int contar_vocales (char *);

int main()
{
    char a[] = "hola como estas";

    cout << contar_vocales(a) << endl;

    return 0;
}

unsigned int contar_vocales (char * str)
{
    unsigned int i;

    unsigned int cont = 0;

    for(i = 0 ; str[i] != '\0' ; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            for(; str[i] != '\0' ; i++)
            {
                str[i] = str[i+1];
            }

            return cont = 1 + contar_vocales(str);
        }
    }
}

/*
unsigned int contar_vocales (char * str)
{
    unsigned int cont = 0;

    if(str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U')
    {
        return cont = 1 + contar_vocales(str + 1);
    }
    else
        return contar_vocales(str);
}*/



