#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "LinkedList.h"

Registro* registro_new()
{
    return (Registro*) malloc(sizeof (Registro));
}

Registro* registro_newParametros(int* id, char* tipo, int* cantidad,float* peso)
{
    Registro* aux;
    aux = registro_new();

    if(aux != NULL)
    {
        registro_setId(aux , *id);
        registro_setTipo(aux, tipo);
        registro_setPeso(aux, *peso);
        registro_setCantidad(aux, *cantidad);
    }
    return aux;
}

int registro_setId(Registro* list,int id)
{
    int returnRet =-1;

    if(list != NULL && id>0)
    {
        list->id =id;
        returnRet = 0;
    }
    return returnRet;
}

int registro_getId(Registro* list,int* id)
{
    int returnRet=-1;

    if(list != NULL && id != NULL)
    {
        *id= list->id;
        returnRet=0;
    }
    return returnRet;
}

int registro_setCantidad(Registro* list,int cant)
{
    int returnRet =-1;

    if(list != NULL && cant>0)
    {
        list->cantidad =cant;
        returnRet = 0;
    }
    return returnRet;
}

int registro_getCantidad(Registro* list,int* cant)
{
    int returnRet=-1;

    if(list != NULL && cant != NULL)
    {
        *cant= list->cantidad;
        returnRet=0;
    }
    return returnRet;
}

int registro_setTipo(Registro* list,char* tipo)
{
    int returnRet =-1;

    if(list != NULL)
    {
         strcpy (list->tipo, tipo);
    }
    return returnRet;
}

int registro_getTipo(Registro* list,char* tipo)
{
    int returnRet =-1;

    if(list != NULL && tipo != NULL)
    {
        strcpy(tipo, list->tipo);
        returnRet =1;
    }
    return returnRet;
}

int registro_setPeso(Registro* list, float peso)
{
    int returnRet =-1;

    if(list != NULL && peso>0)
    {
        list->cantidad =peso;
        returnRet = 0;
    }
    return returnRet;
}

int registro_getPeso(Registro* list,float* peso)
{
    int returnRet=-1;

    if(list != NULL && peso != NULL)
    {
        *peso= list->peso;
        returnRet=0;
    }
    return returnRet;
}

int controller_loadFromText(char* path , LinkedList* registro)
{
    FILE* f;
    int aux;
    f = fopen (path, "r");

    if(f == NULL)
    {
        aux = 0;
        printf("Problemas al crear el archivo de texto\n");
        system("pause");
    }
    else
    {
         aux = 1;
         printf("Archivo de texto abierto con exito\n");
         aux= parser_parseRegistro(f , registro);
         system("pause");
    }
    return aux;
}

int controller_ListRegistro(LinkedList* registro)
{
    int i;
    Registro* casteo;
    int id,cantidad;
    float peso;
    char tipo[100];

    if(registro == NULL){
        printf("No se pudo abrir");
    }
    else{
        for(i=0; i<ll_len(registro); i++){
            casteo=ll_get(registro, i);

            registro_getId(casteo,&id);
            registro_getTipo(casteo,tipo);
            registro_getCantidad(casteo,&cantidad);
            registro_getPeso(casteo,&peso);

            printf("%d %s %d %f\n", id, tipo, cantidad, peso);
        }
    }
    return 1;
}
