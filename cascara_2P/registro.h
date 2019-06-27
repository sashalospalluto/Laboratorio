#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "LinkedList.h"
typedef struct
{
    int id;
    char tipo[100];
    int cantidad;
    float peso;
}Registro;

Registro* registro_new();
Registro* registro_newParametros(char* id, char* tipo, char* cantidad,char* peso);

int registro_setId(Registro* this,int id);
int registro_setIdChar(Registro* this,char* idChar);
int registro_getId(Registro* this,int* id);

int registro_setCantidad(Registro* this,int cant);
int registro_setCantidadChar(Registro* this,char* cantidadChar);
int registro_getCantidad(Registro* this,int* cant);

int registro_setTipo(Registro* this,char* tipo);
int registro_getTipo(Registro* this,char* tipo);

int registro_setPeso(Registro* this, float peso);
int registro_setPesoChar(Registro* this,char* pesoChar);
int registro_getPeso(Registro* this,float* peso);

int controller_loadFromText(char* path , LinkedList* registro);
int controller_ListRegistro(LinkedList* registro);

#endif // REGISTRO_H_INCLUDED
