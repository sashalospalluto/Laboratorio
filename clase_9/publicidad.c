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

void publicidad_generadorId(Publicidad* publicidad,int pos)
{
    static int id=1;
    publicidad[pos].idPublicidad=id++;
}

int publicidad_Alta(Publicidad* publicidad, int cantidad, int* posLibre, int* idPublicidad, Pantalla* pantalla, int cantPantalla)
{
    int ret=1;
    char cuit[32];
    int dias;
    char archivo[25];
    int idPantalla;

    if (publicidad_buscarLibre(publicidad,cantidad,posLibre)!=0)
    {
        printf("Se encuentra lleno");
    }
    else
    {
        if (pantalla_buscaYdevuelveId(pantalla,cantPantalla,"\n\nIngrese el ID de la pantalla donde desea publicar: ","\n\nerror al ingresar id",1,100,5,&idPantalla)==0)
        {
            printf("\n\n\tCARGA DE DATOS\n\n");

            if(getStringConNum(cuit,"\n\nIngrese el cuit del cliente: ","\n\nNo ingreso correctamente",2,25,3)==0 &&

             getNumber(&dias,"\n\nIngrese la cantidad de dias", "\n\nerror al ingresar los dias",1,50,5)==0 &&

             getStringConNum(archivo, "\n\nIngrese el nombre del archivo: ", "\n\nerror al ingrresar el nombre de archivo",2,25,3)==0)
             {
                 printf("\nCUIT %s",cuit);
                 printf("\nDIAS %d",dias);
                 printf("\nARCHIVO %s",archivo);

               publicidad_cargarArray(publicidad,*posLibre,cuit,dias,archivo,idPantalla);
                ret=0;
             }
        }
    }
    return ret;

}

void publicidad_cargarArray(Publicidad * publicidad,int posLibre, char cuit[20],int dias, char archivo[25],int idPantalla)
{
    //pantalla[posLibre].idPantalla=
    strcpy(publicidad[posLibre].cuit,cuit);
    strcpy(publicidad[posLibre].archivo,archivo);
    publicidad[posLibre].dias=dias;
    publicidad[posLibre].idPantalla=idPantalla;
    publicidad[posLibre].isEmpty=0;
    publicidad_generadorId(publicidad,posLibre);
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

void publicidad_mostrar(Publicidad* publicidad, Pantalla* pantalla, int cantPublicidad, int cantPantalla)
{
    int pos;
    printf("\n\n\tDATOS INGRESADOS\n\n");
    for (int i=0; i<cantPublicidad; i++)
    {
        if (publicidad[i].isEmpty==0)
        {
            //pos=i;
            printf("\n\n\nid publicidad: %d", publicidad[i].idPublicidad);
            printf("\nisEmpty: %d",publicidad[i].isEmpty);
            pantalla_buscarPorId2(pantalla,cantPantalla,publicidad[i].idPantalla,&pos);
            printf("\nnombre de la pantalla: %s",pantalla[pos].nombre);
            printf("\nCUIT: %s",publicidad[i].cuit);
            printf("\nDias de contracion: %d",publicidad[i].dias);
            printf("\nARCHIVO: %s",publicidad[i].archivo);
        }
    }
}

void publicidad_buscarPublicidad(Publicidad* publicidad, int cantPublicidad,Pantalla* pantalla, int cantPantalla)
{
    char cuit [20];
    int id;
    int posId;
    int dias;
    fflush( stdin ); //LIMPIA BUFFER WINDOWS
   // __fpurge(stdin); //LIMPIA BUFFER LINUX
    if(getStringConNum(cuit,"\nIngrese el cuit de la publicidad que desea modificar: ","error, vuelva a ingresar",2,25,3)==0)
    {
       if (publicidad_buscarPorCuit(publicidad, cantPublicidad,cuit,pantalla, cantPantalla)==0 &&
           pantalla_buscaYdevuelveId(pantalla,cantPantalla,"ingrese el ID que desea modificar: ", "error, vuelva a ingresar: ",1,50,3,&id)==0 &&
           publicidad_buscarIdPantalla(publicidad,cantPublicidad,id,&posId)==0 &&
           getNumber(&dias,"\n\nIngrese la cantidad de dias para esta pantalla: ", "\n\nerror al ingresar los dias: ",1,50,5)==0)
         {
             publicidad[posId].dias=dias;

         }

        else
        {
            printf("\nNO SE ENCONTRO");
        }
    }

}

int publicidad_buscarPorCuit (Publicidad* publicidad,int cantPublicidad,char cuit[20],Pantalla* pantalla, int cantPantalla)
{
    int ret=1;
    int pos;
    int contador=1;
    printf("\n\tPANTALLAS CONTRATADAS POR EL CUIT: %s\n\n",cuit);
    for(int i=0; i<cantPublicidad;i++)
    {
        if(publicidad[i].isEmpty==0)
        {

            if(strncmp(publicidad[i].cuit,cuit,20)==0)
            {
                printf("\n\nPantalla: %d\n",contador);
                contador++;
                pantalla_buscarPorId2(pantalla,cantPantalla,publicidad[i].idPantalla,&pos);
                printf("\nid pantalla: %d", pantalla[pos].idPantalla);
                printf("\nisEmpty: %d",pantalla[pos].isEmpty);
                printf("\nnombre: %s",pantalla[pos].nombre);
                printf("\ndireccion: %s",pantalla[pos].direccion);
                printf("\nprecio: %0.2f",pantalla[pos].precio);

                if (pantalla[pos].tipo==1)
                {
                    printf("\nTipo: Pantalla LCD");
                }
                else
                {
                    printf("\nTipo: Pantalla gigante LED");
                }

                ret=0;
            }
        }
    }
    return ret;
}

int publicidad_buscarIdPantalla(Publicidad* publicidad,int cantidad,int id, int* devuelve)
{
    int ret=1;
    for (int i=0;i<cantidad;i++)
    {
        if(publicidad[i].idPantalla == id)
        {
            ret=0;
            *devuelve=i;
            break;
        }
    }
    return ret;
}

void publicidad_cancelarContratacion(Publicidad* publicidad, int cantPublicidad,Pantalla* pantalla, int cantPantalla)
{
    char cuit [20];
    int id;
    int posId;
    char elecccionBorrar;
    fflush( stdin ); //LIMPIA BUFFER WINDOWS
   // __fpurge(stdin); //LIMPIA BUFFER LINUX
    if(getStringConNum(cuit,"\nIngrese el cuit de la publicidad que desea eliminar: ","error, vuelva a ingresar",2,25,3)==0)
    {
       if (publicidad_buscarPorCuit(publicidad, cantPublicidad,cuit,pantalla, cantPantalla)==0 &&
           pantalla_buscaYdevuelveId(pantalla,cantPantalla,"\n\ningrese el ID de la pantalla que desea eliminar: ", "error, vuelva a ingresar: ",1,50,3,&id)==0 &&
           publicidad_buscarIdPantalla(publicidad,cantPublicidad,id,&posId)==0)
         {
            do
            {
                printf("\n\nSeguro que desea eliminar? (s/n): ");
               // __fpurge(stdin);
                //fflush( stdin ); //LIMPIA BUFFER WINDOWS
                scanf("%c",&elecccionBorrar);

                if(elecccionBorrar=='s')
                {
                    publicidad[posId].isEmpty=1;
                    printf("\n\nBORRADO CON EXITO\n\n");
                }
            }
            while(elecccionBorrar!='s' && elecccionBorrar!='n');
         }

        else
        {
            printf("\nNO SE ENCONTRO");
        }
    }

}

void publicidad_facturacion(Publicidad* publicidad, int cantPublicidad,Pantalla* pantalla, int cantPantalla)
{
    char cuit[20];
    int pos;
    if(getStringConNum(cuit,"\nIngrese el cuit de la publicidad que desea modificar: ","error, vuelva a ingresar",2,25,3)==0)
    {
        printf("\n\n\tIMPORTES");
        for(int i=0; i<cantPublicidad;i++)
        {
            if(publicidad[i].isEmpty==0 &&
               strncmp(publicidad[i].cuit,cuit,20)==0 &&
               pantalla_buscarPorId2(pantalla,cantPantalla,publicidad[i].idPantalla,&pos)==0)
            {
               printf("\npantalla %s,importe: %0.2f",pantalla[pos].nombre,pantalla[pos].precio);
            }
        }
    }
}





