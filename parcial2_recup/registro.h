#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "LinkedList.h"
typedef struct
{
    int id;
    char fecha[100];
    char tipoFoto[100];
    int cantidad;
    float precio;
    char cuit [100];
}Registro;

Registro* registro_new();
Registro* registro_newParametros(char* id,char* cantidad,char* precio,char* fecha, char* tipoFoto,char* cuit);

int registro_setId(Registro* this,int id);
int registro_setIdChar(Registro* this,char* idChar);
int registro_getId(Registro* this,int* id);

int registro_setCantidad(Registro* this,int cant);
int registro_setCantidadChar(Registro* this,char* cantidadChar);
int registro_getCantidad(Registro* this,int* cant);

int registro_setFoto(Registro* this,char* tipoFoto);
int registro_getFoto(Registro* this,char* tipoFoto);

int registro_setPrecio(Registro* this, float precio);
int registro_setPrecioChar(Registro* this,char* precioChar);
int registro_getPrecio(Registro* this,float* precio);

int registro_setFecha(Registro* this,char* fecha);
int registro_getFecha(Registro* this,char* fecha);

int registro_setCuit(Registro* this,char* cuit);
int registro_getCuit(Registro* this,char* cuit);

int controller_loadFromText(char* path , LinkedList* registro);
int controller_ListRegistro(LinkedList* registro);
int registro_delete(Registro* this);

int cuentaFotos(void* element);
int ventasUno (void* element);
int ventasDos (void* element);
int cuentaPolaroid (void* element);

#endif // REGISTRO_H_INCLUDED
