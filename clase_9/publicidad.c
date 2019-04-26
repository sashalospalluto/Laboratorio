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

int publicidad_Inicializar(Publicidad* publicidad, int cantidad)
{
    int ret=1;
    for (int i=0; i<cantidad;i++)
    {
        publicidad[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

int publicidad_buscarLibre(Publicidad* publicidad, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad; i++)
    {
        if (publicidad[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }
        ret=1;
    }
    return ret;
}

void publicidad_generadorId(Publicidad* publicidad,int pos, int* id)
{
    (*id)++;
    publicidad[pos].idPublicidad=*id;
}

int publicidad_Alta(Publicidad* publicidad, int cantidad, int posLibre)
{
    int ret=1;
    int idEncontrado;

    if (publicidad_buscarPorId(publicidad,cantidad,"\n\nIngrese el ID de la pantalla donde desea publicar: ","\n\nerror al ingresar id",1,100,5,&idEncontrado)==0)
    {
        printf("\n\n\tCARGA DE DATOS\n\n");

        if(getStringConNum(publicidad,"\n\nIngrese el cuit del cliente","\n\nNo ingreso correctamente",1,20,5)==0 &&

         getNumber(publicidad[posLibre].dias,"\n\nIngrese la cantidad de dias", "\n\nerror al ingresar los dias",1,200,5)==0 &&

         getStringConNum(publicidad, "\n\nIngrese el nombre del archivo: ", "\n\nerror al ingrresar el nombre de archivo",2,50,3)==0)
         {
            publicidad[posLibre].idPantalla=idEncontrado;
            ret=0;
         }
    }

    return ret;

}

int publicidad_buscarPorId(Publicidad* publicidad, int cantidad,char* mensaje,char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve)
{
    int ret=1;
    Publicidad auxPublicidad;
    if(getNumber(&(auxPublicidad.idPublicidad),mensaje,mensajeError,minimo,maximo,reintentos)==0)
    {
        for (int i=0;i<cantidad;i++)
        {
            if(publicidad[i].idPublicidad == auxPublicidad.idPublicidad)
            {
                ret=0;
                *devuelve=i;
            }
        }
    }
    return ret;
}

