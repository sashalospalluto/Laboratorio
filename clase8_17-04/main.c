#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "funciones_string.h"

#define CANTEMPLEADOS 10

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int valor;
    Empleado empleados[CANTEMPLEADOS];

    valor=empleado_Inicializar(&empleados, CANTEMPLEADOS);

    if (valor==0)
    {
        printf("Empleados inicializados correctamente\n\n\n");
    }



    while (seguir=='s')
    {

        printf("\t\tMENU");
        printf("\n\n1-Alta empleado");
        printf("\n\n2-Mostrar empleado");
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

                if (empleado_Altaempleado(empleados, CANTEMPLEADOS)==0)
                {
                    printf("dato ingresado correctamente\n\n");
                }
                else
                {
                    printf("ERROR\n\n");
                }
                break;

            case 2:

                empleado_mostrarArray(empleados, CANTEMPLEADOS);
                break;

            case 3:

                break;

            case 4:

                seguir='f';
                break;
        }
    }
    return 0;
}
