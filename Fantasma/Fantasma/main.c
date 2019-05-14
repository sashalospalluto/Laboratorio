#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"  //cambiar por nombre entidad
#include "libros.h"
#include "prestamo.h"
#include "socio.h"
#include "informes.h"
#define QTY_TIPO 7

// ME QUEDE EN int libro_modificar(Libro array[], int sizeArray, Autor arrayAutor)
int main()
{
    int opcion;
    int contadorIdautor=3;                   //cambiar
    int contadorIdlibro=3;
    int contadorIdsocio=4;
    int contadorIdPrestamo=3;

    Autor arrayAutor[QTY_TIPO];
    Libro arrayLibro[QTY_TIPO];
    Socio arraySocio[QTY_TIPO];
    Prestamo arrayPrestamo[QTY_TIPO];

    autor_Inicializar(arrayAutor,QTY_TIPO);
    libro_Inicializar(arrayLibro,QTY_TIPO);
    socio_Inicializar(arraySocio,QTY_TIPO);
    prestamo_Inicializar(arrayPrestamo,QTY_TIPO);

    autor_hardcodeo(arrayAutor);
    libro_hardcodeo(arrayLibro);
    socio_hardcodeo(arraySocio);
    prestamo_hardcoeo(arrayPrestamo);

    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n1) Alta autor \n2) Modificar autor \n3) Baja autor \n4) Listar autor\n"
                               "6) Alta libro \n7) Modificar libro \n8) Baja libro \n9) Listar libro\n"
                               "11) Alta socio \n12) Modificar socio \n13) Baja socio \n14) Listar socio\n15)Alta prestamo \n16)Informes \n17) Salir\n \tIngrese una opcion: ",                //cambiar
                      "\nError",1,sizeof(int),1,18,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);
                break;
            case 2: //Modificar
                autor_modificar(arrayAutor,QTY_TIPO);
                break;
            case 3: //Baja
                autor_baja(arrayAutor,QTY_TIPO);
                break;
            case 4://Listar
                autor_listar(arrayAutor,QTY_TIPO);
                break;
            case 5:
                break;
            case 6: //Alta
                libro_alta(arrayLibro,QTY_TIPO,&contadorIdlibro,arrayAutor);
                break;
            case 7: //Modificar
                libro_modificar(arrayLibro,QTY_TIPO,arrayAutor);
                break;
            case 8: //Baja
                libro_baja(arrayLibro,QTY_TIPO);
                break;
            case 9://Listar
                libro_listar(arrayLibro,QTY_TIPO);
                break;
            case 10://Ordenar
                libro_ordenarPorString(arrayLibro,QTY_TIPO);
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
                prestamo_alta(arrayPrestamo,QTY_TIPO,&contadorIdPrestamo,arraySocio,arrayLibro);
                break;
            case 16:
                informe_mostrar(arrayAutor,arrayLibro,arraySocio,arrayPrestamo,QTY_TIPO);
                break;
            case 17://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=17);
    return 0;
}
