#include <stdio.h>
#include <stdlib.h>
#include "funciones_string.h"


int buscarLibre (char lista[][56], int* pIndex, int cantidadPos)
{
    int i;
    int ret=-1;
    for(i=0; i<cantidadPos;i++)
    {
        printf("%s\n",lista[i]);
        if(lista[i][0]=='\0')
        {
            printf("la %d esta vacia\n",i);
            *pIndex =i;
            ret=0;
            break;
        }
    }

    return ret;
}




//int funcionIngresarNombre

