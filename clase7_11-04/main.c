#include <stdio.h>
#include <stdlib.h>
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


    for (i=0; i<100; i++)
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


       if(ret==0)
       {
        printf("error");
       }

        switch (opcion)
        {
            case 1:

            if (buscarLibre(nombres, &posVacia,CANTIDAD)==0)
            {
                printf("pos vacia: %d",posVacia);
            }

            printf("Ingrese un nombre: ");



                //funcionIngresarNombre()


                break;

            case 2:

                break;

            case 3:



                buscarNombre (buffer,nombres, LEN LISTA, &posAeliminar);

                break;

            case 4:

                seguir=='f';
                break;


        }



    }

}

