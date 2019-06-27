#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
//#include "LinkedList.h"
#include "parser.h"
#include "registro.h"

/** \brief Carga los datos del registro desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* this)
{
    int returnRet=-1;
    FILE* pFile;
    pFile = fopen(path,"r");
    returnRet=parser_registroFromText(pFile, this);
    fclose(pFile);
    return returnRet;
}

int controller_saveAsText(char* path, LinkedList* this)
{
    Registro* registroAux;
    FILE* pf;
    char tipo[4096];
    int cantidad;
    float peso;
    int i;
    int returnRet=-1;
    int len;

    pf=fopen(path,"w");
    if(this!=NULL && pf!=NULL)
    {
        len=ll_len(this);
        for(i=0; i<len; i++)
        {
            registroAux=(Registro*)ll_get(this,i);
            registro_getTipo(registroAux,tipo);
            registro_getCantidad(registroAux,&cantidad);
            registro_getPeso(registroAux,&peso);
        }
        fprintf(pf,"Registro\n");
        fprintf(pf,"- Cantidad total de entregas: \n");
        fprintf(pf,"- Cantidad de entregas por tipo:\n");
        fprintf(pf,"- Cantidad maxima de bultos entregados: \n");
        fprintf(pf,"- Promedio de bultos por entrega: \n");
        fprintf(pf,"- Peso promedio por entrega: \n");
        fclose(pf);
        returnRet=0;
    }
    return returnRet;
}

int controller_printAllRegistros(LinkedList* this)
{
    int returnRet=-1;
    int i,len;
    len=ll_len(this);
    if(this!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            controller_printRegistro(this,i);
            returnRet=0;
        }
    }
    return returnRet;
}

int controller_printRegistro(LinkedList* this, int index)
{
    Registro* registroAux;
    int id;
    char tipo[100];
    int cantidad;
    float peso;
    int returnRet=-1;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        registroAux=(Registro*)ll_get(this,index);
        registro_getId(registroAux,&id);
        registro_getTipo(registroAux,tipo);
        registro_getCantidad(registroAux,&cantidad);
        registro_getPeso(registroAux,&peso);
        printf("%d,%s,%d,%.2f\n",id,tipo,cantidad,peso);
        returnRet=0;
    }
    return returnRet;
}
