#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //LINUX
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
    int posicionPantalla=0;
    int posicionPublicidad;
    Pantalla pantalla[CANTPANTALLAS];
    Publicidad publicidad[CANCONTRATACIONES];
    int pantalla_id=0;
    int publicidad_id=0;
    int posicionEncontrada;

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
     /* printf("\n\n5-Modificar condiciones de publicacion");
        printf("\n\n6-Cancelar contratacion");
        printf("\n\n7-Consulta facturacion");
     */ printf("\n\n8-Listar contrataciones");
      printf("\n\n9-Listar pantallas");
     //   printf("\n\n10-Informar");
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

                if (pantalla_Alta(pantalla,CANTPANTALLAS,&posicionPantalla,&pantalla_id)==0)
                {
                    printf("\nDatos cargados correctamente\n");
                }
                else
                {
                    printf("\nError al cargar los datos\n");
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
                pantalla_baja(pantalla,posicionEncontrada);
            }
            else
            {
                printf("error al eliminar pantalla\n");
            }
            break;

        case 4:

            pantalla_mostrar(pantalla,CANTPANTALLAS);
            if (publicidad_Alta(publicidad,CANCONTRATACIONES,&posicionPublicidad,&publicidad_id, pantalla, CANTPANTALLAS)==0)
            {
                printf("\nDatos cargados correctamente\n");
            }
            else
            {
                printf("\nError al cargar los datos\n");
            }

            break;


        case 5:



            break;
        case 6:

            break;
        case 7:
            break;

        case 8:
            publicidad_mostrar(publicidad, pantalla, CANCONTRATACIONES, CANTPANTALLAS);

        break;

        case 9:

            pantalla_mostrar(pantalla,CANTPANTALLAS);

            break;
 //       case 10:

  //      break;

        case 11:
            seguir='f';
            break;
        }
    }
    return 0;
}
