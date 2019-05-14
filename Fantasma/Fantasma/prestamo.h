#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "socio.h"
#include "libros.h"
#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int codigoLibro;
    int codigoSocio;
    int dia;
    int mes;
    int agno;
}Prestamo;


#endif // PRESTAMO_H_INCLUDED

void prestamo_hardcoeo(Prestamo arrayPrestamo[]);
int prestamo_Inicializar(Prestamo array[], int size);                                    //cambiar prestamo
int prestamo_buscarEmpty(Prestamo array[], int size, int* posicion);                    //cambiar prestamo
int prestamo_buscarID(Prestamo array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamo
int prestamo_buscarInt(Prestamo array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamo
int prestamo_buscarString(Prestamo array[], int size, char* valorBuscado, int* indice);                    //cambiar prestamo
int prestamo_alta(Prestamo array[], int size, int* contadorID,Socio arraySocio[], Libro arrayLibro[]);
int prestamo_baja(Prestamo array[], int sizeArray);                                      //cambiar prestamo
int prestamo_bajaValorRepetidoInt(Prestamo array[], int sizeArray, int valorBuscado);
int prestamo_modificar(Prestamo array[], int sizeArray);                                //cambiar prestamo
int prestamo_ordenarPorString(Prestamo array[],int size);                              //cambiar prestamo
int prestamo_listar(Prestamo array[], int size);                      //cambiar prestamo

