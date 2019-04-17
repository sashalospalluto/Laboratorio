#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"
#include "funciones.h"

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

void funcionMaximo (int* pNumero, int cant, int* maximo)
{
    int* arrayFuncion;
    arrayFuncion=pNumero;
      for (int i=0; i<cant; i++)
    {
        if(i==0)
        {
            *maximo=*(arrayFuncion+i);
        }
        if(*(arrayFuncion+i)>(*maximo))
        {
            *maximo=*(arrayFuncion+i);
        }
    }
}

void funcionMinimo (int* pNumero, int cant, int* minimo)
{
    int* arrayFuncion;
    arrayFuncion=pNumero;
      for (int i=0; i<cant; i++)
    {
        if(i==0)
        {
            *minimo=*(arrayFuncion+i);
        }

        if(*(arrayFuncion+i)<(*minimo))
        {
            *minimo=*(arrayFuncion+i);
        }
    }
}

int funcionIngresarYBuscar(int* pNumero, int cant)
{
    int ret;
    int numero;
    int* arrayFuncion;
    arrayFuncion=pNumero;

    ret=utn_getNumero(&numero, "\ningrese un numero: ", "no es un numero, vuelva a intentar",0,700,3);

    if(ret==0)
    {
        for (int i=0 ; i<cant; i++)
        {
            if (*(arrayFuncion+i)== numero)
            {
                ret=1;
            }
        }
    }

    return ret;

}

void funcionOrdenarArray (int* pNumero, int cant)
{
    //EN LA CLASE 5 DEL CAMPUS HAY OTRA FORMA DE HACERLO
    int* arrayFuncion;
    arrayFuncion=pNumero;

    for (int i=0; i<cant-1; i++)
    {
        for ( int j=0 ; j<cant-1; j++)
        {
            if (arrayFuncion[j] < arrayFuncion[j+1])
            {
                swap(&arrayFuncion[j],&arrayFuncion[j+1]);
            }
        }
    }

    *pNumero=*arrayFuncion;
}


void swap (int* numeroUno, int* numeroDos)
{
    int aux =*numeroUno;
    *numeroUno =*numeroDos;
    *numeroDos = aux;
}
