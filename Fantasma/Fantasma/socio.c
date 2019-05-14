#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socio.h" //cambiar por nombre entidad

void socio_hardcodeo(Socio arraySocio[])
{
    strcpy(arraySocio[0].nombre,"Sasha");
    strcpy(arraySocio[0].apellido,"Lospalluto");
    arraySocio[0].sexo='f';
    arraySocio[0].telefono=1166262107;
    strcpy(arraySocio[0].email,"sasha@hotmail.com");
    arraySocio[0].dia=21;
    arraySocio[0].mes=07;
    arraySocio[0].agno=1997;
    arraySocio[0].isEmpty=0;
    arraySocio[0].idUnico=1;

    strcpy(arraySocio[1].nombre,"Sasha");//Juan Manuel
    strcpy(arraySocio[1].apellido,"Chico");
    arraySocio[1].sexo='m';
    arraySocio[1].telefono=1168940444;
    strcpy(arraySocio[1].email,"juan@hotmail.com");
    arraySocio[1].dia=25;
    arraySocio[1].mes=8;
    arraySocio[1].agno=1997;
    arraySocio[1].isEmpty=0;
    arraySocio[1].idUnico=2;

    strcpy(arraySocio[2].nombre,"Sandra Angelica");//Sandra Angelica
    strcpy(arraySocio[2].apellido,"Alvez");
    arraySocio[2].sexo='f';
    arraySocio[2].telefono=1165808344;
    strcpy(arraySocio[2].email,"sandra@hotmail.com");
    arraySocio[2].dia=26;
    arraySocio[2].mes=01;
    arraySocio[2].agno=1972;
    arraySocio[2].isEmpty=0;
    arraySocio[2].idUnico=3;

    strcpy(arraySocio[3].nombre,"Sasha");//Sandra Angelica
    strcpy(arraySocio[3].apellido,"Alvez");
    arraySocio[3].sexo='f';
    arraySocio[3].telefono=1165808344;
    strcpy(arraySocio[3].email,"sandra@hotmail.com");
    arraySocio[3].dia=26;
    arraySocio[3].mes=01;
    arraySocio[3].agno=1972;
    arraySocio[3].isEmpty=0;
    arraySocio[3].idUnico=4;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socio Array of socio
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socio_Inicializar(Socio array[], int size)                                    //cambiar socio
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socio_buscarEmpty(Socio array[], int size, int* posicion)                    //cambiar socio
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion)                    //cambiar socio
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
          /*  else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
            */
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice)                    //cambiar socio
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socio_alta(Socio array[], int size, int* contadorID)                          //cambiar socio
{
    int retorno=-1;
    int posicion;
    if (socio_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun socio\n");
    }
    else
    {
        if(array!=NULL && size>0 && contadorID!=NULL)
        {
            if(socio_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socio
            {
                printf("\nNo hay lugares vacios");
            }
            else
            {
                if(utn_getFloat("\nTelefono: ","\nError",1,13,0,sizeof(float),1,&array[posicion].telefono)==0 &&            //mensaje + cambiar campo telefono
                   utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)==0 &&                      //mensaje + cambiar campo nombre
                   utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)==0)
                   {
                       utn_getChar("\nIngrese sexo (F o M): ","\nError",1,sizeof(char),3,&array[posicion].sexo);
                       if (array[posicion].sexo=='f' || array[posicion].sexo=='F' || array[posicion].sexo=='m' || array[posicion].sexo=='M')
                       {
                           if (utn_getEmail("\ningrese email: ", "\nerror\n",1,TEXT_SIZE,3,array[posicion].email)==0 &&
                                utn_getFecha(&array[posicion].dia,&array[posicion].mes,&array[posicion].agno)==0)
                                {
                                    (*contadorID)++;
                                    array[posicion].idUnico=*contadorID;                                                       //campo ID
                                    array[posicion].isEmpty=0;
                                    printf("\n Posicion: %d\n ID: %d\n telefono: %f\n nombre: %s\n apellido: %s \n Sexo: %c\n Email: %s\n Fecha: %d/%d/%d\n",
                                    posicion, array[posicion].idUnico,array[posicion].telefono,array[posicion].nombre,array[posicion].apellido,array[posicion].sexo, array[posicion].email,array[posicion].dia,array[posicion].mes, array[posicion].agno);
                                }
                       }
                       else
                       {
                           printf("\nError al poner el sexo\n");
                       }
                   }
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_baja(Socio array[], int sizeArray)                                      //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;
    if (socio_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun socio\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
            if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                printf("\nBORRADO CON EXITO\n");
                array[posicion].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socio Array de socio
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
//                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].telefono=0;                                                             //cambiar campo telefono
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socio_modificar(Socio array[], int sizeArray)                                //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;

    //auxiliares
    Socio auxArray;
    if (socio_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun socio\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nIngrese el codigo del socio: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
            if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                do
                {       //copiar printf de alta
                    printf("\n 1-nombre: %s\n 2-apellido: %s \n3-sexo: %c \n4-Telefono: %2.f \n5-email: %s\n6-SALIR\n",
                           array[posicion].nombre,array[posicion].apellido, array[posicion].sexo,array[posicion].telefono,array[posicion].email);
                    utn_getUnsignedInt("\nIngrese opcion: ","error",1,7,1,6,3,&opcion);
                    switch(opcion)
                    {
                        case 1:
                            if (utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,auxArray.nombre)==0)
                            {
                                strcpy(array[posicion].nombre,auxArray.nombre);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 2:
                            if(utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,auxArray.apellido)==0)
                            {
                                strcpy(array[posicion].apellido,auxArray.apellido);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 3:
                            utn_getChar("\nIngrese sexo (F o M): ","\nError",1,sizeof(char),3,&auxArray.sexo);
                            if (auxArray.sexo=='f' || auxArray.sexo=='F' || auxArray.sexo=='m' || auxArray.sexo=='M')
                            {
                                array[posicion].sexo=auxArray.sexo;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 4:
                            if(utn_getFloat("\nTelefono: ","\nError",1,13,0,sizeof(float),1,&auxArray.telefono)==0)
                            {
                                array[posicion].telefono=auxArray.telefono;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 5:
                            if(utn_getEmail("\ningrese email: ", "\nerror\n",1,TEXT_SIZE,3,auxArray.email)==0)
                            {
                                strcpy(array[posicion].email,auxArray.email);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 6:
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!=6);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

void socio_ordenarPorString(Socio array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Socio auxiliar;
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
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socio_listar(Socio array[], int size)                      //cambiar socio
{
    int retorno=-1;
    int i;
    if (socio_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun socio\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            socio_ordenarPorString(array,size);
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                    continue;
                else
                    printf("\n ID: %d\n telefono: %2.f\n nombre: %s\n apellido: %s \n Sexo: %c \n email: %s, \n fecha: %d/%d/%d\n",
                           array[i].idUnico,array[i].telefono,array[i].nombre,array[i].apellido, array[i].sexo, array[i].email,array[i].dia,array[i].mes,array[i].agno);      //cambiar todos
            }
            retorno=0;
        }
    }
    return retorno;
}

int socio_todoVacio(Socio array[], int size)
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
