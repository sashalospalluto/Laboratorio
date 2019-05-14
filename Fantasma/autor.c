#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h" //cambiar por nombre entidad

void autor_hardcodeo(Autor arrayAutor[])
{
    strcpy(arrayAutor[0].apellido,"Cortazar");
    strcpy(arrayAutor[0].nombre,"Julio");
    arrayAutor[0].idUnico=1;
    arrayAutor[0].isEmpty=0;

    strcpy(arrayAutor[1].apellido,"Sabato");
    strcpy(arrayAutor[1].nombre,"Ernesto");
    arrayAutor[1].idUnico=2;
    arrayAutor[1].isEmpty=0;

    strcpy(arrayAutor[2].apellido,"Borges");
    strcpy(arrayAutor[2].nombre,"Jorge Luis");
    arrayAutor[2].idUnico=3;
    arrayAutor[2].isEmpty=0;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autor Array of autor
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autor_Inicializar(Autor array[], int size)                                    //cambiar autor
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autor_buscarEmpty(Autor array[], int size, int* posicion)                    //cambiar autor
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarID(Autor array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarInt(Autor array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            /*else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }*/
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarString(Autor array[], int size, char* valorBuscado, int* indice)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmpi(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autor_alta(Autor array[], int size, int* contadorID)                          //cambiar autor
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(autor_buscarEmpty(array,size,&posicion)==-1)                          //cambiar autor
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getName("\nIngrese el nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)==0)
            {
                if (utn_getName("\nIngrese el apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)==0) //mensaje + cambiar campo apellido
                {
                    (*contadorID)++;
                    array[posicion].idUnico=*contadorID;                                                       //campo ID
                    array[posicion].isEmpty=0;
                    printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
                    posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido);
                    retorno=0;
                }
                else
                {
                    printf("\nError al cargar el apellido\n");
                }
            }
            else
            {
                printf("\nError al cargar el nombre\n");
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_baja(Autor array[], int sizeArray)                                      //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if (autor_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun autor\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
            if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                utn_getUnsignedInt("\n1-SI\n2-NO\n\tSeguro que desea borrar?:","No es una opcion valida",1,sizeof(int),1,2,3,&opcion);
                if(opcion==1)
                {
                    array[posicion].isEmpty=1;
                    retorno=0;
                    printf("\nBaja realizada con exito\n");
                }

            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array autor Array de autor
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_bajaValorRepetidoInt(Autor array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autor_modificar(Autor array[], int sizeArray)                                //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if (autor_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun autor\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
            if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                do
                {       //copiar printf de alta
                    printf("\n 1-nombre: %s\n 2-apellido: %s \n 3-Salir",
                           array[posicion].nombre,array[posicion].apellido);
                    utn_getUnsignedInt("\nIngrese opcion: ","error",1,3,1,3,3,&opcion);
                    switch(opcion)
                    {
                        case 1:
                            utn_getName("\nIngrese nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                            break;
                        case 2:
                            utn_getName("\nIngrese apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
void autor_ordenarPorString(Autor array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Autor auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if ((strcmpi(array[j].apellido,array[i].apellido)<0))
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;
                    }else if((strcmpi(array[j].apellido,array[i].apellido)==0) && (strcmpi(array[j].nombre,array[i].nombre)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autor_listar(Autor array[], int size)                      //cambiar autor
{
    int retorno=-1;
    int i;
    if (autor_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun autor\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            autor_ordenarPorString(array,size);
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else
                {
                    printf("\n ID: %d\n nombre: %s\n apellido: %s",
                    array[i].idUnico,array[i].nombre,array[i].apellido);
                }

            }
            retorno=0;
        }
    }
    return retorno;
}

int autor_todoVacio(Autor array[], int size)
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
