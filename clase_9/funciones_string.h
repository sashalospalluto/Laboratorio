#ifndef FUNCIONES_STRING_H_INCLUDED
#define FUNCIONES_STRING_H_INCLUDED

#include "empleado.h"

int inicializarArray(char *nombres[]);

int buscarLibre (char lista[][56], int* pIndex, int cantidadPos);

int getString(char *pResult,char *pMsg,char *pMsgError,int min,int max,int intentos);

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);

int validarLetra (char letras[]);

int getStringConNum(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);

int utn_getFloat(float* pResultado,const char* mensaje, const char*mensajeError,int minimo,int maximo,int reintentos);

int  isValidIntNumber (char * cadena);

int  getNumber (int * pResult, char * pMsg, char * pMsgError,int min,int max,int intentos);

int getFloat(float *pResultado);

#endif // FUNCIONES_STRING_H_INCLUDED
