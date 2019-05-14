#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamo.h"
#include "socio.h"
#include "libros.h"
#include "fantasma.h"  //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int Informes_listarPorCriterio(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1 && strcmpi(arrayA[i].varString,criterio)!=0)
            {
                continue;
            }
            else
            {
                fantasma_buscarID(arrayB,sizeJ,arrayA[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int Informes_listarCriterioContadorAcumulado(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].varString);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmpi(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                        printf("\nID A: %d\nID B: %d",
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_maxContadorAcumulado(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].varString);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmpi(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[k].varInt*arrayB[j].varInt);

                        printf("\nID A: %d\nID B: %d",                                         //imprimo datos que haya que mostrar
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].varString);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].varString);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Fantasma arrayAux[sizeI];                                                           //cambiar Fantasma y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].varString,arrayA[i].varString);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmpi(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                    }
                }
                arrayAux[i].varInt=contador;                                    //completo el resto de los campos
                arrayAux[i].varInt=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

void informe_totalGeneral(Prestamo array[], int size)
{
    int contador=0;
    int i;

    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
            contador++;
        }
    }
    printf("\nTotal general de prestamos: %d",contador);
}

void informe_libroDeterminado(Socio arraySocio[], Prestamo arrayPrestamo[],Libro arrayLibro[], int size)
{
    int i;
    int j;
    int opcion;
    int posSocio;
    printf("\n\tLIBROS\n");
    for(i=0;i<size;i++)
    {
        if(arrayLibro[i].isEmpty==0)
        {
            printf("\n %d- %s",i,arrayLibro[i].titulo);
        }
    }
    utn_getUnsignedInt("\nIngrese el libro para listar los socios: ","error",0,sizeof(int),0,size,3,&opcion);

    printf("\nSocios que solicitaron el libro %s\n",arrayLibro[opcion].titulo);
    for(j=0; j<size;j++)
    {
        if((arrayLibro[opcion].idUnico==arrayPrestamo[j].codigoLibro) && (arrayPrestamo[j].isEmpty==0))
        {
            socio_buscarID(arraySocio,size,arrayPrestamo[j].codigoSocio,&posSocio);
            printf("\n- %s %s",arraySocio[posSocio].nombre, arraySocio[posSocio].apellido);
        }
    }
}


void informe_mostrar(Autor arrayAutor[], Libro arrayLibro[], Socio arraySocio[], Prestamo arrayPrestamo[], int size)
{
    int opcion;
    do{
        utn_getUnsignedInt("\n1) Informar el Total general y Promedio diario de las solicitudes a prestamo de los libros"
                            "\n2) Informar la cantidad de dias cuya solicitud a prestamo NO superan el promedio del item anterior"
                            "\n3) Listar todos los socios que solicitaron el prestamo de un libro determinado"
                            "\n4) Listar todos los libros que fueron solicitados a prestamo por un socio determinado"
                            "\n5) Listar el/los libro/s menos solicitado/s en prestamo"
                            "\n6) Listar el/los socios que realizo/realizaron más solicitudes a prestamo"
                            "\n7) Listar todos los libros solicitados a prestamo en una fecha determinada"
                            "\n8) Listar todos los socios que realizaron al menos una solicitud a prestamo en una fecha determinada"
                            "\n9) Listar todos los libros ordenados por Titulo (descendente), utilizando el metodo de burbujeo mas eficiente"
                            "\n10) Listar todos los socios ordenados por Apellido (ascendente), utilizando el metodo de insercion"
                            "\n11) Salir"
                            "\n\tElija una opcion: ","error",1,sizeof(int),1,12,3,&opcion);
        switch(opcion)
        {
        case 1:
            informe_totalGeneral(arrayPrestamo,size);
            break;
        case 2:
            break;
        case 3:
            informe_libroDeterminado(arraySocio,arrayPrestamo,arrayLibro,size);
            break;
        case 11: //salir
            break;
        default:
            printf("\nOpcion Incorrecta\n");
        }

    }while(opcion!=11);
}
