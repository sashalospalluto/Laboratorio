#include <stdio.h>
#include <stdlib.h>
#include "publicidad.h"
#include "pantalla.h"
#include "empleado.h"
#include "funciones_string.h"
#include <string.h>
#include <ctype.h>
#define CANTPANTALLAS 100
#define CANCONTRATACIONES 1000

int pantalla_Inicializar(Pantalla* pantalla, int cantidad)
{
    int ret=1;
    for (int i=0; i<cantidad; i++)
    {
        pantalla[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

int pantalla_buscarLibre(Pantalla* pantalla, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad; i++)
    {
        if (pantalla[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }

        ret=1;
    }

    return ret;
}

int pantalla_Alta(Pantalla* pantalla, int cantidad, int posLibre)
{
    int ret=1;
    printf("\n\n\tCARGA DE DATOS\n\n");
    if(getString(pantalla[posLibre].nombre,"\nIngrese nombre :", "\nNo ingreso correctamente ",3,50,3)==0 &&

            getString(pantalla[posLibre].direccion, "\nIngrese Direccion: ", "\nError de ingreso ",3,200,3)==0 &&

            utn_getFloat(&pantalla[posLibre].precio, "\nIngrese precio: ", "\nError de ingreso ",2,1000,3)==0 &&

            pantalla_asignarPantalla(pantalla,posLibre)==0)
    {
        ret=0;
    }

    return ret;
}

int pantalla_asignarPantalla(Pantalla* pantalla, int posLibre)
{
    int ret=1;
    Pantalla auxPantalla;

    printf("\n\n1-Pantallas LCD - Ubicados en paseos comerciales");
    printf("\n\n2-Pantallas gigantes Led - Ubicadas en la via publica");
    printf("\n\nIngrese la opcion de la pantalla deseada: ");

    scanf("%d",&auxPantalla.tipo);
    if(auxPantalla.tipo==1 || auxPantalla.tipo==2)
    {
        pantalla[posLibre].tipo=auxPantalla.tipo;
        ret=0;
    }
    else
    {
        printf("No ingreso ni 1 ni 2 ");
    }

    return ret;
}

void pantalla_generadorId(Pantalla* pantalla,int pos, int* id)
{
    int aux=0;
    aux=id;
    aux++;

    id=id+1;
    pantalla[pos].idPantalla=id;
}

void pantalla_mostrar (Pantalla* pantalla, int cantidad)
{
    printf("\n\n\tDATOS INGRESADOS\n\n");
    for (int i=0; i<cantidad; i++)
    {
        if (pantalla[i].isEmpty==0)
        {
            printf("\nid pantalla: %d", pantalla[i].idPantalla);
            printf("\nisEmpty: %d",pantalla[i].isEmpty);
            printf("\nnombre: %s",pantalla[i].nombre);
            printf("\ndireccion: %s",pantalla[i].direccion);
            printf("\nprecio: %0.2f",pantalla[i].precio);

            if (pantalla[i].tipo==1)
            {
                printf("\nTipo: Pantalla LCD");
            }
            else
            {
                printf("\nTipo: Pantalla gigantes LED");
            }
        }
    }
}

int pantalla_buscar(Pantalla* pantalla, int cantidad,const char* mensaje, const char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve)
{
    int ret=1;
    Pantalla auxPantalla;

    if(getNumber(auxPantalla.idPantalla,mensaje,mensajeError,minimo,maximo,reintentos)==0)
    {
        for (int i=0;i<cantidad;i++)
        {
            if(strcasecmp(pantalla[i].idPantalla,auxPantalla.idPantalla==0))
            {
                ret=0;
                *devuelve=i;
            }
        }
    }

    return ret;
}
