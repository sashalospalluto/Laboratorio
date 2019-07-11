#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    FILE* pf;
    int returnRet=-1;
    int fotosTotales=0;
    int cantVentas1=0;
    int cantVentas2=0;
    int totalPolaroid=0;
    pf=fopen(path,"w");

    if(this!=NULL && pf!=NULL)
    {
        fotosTotales = ll_count(this,cuentaFotos);
        cantVentas1 = ll_count(this, ventasUno);
        cantVentas2 = ll_count(this, ventasDos);
        totalPolaroid = ll_count(this, cuentaPolaroid);

        fprintf(pf,"Registro\n");
        fprintf(pf,"- Cantidad de fotos reveladas: %d\n",fotosTotales);
        fprintf(pf,"- Cantidad de ventas mayores a $150: %d\n",cantVentas1);
        fprintf(pf,"- Cantidad de ventas mayores a $300: %d\n",cantVentas2);
        fprintf(pf,"- Cantidad de fotos polaroids reveladas: %d\n",totalPolaroid);
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
    char fecha[100];
    char tipoFoto[100];
    int cantidad;
    float precio;
    char cuit[100];
    int returnRet=-1;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        registroAux=(Registro*)ll_get(this,index);
        registro_getId(registroAux,&id);
        registro_getFecha(registroAux,fecha);
        registro_getFoto(registroAux,tipoFoto);
        registro_getCantidad(registroAux,&cantidad);
        registro_getPrecio(registroAux,&precio);
        registro_getCuit(registroAux,cuit);
        printf("%d , %s , %s , %d , %.2f , %s\n",id,fecha,tipoFoto,cantidad,precio,cuit);
        returnRet=0;
    }
    return returnRet;
}
