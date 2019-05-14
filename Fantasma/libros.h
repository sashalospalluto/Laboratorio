#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#define TEXT_SIZE 20
#include "autor.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char titulo[TEXT_SIZE];
    int codigoAutor;
}Libro;


#endif // LIBROS_H_INCLUDED

int libro_todoVacio(Libro array[], int size);
void libro_hardcodeo(Libro arrayLibro[]);
int libro_Inicializar(Libro array[], int size);                                    //cambiar libro
int libro_buscarEmpty(Libro array[], int size, int* posicion);                    //cambiar libro
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice);                    //cambiar libro
int libro_alta(Libro array[], int size, int* contadorID, Autor arrayAutor[]);                          //cambiar libro
int libro_baja(Libro array[], int sizeArray);                                      //cambiar libro
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado);
int libro_modificar(Libro array[], int sizeArray, Autor arrayAutor[]);                                //cambiar libro
int libro_ordenarPorString(Libro array[],int size);                              //cambiar libro
int libro_listar(Libro array[], int size);                      //cambiar libro

