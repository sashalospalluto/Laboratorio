#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 3
#include "function.h"
#include "funciones.h"

int main()
{
    int numeros[CANTIDAD];
    float promedio;
    int resultado;
    int maximo;
    int minimo;
    int valor;

    printf("----------------NUMEROS INGRESADOS-------------------\n");
    resultado=funcionCargaArray(numeros, CANTIDAD);

    if (resultado==-1)
    {
        printf("\n\nNo se ingresaron los datos correctamente");
    }
    else
    {
        printf("\n----------------OPERACIONES REALIZADAS-------------------\n");

        funcionPromedio (numeros, CANTIDAD, &promedio);
        funcionMaximo(numeros, CANTIDAD,&maximo);
        funcionMinimo(numeros, CANTIDAD, &minimo);

        printf("\npromedio: %.2f", promedio);
        printf("\nmaximo: %d",maximo);
        printf("\nminimo: %d",minimo);

        printf("\n----------------BUSQUEDA DE VALOR EN EL ARRAY-------------------\n");

        valor=funcionIngresarYBuscar(numeros, CANTIDAD);

        if(valor==1)
        {
            printf("\neste valor se encuentra en el array!\n");
        }
        else if (valor==0)
        {
            printf("\nel valor no se encuentra en el array\n");
        }
        else
        {
            printf("\nLo que ingreso no fue un numero\n");
        }

        printf("\n----------------ARRAY ORDENADO DE MAYOR A MENOR-------------------\n");

        funcionOrdenarArray(numeros, CANTIDAD);
        funcionMostrarArray(numeros, CANTIDAD);
    }

    return 0;
}
