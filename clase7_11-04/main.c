#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones_string.h"
#define CANTIDAD 100

int main()
{
    char seguir='s';
    int opcion;
    char nombres [CANTIDAD][56];
    int ret;
    int i;
    int posVacia;
    char auxNombres[56];


    for (i=0; i<CANTIDAD; i++)
    {
        nombres[i][0]='\0';
    }

    while (seguir=='s')
    {

        printf("\t\tMENU");
        printf("\n\n1-Ingresar un nuevo nombre");
        printf("\n\n2-Ordenar por nombre");
        printf("\n\n3-Borrar nombre");
        printf("\n\n4-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }while (opcion<1 || opcion>4);

        switch (opcion)
        {
            case 1:

            if (buscarLibre(nombres, &posVacia,CANTIDAD)==0)
            {
                printf("pos vacia: %d \n\n",posVacia);
            }

            if (getString(auxNombres, "ingrese un nombre: ", "Ingreso invalido, vuelva a ingresar", 1, CANTIDAD, 3)==0)
            {
                strcpy(nombres[posVacia],auxNombres);

                printf("Ingreso: %s en la pos %d", nombres[posVacia], posVacia);
            }



                break;

            case 2:

                break;

            case 3:



//                buscarNombre (buffer,nombres, LEN LISTA, &posAeliminar);

                break;

            case 4:

                seguir='f';
                break;


        }
    }

    return 0;
}

