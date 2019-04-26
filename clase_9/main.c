#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //LINUX
#include "publicidad.h"
#include "pantalla.h"
#include "empleado.h"
#include "funciones_string.h"
#include <string.h>
#include <ctype.h>
#define CANTPANTALLAS 100
#define CANCONTRATACIONES 1000

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int posicionPantalla;
    int posicionPublicidad;
    Pantalla pantalla[CANTPANTALLAS];
    Publicidad publicidad[CANCONTRATACIONES];
    int pantalla_id=0;
    int posicionEncontrada;
    char elecccionBorrar;

    if (pantalla_Inicializar(pantalla, CANTPANTALLAS)==0)
    {
        printf("Se inicializo correctamente pantalla\n");
    }
    if (publicidad_Inicializar(publicidad, CANCONTRATACIONES)==0)
    {
        printf("Se inicializo correctamente publicidad\n");
    }

    while (seguir=='s')
    {
        printf("\n\t\tMENU");
        printf("\n\n1-Alta de pantalla");
        printf("\n\n2-Modificar datos de pantalla");
        printf("\n\n3-Baja de pantalla");
        printf("\n\n4-Contratar una publicidad");
        printf("\n\n5-Modificar condiciones de publicacion");
        printf("\n\n6-Cancelar contratacion");
        printf("\n\n7-Consulta facturacion");
        printf("\n\n8-Listar contrataciones");
        printf("\n\n9-Listar pantallas");
        printf("\n\n10-Informar");
        printf("\n\n11-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>11);

        switch (opcion)
        {
        case 1:

            if(pantalla_buscarLibre(pantalla,CANTPANTALLAS,&posicionPantalla)!=0)
            {
                printf("Se encuentra lleno\n\n");
            }
            else
            {
                if (pantalla_Alta(pantalla,CANTPANTALLAS,posicionPantalla)==0)
                {
                    pantalla_generadorId(pantalla,posicionPantalla,&pantalla_id);
                    pantalla[posicionPantalla].isEmpty=0;
                }
            }
            break;

        case 2:

            if(pantalla_buscarPorId(pantalla,CANTPANTALLAS,"\ningrese el ID de la pantalla que desea modificar: ","\nError, vuelva a ingresar un ID correcto",1,10000,5, &posicionEncontrada)==0)
            {
                pantalla_modificar(pantalla, posicionEncontrada);
            }
            break;

        case 3:

            if(pantalla_buscarPorId(pantalla,CANTPANTALLAS,"\ningrese el ID de la pantalla que desea eliminar: ","\nError, vuelva a ingresar un ID correcto",1,10000,5, &posicionEncontrada)==0)
            {
                do{
                    printf("\n\nSeguro que desea eliminar? (s/n): ");
                    __fpurge(stdin);
                    scanf("%c",&elecccionBorrar);

                    if(elecccionBorrar=='s')
                    {
                        pantalla_baja(pantalla,posicionEncontrada);
                        printf("\n\nBORRADO CON EXITO\n\n");
                    }

                }while(elecccionBorrar!='s' && elecccionBorrar!='n');
            }
            break;

        case 4:

            pantalla_mostrar(pantalla,CANTPANTALLAS);

            if(publicidad_buscarLibre(publicidad,CANTPANTALLAS,&posicionPublicidad)!=0)
            {
                printf("Se encuentra lleno\n\n");
            }
            else
            {
                if (publicidad_Alta(publicidad,CANCONTRATACIONES,posicionPublicidad)==0)
                {

                    publicidad_generadorId(pantalla,posicionPantalla,&pantalla_id);
                    publicidad[posicionPublicidad].isEmpty=0;
                }
            }
            break;


        case 5:


            break;

        case 6:

            break;
        case 7:



            break;

        case 8:

            pantalla_mostrar(pantalla,CANTPANTALLAS);

            break;

        case 9:



            break;
        case 10:

            break;

        case 11:
            seguir='f';
            break;
        }
    }
    return 0;
}
