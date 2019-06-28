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

Registro* registro_newParametros(char* id,char* cantidad,char* precio,char* fecha, char* tipoFoto,char* cuit)
{
    Registro* aux;
    aux = registro_new();

    if(aux != NULL)
    {
        registro_setIdChar(aux , id);
        registro_setCantidadChar(aux, cantidad);
        registro_setPrecioChar(aux, precio);
        registro_setFecha(aux, fecha);
        registro_setFoto(aux, tipoFoto);
        registro_setCuit(aux, cuit);
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
        /*if(isValidNumber(idChar)==0)
        {*/
            idAux = atoi(idChar);
            if(registro_setId(this,idAux)==0)
            {
                returnRet=0;
            }
        /*}*/
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
        if(isValidNumber(cantidadChar)==1)
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

int registro_setFecha(Registro* this,char* fecha)
{
    int returnRet =-1;

    if(this != NULL)
    {
         strcpy (this->fecha, fecha);
         returnRet=0;
    }
    return returnRet;
}

int registro_getFecha(Registro* this,char* fecha)
{
    int returnRet =-1;

    if(this != NULL && fecha != NULL)
    {
        strcpy(fecha, this->fecha);
        returnRet =0;
    }
    return returnRet;
}

int registro_setPrecio(Registro* this, float precio)
{
    int returnRet =-1;

    if(this != NULL && precio>0)
    {
        this->precio =precio;
        returnRet = 0;
    }
    return returnRet;
}

int registro_setPrecioChar(Registro* this,char* precioChar)
{
    int returnRet=-1;
    float precioAux;
    if(this!=NULL && precioChar!=NULL)
    {
        if(isValidFloatNumber(precioChar)==1)
        {
            precioAux = atof(precioChar);
            if(registro_setPrecio(this,precioAux)==0)
            {
                returnRet=0;
            }
        }

    }
    return returnRet;
}

int registro_getPrecio(Registro* this,float* precio)
{
    int returnRet=-1;

    if(this != NULL && precio != NULL)
    {
        *precio= this->precio;
        returnRet=0;
    }
    return returnRet;
}

int registro_setFoto(Registro* this,char* foto)
{
    int returnRet =-1;

    if(this != NULL)
    {
         strcpy (this->tipoFoto, foto);
    }
    return returnRet;
}

int registro_getFoto(Registro* this,char* foto)
{
    int returnRet =-1;

    if(this != NULL && foto != NULL)
    {
        strcpy(foto, this->tipoFoto);
        returnRet =1;
    }
    return returnRet;
}

int registro_setCuit(Registro* this,char* cuit)
{
    int returnRet =-1;

    if(this != NULL)
    {
         strcpy (this->cuit, cuit);
         returnRet=0;
    }
    return returnRet;
}

int registro_getCuit(Registro* this,char* cuit)
{
    int returnRet =-1;

    if(this != NULL && cuit != NULL)
    {
        strcpy(cuit, this->cuit);
        returnRet =0;
    }
    return returnRet;
}

int registro_delete(Registro* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}

int fn(Registro* element)
{
    int cant;
    cant=element->cantidad;
    return cant;
}
