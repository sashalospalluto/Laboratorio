#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libros.h" //cambiar por nombre entidad
#include "autor.h"

void libro_hardcodeo(Libro arrayLibro[])
{
    strcpy(arrayLibro[0].titulo,"Inquisiciones");
    arrayLibro[0].codigoAutor=1;
    arrayLibro[0].isEmpty=0;
    arrayLibro[0].idUnico=1;

    strcpy(arrayLibro[1].titulo,"Rayuela");
    arrayLibro[1].codigoAutor=2;
    arrayLibro[1].isEmpty=0;
    arrayLibro[1].idUnico=2;

    strcpy(arrayLibro[2].titulo,"Tunel");
    arrayLibro[2].codigoAutor=1;
    arrayLibro[2].isEmpty=0;
    arrayLibro[2].idUnico=3;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libro Array of libro
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libro_Inicializar(Libro array[], int size)                                    //cambiar libro
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libro_buscarEmpty(Libro array[], int size, int* posicion)                    //cambiar libro
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].codigoAutor==valorBuscado)                                                   //cambiar campo codigoAutor
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmpi(array[i].titulo,valorBuscado)==0)                                        //cambiar campo titulo
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libro_alta(Libro array[], int size, int* contadorID, Autor arrayAutor[])                          //cambiar libro
{
    int retorno=-1;
    int posicion;
    int pos;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libro_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libro
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getUnsignedInt("\nIngrese codigo de autor: ","\nError",1,sizeof(int),1,10,3,&array[posicion].codigoAutor)==-1 ||
               autor_buscarID(arrayAutor,size,array[posicion].codigoAutor,&pos)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID\n");                                                          //cambiar si no se busca por ID
            }
            else if (utn_getTexto("Ingrese el titulo del libro: ","\nError",1,TEXT_SIZE,3,array[posicion].titulo)==0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;
                printf("\n Posicion: %d\n ID: %d\n codigoAutor: %d\n titulo: %s\n",
                posicion, array[posicion].idUnico,array[posicion].codigoAutor,array[posicion].titulo);
                retorno=0;
            }
            else
            {
                printf("\nError al cargar el titulo del libro\n");
            }


        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_baja(Libro array[], int sizeArray)                                      //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;
    if (libro_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun libro\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
            if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                array[posicion].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libro Array de libro
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].codigoAutor=0;                                                               //cambiar campo codigoAutor
//                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].titulo,"");                                                   //cambiar campo titulo
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libro_modificar(Libro array[], int sizeArray, Autor arrayAutor[])                                //cambiar libro
{
    int retorno=-1;
    int posicion;
    int pos;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    int auxCodigoAutor;
    if (libro_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun libro\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
            if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                do
                {       //copiar printf de alta
                    printf("\n 1-CodigoAutor: %d\n 2-titulo: %s\n 3-salir\n",
                           array[posicion].codigoAutor,array[posicion].titulo);
                    utn_getUnsignedInt("\nModificar: ","\nError",1,3,1,3,10,&opcion);
                    //utn_getChar("\nModificar: A B S(salir)","\nError",'A','Z',1,&opcion);
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getUnsignedInt("\nIngrese codigo de autor: ","\nError",1,sizeof(int),1,10,3,&auxCodigoAutor)==-1 ||
                               autor_buscarID(arrayAutor,sizeArray,auxCodigoAutor,&pos)==-1)                                   //cambiar si no se busca por ID
                            {
                                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
                            }
                            else
                            {
                                array[posicion].codigoAutor=auxCodigoAutor;
                            }
                            break;
                        case 2:
                            utn_getName("\nIngrese el titulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);            //mensaje + cambiar campo varFloat
                            break;
                        case 3:
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!=3);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libro_ordenarPorString(Libro array[],int size)                              //cambiar libro
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo titulo
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
//    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].titulo);                      //cambiar campo titulo
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].codigoAutor;                                //cambiar campo codigoAutor


            j = i - 1;
            while ((j >= 0) && strcmpi(bufferString,array[j].titulo)<0)         //cambiar campo titulo                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].codigoAutor
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].titulo,array[j].titulo);          //cambiar campo titulo
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].codigoAutor=array[j].codigoAutor;                        //cambiar campo codigoAutor
//                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
//                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].titulo,bufferString);                     //cambiar campo titulo
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].codigoAutor=bufferInt;                                                        //cambiar campo codigoAutor
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libro_listar(Libro array[], int size)                      //cambiar libro
{
    int retorno=-1;
    int i;
    if (libro_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun libro\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            libro_ordenarPorString(array,size);
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                    continue;
                else
                    printf("\n ID: %d\n codigoAutor: %d\n titulo: %s\n",
                           array[i].idUnico,array[i].codigoAutor,array[i].titulo);      //cambiar todos
            }
            retorno=0;
        }
    }
    return retorno;
}

int libro_todoVacio(Libro array[], int size)
{
    int ret=-1;
    int contador=0;
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==1)
        {
            contador++;
            if(contador==size)
            {
               ret=0;
            }
        }
    }
    return ret;
}
