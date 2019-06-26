#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux= this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this!=NULL && nodeIndex < this->size && nodeIndex>=0)
    {
         pNode = this->pFirstNode;
         for (i=0;i<nodeIndex;i++)
         {
            pNode =pNode->pNextNode;
         }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodeNew;
    Node* pNodeAux;

    if(this!= NULL)
    {
        pNodeNew = (Node*) malloc (sizeof(Node*));

        if(nodeIndex==0 && pNodeNew!=NULL)
        {
             pNodeNew->pNextNode=this->pFirstNode;
             pNodeNew->pElement=pElement;
             this->size++;
             this->pFirstNode=pNodeNew;

        }
        if(nodeIndex>0 && pNodeNew!=NULL)
        {
            pNodeAux=getNode(this,nodeIndex-1);
            pNodeNew->pNextNode=pNodeAux->pNextNode;
            pNodeAux->pNextNode=pNodeNew;
            pNodeNew->pElement=pElement;
            this->size++;
        }

        returnAux=0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int valor;

    if(this!=NULL)
    {
        valor=addNode(this,ll_len(this),pElement);
        if(valor==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this!=NULL && index>=0 && index<this->size)
    {
        pNode=getNode(this,index);
        returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this!=NULL && index>=0 && index<this->size)
    {
        pNode=getNode(this,index);
        pNode->pElement=pElement;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pAuxNode;

    if(this!=NULL && index>=0 && index<this->size)
    {
        if(index==0)
        {
            if(ll_len(this)!=0)
            {
                this->pFirstNode=getNode(this,index+1);
                pNode=getNode(this,index);
                free(pNode);
            }
            else
            {
                 this->pFirstNode=NULL;
            }
        }
        if(index>0)
        {
            pNode=getNode(this,index);
            free(pNode);
            pNode=getNode(this,index+1);
            pAuxNode=getNode(this,index-1);
            pAuxNode->pNextNode=pNode;
        }
        this->size--;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
        for(i=ll_len(this);i>-1;i--)
        {
            if(ll_remove(this, i-1)!=0)
            {
                break;
            }
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if (this!= NULL)
    {
        if (ll_clear(this)==0)
        {
            this=NULL;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    Node* auxNode;
    len=ll_len(this);
    if(this!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxNode=getNode(this,i);
            if(auxNode->pElement == pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        if (addNode(this,index,pElement)==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index<=ll_len(this))
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if (ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    //Node* pNode;
    //Node* pNode2;
    int contador=0;
    int i,j;

    if(this!=NULL && this2!=NULL)
    {
        if(ll_len(this)==ll_len(this2))
        {
            //pNode = this->pFirstNode;
            for (i=0; i<ll_len(this); i++)
            {
                //pNode =pNode->pNextNode;
                //pNode = this->pFirstNode;
                for (j=0; j<ll_len(this2); j++)
                {
                    // pNode2 =pNode2->pNextNode;
                    if(ll_get(this,i)==ll_get(this2,j))
                    {
                        contador++;
                    }
                }
            }
        }
        if(ll_len(this)==contador)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;

    if(this!=NULL && from>=0 && to>=0 && from<=ll_len(this) && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL && from<to)
        {
            for(i=from; i<=to ; i++)
            {
                pElement=ll_get(this,i);
                if(pElement!=NULL)
                {
                    ll_add(cloneArray,pElement);
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            cloneArray=ll_subList(this,0,this->size);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i,j;
    void* pElement;

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this)-1;i++)
        {
            for(j=i+1;j<ll_len(this);j++)
            {
                if(pFunc(ll_get(this,i),ll_get(this,j))==1 && order==1) //i>j y de menor a mayot
                {
                    pElement = ll_get(this, i);
                    ll_set(this,i,ll_get(this, j));
                    ll_set(this,j,pElement);
                }
                if(pFunc(ll_get(this,i),ll_get(this,j))==1 && order==0)
                {

                    pElement = ll_get(this, i);
                    ll_set(this,i,ll_get(this, j));
                    ll_set(this,j,pElement);
                }
            }
        }
    }
    return returnAux;
}

int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList *listaNueva =NULL;
    listaNueva=ll_newLinkedList();
    int i;
    int returnAux=-1;
    int devuelve;

    if(this!=NULL && listaNueva!=NULL)
    {
        for(i=0; i<ll_len(this);i++)
        {
            devuelve=pFunc(ll_get(this,i));
            if(devuelve==1)
            {
                ll_add(listaNueva,ll_get(this,i));
            }
        }
        returnAux=0;
    }
    return returnAux;
}

int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux=-1;
    int i;
    LinkedList* listaNueva;
    listaNueva=ll_newLinkedList();

    if(this!=NULL && listaNueva!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            if(pFunc(ll_get(this,i))==1)
            {
                ll_add(listaNueva,ll_get(this,i));
            }
        }
        ll_clear(this);
        for(i=0;i<ll_len(listaNueva);i++)
        {
            ll_add(this,ll_get(listaNueva,i));
        }
        returnAux=0;
    }
    return returnAux;
}
