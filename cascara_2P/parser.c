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
    char id[4096];
    char tipo[4096];
    char cantidad[4096];
    char peso[4096];

    if(pFile!=NULL && this!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,id,id,id);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,tipo,cantidad,peso);

            pElement = registro_newParametros(id,tipo,cantidad,peso);

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
