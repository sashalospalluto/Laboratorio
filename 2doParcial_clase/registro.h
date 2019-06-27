#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "LinkedList.h"
typedef struct
{
  int id;
  char tipo[100];
  int cantidad;
  char peso;
}Registro;

void registro_cantidadTotalDeEntregas(void* p);
void registro_cantEntregasPorTipo(void* p);
void registro_cantMaxDeBultos(void* p);
void registro_promDeBultos(void* p);
void registro_pesoPromedio(void*p);

Registro* registro_new();
Registro* registro_newParametros(int* id, char* tipo, int* cantidad,float* peso);

int registro_setId(Registro* list,int id);
int registro_getId(Registro* list,int* id);

int registro_setTipo(Registro* list,char* tipo);
int registro_getTipo(Registro* list,char* tipo);

int registro_setPeso(Registro* list,float peso);
int registro_getPeso(Registro* list,float* peso);

int registro_setCantidad(Registro* list,int cant);
int registro_getCantidad(Registro* list,int* cant);

int controller_loadFromText(char* path , LinkedList* registro);
int controller_ListRegistro(LinkedList* registro);

#endif // REGISTRO_H_INCLUDED
