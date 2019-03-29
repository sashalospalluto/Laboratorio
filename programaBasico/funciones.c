#include <stdio.h>
#include <stdlib.h>

int funciones_getNumber (int*numero, int max, int min, char*msj,char* errorMsj, int reintento, char*msjReintento)
{
    int error=0;

    for(int i=reintento;i>0;i--)
    {
        printf("\n%s %d\n\n", msjReintento, i);
        printf("%s", msj);
        scanf("%d", numero);

        if((*numero)>min && (*numero)<max)
        {
            error=1;
            break;

        } else
            {
                printf("%s\n",errorMsj);
                printf("--------------------------\n");
            }

    }

    return error;
}

void funciones_validoResultado(int rta)
{
    if(rta==1)
    {
        system("clear");
        printf("Exito");
    } else
        {
            printf("Hubo algun error y devolvio 0\n");

        }
}
