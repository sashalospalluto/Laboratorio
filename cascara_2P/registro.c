#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "LinkedList.h"
#include "utn.h"

Registro* registro_new()
{
    return (Registro*) malloc(sizeof (Registro));
}

Registro* registro_newParametros(char* id, char* tipo, char* cantidad,char* peso)
{
    Registro* aux;
    aux = registro_new();

    if(aux != NULL)
    {
        registro_setIdChar(aux , id);
        registro_setTipo(aux, tipo);
        registro_setPesoChar(aux, peso);
        registro_setCantidadChar(aux, cantidad);
    }
    return aux;
}

int registro_setId(Registro* this,int id)
{
    int returnRet =-1;

    if(this != NULL && id>0)
    {
        this->id =id;
        returnRet = 0;
    }
    return returnRet;
}

int registro_setIdChar(Registro* this,char* idChar)
{
    int returnRet=-1;
    int idAux;
    if(this!=NULL && idChar!=NULL)
    {
        if(isValidNumber(idChar)==0)
        {
            idAux = atoi(idChar);
            if(registro_setId(this,idAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int registro_getId(Registro* this,int* id)
{
    int returnRet=-1;

    if(this != NULL && id != NULL)
    {
        *id= this->id;
        returnRet=0;
    }
    return returnRet;
}

int registro_setCantidad(Registro* this,int cant)
{
    int returnRet =-1;

    if(this != NULL && cant>0)
    {
        this->cantidad =cant;
        returnRet = 0;
    }
    return returnRet;
}

int registro_setCantidadChar(Registro* this,char* cantidadChar)
{
    int returnRet=-1;
    int cantidadAux;
    if(this!=NULL && cantidadChar!=NULL)
    {
        if(isValidNumber(cantidadChar)==0)
        {
            cantidadAux = atoi(cantidadChar);
            if(registro_setCantidad(this,cantidadAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int registro_getCantidad(Registro* this,int* cant)
{
    int returnRet=-1;

    if(this != NULL && cant != NULL)
    {
        *cant= this->cantidad;
        returnRet=0;
    }
    return returnRet;
}

int registro_setTipo(Registro* this,char* tipo)
{
    int returnRet =-1;

    if(this != NULL)
    {
         strcpy (this->tipo, tipo);
    }
    return returnRet;
}

int registro_getTipo(Registro* this,char* tipo)
{
    int returnRet =-1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        returnRet =1;
    }
    return returnRet;
}

int registro_setPeso(Registro* this, float peso)
{
    int returnRet =-1;

    if(this != NULL && peso>0)
    {
        this->cantidad =peso;
        returnRet = 0;
    }
    return returnRet;
}

int registro_setPesoChar(Registro* this,char* pesoChar)
{
    int returnRet=-1;
    int pesoAux;
    if(this!=NULL && pesoChar!=NULL)
    {
        if(isValidFloatNumber(pesoChar)==0)
        {
            pesoAux = atof(pesoChar);
            if(registro_setPeso(this,pesoAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int registro_getPeso(Registro* this,float* peso)
{
    int returnRet=-1;

    if(this != NULL && peso != NULL)
    {
        *peso= this->peso;
        returnRet=0;
    }
    return returnRet;
}
