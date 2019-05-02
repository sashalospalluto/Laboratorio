#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

#include "pantalla.h"
typedef struct
{
int idPublicidad;
int isEmpty; //lleno=0 o vacio=1
char cuit[20];
int dias;
char archivo[25];
int idPantalla;
}Publicidad;


int publicidad_Inicializar(Publicidad* publicidad, int cantidad);
int publicidad_buscarLibre(Publicidad* publicidad, int cantidad, int* devuelve);
int publicidad_Alta(Publicidad* publicidad, int cantidad, int* posLibre, int* idPublicidad, Pantalla* pantalla,int cantPantalla);
void publicidad_generadorId(Publicidad* publicidad,int pos, int* id);
void publicidad_cargarArray(Publicidad * publicidad,int posLibre, char cuit[20],int dias, char archivo[25],int idPantalla);
void publicidad_buscarNombrePantalla (Pantalla* pantalla, Publicidad* publicidad, int* posNombre, int cantidad);
int publicidad_buscarPorId(Publicidad* publicidad, int cantidad,char* mensaje,char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve);
void publicidad_mostrar(Publicidad* publicidad, Pantalla* pantalla, int cantPublicidad,int cantPantalla);


#endif // PUBLICIDAD_H_INCLUDED
