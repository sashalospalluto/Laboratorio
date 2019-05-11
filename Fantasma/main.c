#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"  //cambiar por nombre entidad
#include "libros.h"
#include "prestamo.h"
#include "socio.h"
#define QTY_TIPO 5

// ME QUEDE EN int libro_modificar(Libro array[], int sizeArray, Autor arrayAutor)
int main()
{
    int opcion;
    int contadorIdautor=3;                   //cambiar
    int contadorIdlibro=3;
    int contadorIdsocio=3;

    Autor arrayAutor[QTY_TIPO];
    Libro arrayLibro[QTY_TIPO];
    Socio arraySocio[QTY_TIPO];
    autor_Inicializar(arrayAutor,QTY_TIPO);
    libro_Inicializar(arrayLibro,QTY_TIPO);
    socio_Inicializar(arraySocio,QTY_TIPO);                   //cambiar

    strcpy(arrayAutor[0].apellido,"Borges");
    strcpy(arrayAutor[0].nombre,"Luis");
    arrayAutor[0].idUnico=1;
    arrayAutor[0].isEmpty=0;

    strcpy(arrayAutor[1].apellido,"Cortazar");
    strcpy(arrayAutor[1].nombre,"Julio");
    arrayAutor[1].idUnico=2;
    arrayAutor[1].isEmpty=0;

    strcpy(arrayAutor[2].apellido,"Sabato");
    strcpy(arrayAutor[2].nombre,"Ernesto");
    arrayAutor[2].idUnico=3;
    arrayAutor[2].isEmpty=0;

    strcpy(arrayLibro[0].titulo,"Inquisiciones");
    arrayLibro[0].codigoAutor=1;
    arrayLibro[0].isEmpty=0;
    arrayLibro[0].idUnico=1;

    strcpy(arrayLibro[1].titulo,"Rayuela");
    arrayLibro[1].codigoAutor=2;
    arrayLibro[1].isEmpty=0;
    arrayLibro[1].idUnico=2;

    strcpy(arrayLibro[2].titulo,"Tunel");
    arrayLibro[2].codigoAutor=1;
    arrayLibro[2].isEmpty=0;
    arrayLibro[2].idUnico=3;

    strcpy(arraySocio[0].nombre,"Sasha Oriana");
    strcpy(arraySocio[0].apellido,"Lospalluto");
    arraySocio[0].sexo='f';
    arraySocio[0].telefono=1166262107;
    strcpy(arraySocio[0].email,"sasha@hotmail.com");
    arraySocio[0].dia=21;
    arraySocio[0].mes=07;
    arraySocio[0].agno=1997;
    arraySocio[0].isEmpty=0;
    arraySocio[0].idUnico=1;

    strcpy(arraySocio[1].nombre,"Sasha Oriana");//Juan Manuel
    strcpy(arraySocio[1].apellido,"Chico");
    arraySocio[1].sexo='m';
    arraySocio[1].telefono=1168940444;
    strcpy(arraySocio[1].email,"juan@hotmail.com");
    arraySocio[1].dia=25;
    arraySocio[1].mes=8;
    arraySocio[1].agno=1997;
    arraySocio[1].isEmpty=0;
    arraySocio[1].idUnico=2;

    strcpy(arraySocio[2].nombre,"Sasha Oriana");//Sandra Angelica
    strcpy(arraySocio[2].apellido,"Alvez");
    arraySocio[2].sexo='f';
    arraySocio[2].telefono=1165808344;
    strcpy(arraySocio[2].email,"sandra@hotmail.com");
    arraySocio[2].dia=26;
    arraySocio[2].mes=01;
    arraySocio[2].agno=1972;
    arraySocio[2].isEmpty=0;
    arraySocio[2].idUnico=3;

    do
    {
        utn_getUnsignedInt(/*"\n\n1) Alta autor \n2) Modificar autor \n3) Baja autor \n4) Listar autor \n5) Ordenar autor \n"
                               "6) Alta libro \n7) Modificar libro \n8) Baja libro \n9) Listar libro \n10) Ordenar libro \n"*/
                               "11) Alta socio \n12) Modificar socio \n13) Baja socio \n14) Listar socio \n15) Ordenar socio \n16) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,17,1,&opcion);
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
                libro_modificar(arrayLibro,QTY_TIPO,arrayAutor);                   //cambiar
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

            case 11:
                socio_alta(arraySocio,QTY_TIPO,&contadorIdsocio);
                break;

            case 12:
                socio_modificar(arraySocio,QTY_TIPO);
                break;
            case 13:
                socio_baja(arraySocio,QTY_TIPO);
                break;
            case 14:
                socio_listar(arraySocio,QTY_TIPO);
                break;
            case 15:
                socio_ordenarPorString(arraySocio,QTY_TIPO);
            case 16://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=16);
    return 0;
}
