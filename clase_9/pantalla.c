#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
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

int pantalla_buscarLibre(Pantalla * pantalla, int cantidad, int * devuelve)
{
    int ret=1;
    for (int i=0; i<cantidad; i++)
    {
        if (pantalla[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int pantalla_Alta(Pantalla* pantalla, int cantidad, int* posLibre,int *pantalla_id)
{
    //Pantalla auxPantalla[cantidad];

    char nombre[50];
    char direccion [200];
    float precio;
    int tipo;
    int ret=1;

    if(pantalla_buscarLibre(pantalla,cantidad,posLibre)!=0)
    {
        printf("Se encuentra lleno\n\n");
    }
    else
    {
        printf("\n\n\tCARGA DE DATOS\n\n");
        if(getString(nombre,"\nIngrese nombre :", "\nNo ingreso correctamente ",3,50,3)==0 &&

                getString(direccion, "\nIngrese Direccion: ", "\nError de ingreso ",3,200,3)==0 &&

                utn_getFloat(&precio, "\nIngrese precio: ", "\nError de ingreso ",2,100000000,3)==0 &&

                pantalla_asignarPantalla(&tipo)==0)
        {
            pantalla_cargarArray(pantalla,*posLibre,tipo, nombre, direccion,precio);
            ret=0;
        }
    }
    return ret;
}

void pantalla_cargarArray(Pantalla * pantalla,int posLibre, int tipoPantalla, char nombre[50],char direccion[200], float precio)
{

    //pantalla[posLibre].idPantalla=

    strcpy(pantalla[posLibre].nombre,nombre);
    strcpy(pantalla[posLibre].direccion,direccion);
    pantalla[posLibre].precio=precio;
    pantalla[posLibre].tipo=tipoPantalla;
    pantalla[posLibre].isEmpty=0;

    pantalla_generadorId(pantalla,posLibre);

}
int pantalla_asignarPantalla(int* tipoPantalla)
{
    int ret=1;
    int i=3;
    int auxTipo;

    while (i!=0)
    {
        printf("\n\n1-Pantallas LCD - Ubicados en paseos comerciales");
        printf("\n\n2-Pantallas gigantes Led - Ubicadas en la via publica");
        printf("\n\nIngrese la opcion de la pantalla deseada: ");

        scanf("%d",&auxTipo);
        if(auxTipo==1 || auxTipo==2)
        {
            *tipoPantalla=auxTipo;
            ret=0;
            break;
        }
        else
        {
            printf("No ingreso ni 1 ni 2 ");
            i--;
        }
    }
    return ret;
}

void pantalla_generadorId(Pantalla* pantalla,int pos)
{
    static int id=1;
    pantalla[pos].idPantalla=id++;
}

void pantalla_mostrar (Pantalla* pantalla, int cantidad)
{
    printf("\n\n\tDATOS INGRESADOS\n\n");
    for (int i=0; i<cantidad; i++)
    {
        if (pantalla[i].isEmpty==0)
        {
            printf("\n\n\nid pantalla: %d", pantalla[i].idPantalla);
            printf("\nisEmpty: %d",pantalla[i].isEmpty);
            printf("\nnombre: %s",pantalla[i].nombre);
            printf("\ndireccion: %s",pantalla[i].direccion);
            printf("\nprecio: %0.2f",pantalla[i].precio);
            printf("\npos: %d\n",i);

            if (pantalla[i].tipo==1)
            {
                printf("\nTipo: Pantalla LCD");
            }
            else
            {
                printf("\nTipo: Pantalla gigante LED");
            }
        }
    }
}

int pantalla_buscarPorId(Pantalla* pantalla, int cantidad,char* mensaje,char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve)
{
    int ret=1;
    Pantalla auxPantalla;
    if(getNumber(&(auxPantalla.idPantalla),mensaje,mensajeError,minimo,maximo,reintentos)==0)
    {

        for (int i=0;i<cantidad;i++)
        {
            if(pantalla[i].idPantalla==auxPantalla.idPantalla)
            {
                ret=0;
                *devuelve=i;
            }
        }
    }
    return ret;
}

void pantalla_modificar(Pantalla* pantalla, int posicion)
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int tipoPantalla;

    while (seguir=='s')
    {
        printf("\n\t\tMODIFICACIONES");
        printf("\n\n1-nombre");
        printf("\n\n2-Direccion");
        printf("\n\n3-Precio");
        printf("\n\n4-tipo");
        printf("\n\n5-Salir\n");

        do
        {
            printf("\n\t\tingrese la opcion que desea modificar: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>5);

        switch (opcion)

        {
            case 1:

                if(getString(pantalla[posicion].nombre,"\nIngrese nombre :", "\nNo ingreso correctamente ",3,50,3)==0)
                {
                    printf("Nombre modificado con exito!\n\n");
                }
                else
                {
                    printf("Error, no ingreso correctamente los datos!\n\n");
                }
                break;

            case 2:

                if(getString(pantalla[posicion].direccion, "\nIngrese Direccion: ", "\nError de ingreso ",3,200,3)==0)
                {
                    printf("Direccion modificada con exito!\n\n");
                }
                else
                {
                    printf("Error, no ingreso correctamente los datos!\n\n");
                }
                break;

            case 3:

                if(utn_getFloat(&pantalla[posicion].precio, "\nIngrese precio: ", "\nError de ingreso ",2,100000000,3)==0)
                {
                    printf("Precio modificado con exito!\n\n");
                }
                else
                {
                    printf("Error, no ingreso correctamente los datos!\n\n");
                }
                break;

            case 4:

                if(pantalla_asignarPantalla(&tipoPantalla)==0)
                {
                    pantalla[posicion].tipo=tipoPantalla;
                    printf("Pantalla modificada con exito!\n\n");
                }
                else
                {
                    printf("Error, no ingreso correctamente los datos!\n\n");
                }
                break;

            case 5:
                seguir='f';
                break;
        }
    }
}
void pantalla_baja(Pantalla* pantalla, int posicion)
{
    char elecccionBorrar;
    do
    {
        printf("\n\nSeguro que desea eliminar? (s/n): ");
       // __fpurge(stdin);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        scanf("%c",&elecccionBorrar);

        if(elecccionBorrar=='s')
        {
            pantalla[posicion].isEmpty=1;
            printf("\n\nBORRADO CON EXITO\n\n");
        }
    }
    while(elecccionBorrar!='s' && elecccionBorrar!='n');
}


int pantalla_buscarPorId2(Pantalla* pantalla, int cantidad,int id, int* devuelve)
{
    int ret=1;
    for (int i=0;i<cantidad;i++)
    {
        if(pantalla[i].isEmpty==0)
        {
            if(pantalla[i].idPantalla==id)
            {
                ret=0;
                *devuelve=i;
                break;
            }
        }
    }
    return ret;
}

int pantalla_buscaYdevuelveId(Pantalla* pantalla, int cantidad,char* mensaje,char*mensajeError,int minimo,int maximo,int reintentos, int* devuelveId)
{
    int ret=1;
    Pantalla auxPantalla;
    if(getNumber(&(auxPantalla.idPantalla),mensaje,mensajeError,minimo,maximo,reintentos)==0)
    {

        for (int i=0;i<cantidad;i++)
        {
            if(pantalla[i].idPantalla==auxPantalla.idPantalla)
            {
                ret=0;
                *devuelveId=auxPantalla.idPantalla;
            }
        }
    }
    return ret;
}
