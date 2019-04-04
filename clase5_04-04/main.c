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

    resultado=funcionCargaArray(numeros, CANTIDAD);

    if (resultado==-1)
    {
        printf("\n\nNo se ingresaron los datos correctamente");
    }
    else
    {
        funcionMostrarArray(numeros, CANTIDAD);

        funcionPromedio (numeros, CANTIDAD, &promedio);

        printf("\n%.2f", promedio);
    }

    return 0;
}
