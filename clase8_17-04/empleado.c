#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_string.h"
#include "empleado.h"

int empleado_Inicializar(Empleado* empleados, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        empleados[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

void empleado_mostrarArray(Empleado* empleados, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        if(empleados[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, empleados[i].isEmpty);
            printf("posicion %d :%s\n", i, empleados[i].nombre);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}

int empleado_buscarLibre(Empleado* empleados, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        if (empleados[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }

        ret=1;
    }

    return ret;
}

int empleado_Altaempleado(Empleado* empleados, int cantidad)
{
    int ret;
    int posLibre;

    if(empleado_buscarLibre(empleados, cantidad, &posLibre)==0)
    {
        ret = getString(empleados[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,2);
        if (ret==0)
        {
            empleados[posLibre].isEmpty=0;

        }
    }
    else
    {
        ret=1;
    }

    return ret;
}
