#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

int parser_parseRegistro(char* archivo , LinkedList* listaRegistros)//pFile
{
    int retorno =0;
    Registro* pRegistro;
    int aux;
    int id;
    char tipo [100];
    int cantidad;
    float peso;
   // FILE* archivo;

   // archivo=fopen(pFile,"r");

    if(archivo!= NULL)
    {
        aux= fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]", tipo, tipo, tipo, tipo);
        do
        {
            aux= fscanf(archivo, "%d,%[^,],%d,%f \n", &id, tipo, &cantidad, &peso);
            if(aux ==4)
            {
                pRegistro = registro_newParametros(&id, tipo, &cantidad,&peso);
                ll_add(listaRegistros, pRegistro);
                retorno = 1;
            }
        }while(!feof(archivo));
    }

   // fclose(archivo);
    return retorno;
}

