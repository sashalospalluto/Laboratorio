#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString(  char *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attemps)
{
    int ret=-1;
    char bufferStr[4096];
    while(attemps>0)
    {
        printf(pMsg);
        fgets(bufferStr,sizeof(bufferStr),stdin);
        bufferStr[strlen(bufferStr)-1] = '\0';
        if( pResult != NULL &&
            strlen(bufferStr) >= min &&
            strlen(bufferStr) <= max)
        {
            strncpy(pResult,bufferStr,max);
            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        attemps--;
    }

    return ret;
}

int isValidIntNumber (char* cadena)
{
    int ret = 1;
    int i=0;
    if(cadena[i] == '-')
    {
        i++;
    }
    for(;cadena[i] != '\0';i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            ret=0;
            break;
        }
    }

    return ret;
}

int getNumber(  int *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    int bufferInt;

    if(pResult != NULL &&
        attempts >= 0) //FALTAN
    {
        if(!getString(bufferStr,pMsg,pMsgError,1,7,10) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= min && bufferInt <= max)
            {
                ret = 0;
                *pResult = bufferInt;
            }
        }
    }
    return ret;
}
