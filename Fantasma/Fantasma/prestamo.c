#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamo.h" //cambiar por nombre entidad


void prestamo_hardcoeo(Prestamo arrayPrestamo[])
{
    arrayPrestamo[0].idUnico=1;
    arrayPrestamo[0].isEmpty=0;
    arrayPrestamo[0].codigoLibro=1;
    arrayPrestamo[0].codigoSocio=1;
    arrayPrestamo[0].dia=21;
    arrayPrestamo[0].mes=07;
    arrayPrestamo[0].agno=2018;

    arrayPrestamo[1].idUnico=2;
    arrayPrestamo[1].isEmpty=0;
    arrayPrestamo[1].codigoLibro=1;
    arrayPrestamo[1].codigoSocio=2;
    arrayPrestamo[1].dia=21;
    arrayPrestamo[1].mes=07;
    arrayPrestamo[1].agno=2017;

    arrayPrestamo[2].idUnico=3;
    arrayPrestamo[2].isEmpty=0;
    arrayPrestamo[2].codigoLibro=3;
    arrayPrestamo[2].codigoSocio=2;
    arrayPrestamo[2].dia=21;
    arrayPrestamo[2].mes=10;
    arrayPrestamo[2].agno=2018;

}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array prestamo Array of prestamo
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamo_Inicializar(Prestamo array[], int size)                                    //cambiar prestamo
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamo_buscarEmpty(Prestamo array[], int size, int* posicion)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamo_buscarID(Prestamo array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamo_buscarInt(Prestamo array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].codigoSocio==valorBuscado)                                                   //cambiar campo codigoSocio
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamo_buscarString(Prestamo array[], int size, char* valorBuscado, int* indice)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
/*            else if(strcmpi(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }*/
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int prestamo_alta(Prestamo array[], int size, int* contadorID,Socio arraySocio[], Libro arrayLibro[])                          //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    int devuelve;
    if (socio_todoVacio(arraySocio,size)==0 && libro_todoVacio(arrayLibro,size)==0)
    {
        printf("\nDebe ingresar al menos un socio y un libro\n");
    }
    else
    {
        if(array!=NULL && size>0 && contadorID!=NULL)
        {
            if(prestamo_buscarEmpty(array,size,&posicion)==-1)
            {
                printf("\nNo hay lugares vacios");
            }
            else
            {
                //fflush( stdin);
                if (utn_getUnsignedInt("\nIngrese el codigo del socio: ","\nError",1,sizeof(int),1,3,1,&array[posicion].codigoSocio)==0)
                {
                    if(socio_buscarID(arraySocio,size,array[posicion].codigoSocio,&devuelve)!=0)
                    {
                        printf("\nEl codigo de socio no existe\n");
                    }
                    else if (utn_getUnsignedInt("\nIngrese el codigo de Libro: ","\nError",1,sizeof(int),1,3,1,&array[posicion].codigoLibro)==0)
                        {
                            if(libro_buscarID(arrayLibro,size,array[posicion].codigoLibro,&devuelve)!=0)
                            {
                                printf("\nEl codigo de libro no existe\n");
                            }
                            else
                            {
                            if(utn_getFecha(&array[posicion].dia,&array[posicion].mes,&array[posicion].agno)==0)
                            {
                                (*contadorID)++;
                                array[posicion].idUnico=*contadorID;                                                       //campo ID
                                array[posicion].isEmpty=0;
                                printf("\n Posicion: %d\n ID: %d\n codigoSocio: %d\n codigo libro: %d\n fecha:%d/%d/%d\n",
                                       posicion, array[posicion].idUnico,array[posicion].codigoSocio,
                                       array[posicion].codigoLibro,array[posicion].dia,array[posicion].mes,array[posicion].agno);
                                retorno=0;
                            }
                                else
                                {
                                    printf("\n\Error al cargar la fechan");
                                }
                            }
                        }
                        else
                        {
                            printf("\nError al cargar los datos\n");
                        }
                }
                else
                {
                    printf("\nError al cargar los datos\n");
                }
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamo_baja(Prestamo array[], int sizeArray)                                      //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].codigoSocio=0;                                                               //cambiar campo codigoSocio
//            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
//            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
//            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamo_bajaValorRepetidoInt(Prestamo array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].codigoSocio=0;                                                               //cambiar campo codigoSocio
//                array[i].varFloat=0;                                                             //cambiar campo varFloat
//                strcpy(array[i].varString,"");                                                   //cambiar campo varString
//                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int prestamo_modificar(Prestamo array[], int sizeArray)                                //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(prestamo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n codigoSocio: %d\n",
                       posicion, array[posicion].idUnico,array[posicion].codigoSocio);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].codigoSocio);           //mensaje + cambiar campo codigoSocio
                        break;
                    case 'B':
//                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
//                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
//                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int prestamo_ordenarPorString(Prestamo array[],int size)                              //cambiar prestamo
{
    int retorno=-1;
    int i, j;
//    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
//    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
//            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].codigoSocio;                                //cambiar campo codigoSocio
//            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
//            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
/*            while ((j >= 0) && strcmpi(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].codigoSocio
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].codigoSocio=array[j].codigoSocio;                        //cambiar campo codigoSocio
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }*/
//            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].codigoSocio=bufferInt;                                                        //cambiar campo codigoSocio
//            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
//            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int prestamo_listar(Prestamo array[], int size)                      //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n codigoSocio: %d\n",
                       array[i].idUnico,array[i].codigoSocio);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

