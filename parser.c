#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "registro.h"
#include "LinkedList.h"

/** \brief Parsea los datos de los entregas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int parser_registroFromText(FILE* pFile, LinkedList* this)
{
    int returnRet= 0;
    Registro *pElement;
    char id[100];
    char cantidad[100];
    char precio[100];
    char fecha[100];
    char tipoFoto[100];
    char cuit[100];


    if(pFile!=NULL && this!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,id,id,id,id,id);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,fecha,tipoFoto,cantidad,precio,cuit);

            pElement = registro_newParametros(id,cantidad,precio,fecha,tipoFoto,cuit);

            if(pElement != NULL)
            {
                if(ll_add(this,pElement)==0)
                {
                    returnRet++;
                }
            }
        }
    }
    return returnRet;
}
