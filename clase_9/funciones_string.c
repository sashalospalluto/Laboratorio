#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //linux
#include "publicidad.h"
#include "pantalla.h"
#include "empleado.h"
#include "funciones_string.h"
#include <string.h>
#include <ctype.h>
#define CANTPANTALLAS 100
#define CANCONTRATACIONES 1000


int buscarLibre (char lista[][56], int* pIndex, int cantidadPos)
{
    int i;
    int ret=-1;
    for(i=0; i<cantidadPos;i++)
    {
        printf("%s\n",lista[i]);
        if(lista[i][0]=='\0')
        {
            *pIndex =i;
            ret=0;
            break;
        }
    }
    return ret;
}

int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    char arrayAuxiliar[20];
    while(intentos>0)
    {
        printf(pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max /*&& validarLetra(arrayAuxiliar)==0*/)
        {
            strncpy(pResult,arrayAuxiliar,max);

            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        intentos--;
    }
    return ret;
}

int validarLetra (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0 || letras[i]==' ')
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

int getStringConNum(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    char arrayAuxiliar[20];
    while(intentos>0)
    {
        printf(pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX

        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';

        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max )
        {
            strncpy(pResult,arrayAuxiliar,max);
            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        intentos--;
    }
    return ret;
}

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{

    //fflush( stdin ); //LIMPIA BUFFER WINDOWS
    __fpurge(stdin); //LIMPIA BUFFER LINUX
    int ret;
    float num;
    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
        //__fpurge(stdin); //LIMPIA BUFFER LINUX
        reintentos--;
        printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);
    *pResultado = atof(buffer);
    return 0;
}

int  isValidIntNumber (char * cadena)
{
    int ret = 1 ;
    /*if (cadena [i] == ' - ' )
    {
        i ++;
    }*/
    for (int i=0;cadena [i] != '\0' ; i ++)
    {
        if (cadena [i] < '0' || cadena [i]> '9' )
        {
            ret = 0 ;
            break ;
        }
    }
    return ret;
}

int  getNumber (int * pResult, char * pMsg, char * pMsgError,int min,int max,int intentos)
{
    int ret = 1;
    char bufferStr [100];
    int bufferInt;

    if (pResult != NULL && intentos >= 0 ) // FALTAN
    {
        if (!getStringConNum(bufferStr, pMsg, pMsgError, 1 , 10, intentos) && isValidIntNumber (bufferStr))
        {
            bufferInt = atoi (bufferStr);

            if (bufferInt >= min && bufferInt <= max)
            {
                ret = 0 ;
                * pResult = bufferInt;
                //printf("NUMERO EN FUNCION %d\n",*pResult);
            }
        }
    }
    return ret;
}
