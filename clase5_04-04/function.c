#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int funcionCargaArray (int* pNumero, int cant)
{
    int ret=0;
    int arrayFuncion[cant];
    for (int i=0; i<cant ;i++)
    {
        ret=utn_getNumero(arrayFuncion, "\ningrese un numero: ", "no es un numero, vuelva a intentar",0,700,3);

        if(ret==0)
        {
            *(pNumero+i)=(*arrayFuncion);
        }
        else
        {
            break;
        }

    }

    return ret;
}

void funcionMostrarArray (int* pNumero, int cant)
{
    for (int i=0; i<cant; i++)
    {
        printf("\n %d", *(pNumero+i));
    }
}

void funcionPromedio(int* pNumero, int cant, float* promedio)
{
    int sumaArray=0;

    for (int i=0 ; i<cant ; i++)
    {
        sumaArray=sumaArray+*(pNumero+i);
    }

    (*promedio)=sumaArray/cant;
}
