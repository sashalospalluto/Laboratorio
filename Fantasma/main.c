#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"  //cambiar por nombre entidad
#include "libros.h"
#include "prestamo.h"
#include "socio.h"
#define QTY_TIPO 3

// ME QUEDE EN int libro_modificar(Libro array[], int sizeArray, Autor arrayAutor)
int main()
{
    int opcion;
    int contadorIdautor=0;                   //cambiar
    int contadorIdlibro=0;

    Autor arrayAutor[QTY_TIPO];
    Libro arrayLibro[QTY_TIPO];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_TIPO);
    libro_Inicializar(arrayLibro,QTY_TIPO);                    //cambiar

    strcpy(arrayAutor[0].apellido,"Lospalluto");
    strcpy(arrayAutor[0].nombre,"sasha");
    arrayAutor[0].idUnico=1;
    arrayAutor[0].isEmpty=0;

    strcpy(arrayAutor[1].apellido,"Palmito");
    strcpy(arrayAutor[1].nombre,"matias");
    arrayAutor[1].idUnico=2;
    arrayAutor[1].isEmpty=0;

    strcpy(arrayAutor[2].apellido,"lamas");
    strcpy(arrayAutor[2].nombre,"sergio");
    arrayAutor[2].idUnico=3;
    arrayAutor[2].isEmpty=0;

    do
    {
        utn_getUnsignedInt("\n\n1) Alta autor \n2) Modificar autor \n3) Baja autor \n4) Listar autor \n5) Ordenar autor \n"
                               "6) Alta libro \n7) Modificar libro \n8) Baja libro \n9) Listar libro \n10) Ordenar libro \n11) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,13,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 2: //Modificar
                autor_modificar(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                autor_ordenarPorString(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 6: //Alta
                libro_alta(arrayLibro,QTY_TIPO,&contadorIdlibro,arrayAutor);                   //cambiar

                break;

            case 7: //Modificar
                libro_modificar(arrayLibro,QTY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                libro_baja(arrayLibro,QTY_TIPO);                   //cambiar
                break;

            case 9://Listar
                libro_listar(arrayLibro,QTY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                libro_ordenarPorString(arrayLibro,QTY_TIPO);                   //cambiar
                break;

            case 11://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
