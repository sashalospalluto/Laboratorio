#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int resultado=-1;

    for (int i=0;i<len;i++)
    {
        list[i].isEmpty=0;
        printf("%d\n\n", list[i].isEmpty);
        resultado=0;
    }

 return resultado;
}

int buscarEspacio (Employee* list, int len)
{
    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            return 0;
        }
    }
    return -1;
}

int buscarEspacioOcupado (Employee* list, int len)
{
    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            return 0;
        }
    }
    return -1;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].id=i+1;
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=1;
            printf("\n\nsu ID es: %d y posicion %d",list[i].id,i);
            return 0;

        }
    }
    return -1;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index=-1;
    for (int i=0;i<len;i++)
    {
        if (list[i].id==id && list[i].isEmpty==1)
        {
            index=i;
            return index;
        }
    }
 return index;
}


int removeEmployee(Employee* list, int len, int id)
{
    int r;

    r=findEmployeeById(list,len,id);

    if (r==-1)
    {
        return r;
    }
    else
    {
        list[r].isEmpty=0;
        return r;
    }

}

int sortEmployees(Employee* list, int len, int order)
{
    Employee listAux;

    int resultado=0;

    if (order==1)
    {
        for (int i=0; i<len-1; i++)
        {
            for (int j=i+1; j<len; j++)
            {
                if (strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    if(list[i].isEmpty == 1) //aca verifico cual es el apellido de forma ascendente
                    {
                        listAux=list[i];
                        list[i]=list[j];
                        list[j]=listAux;
                        resultado=1;

                        if (strcmp(list[i].lastName,list[j].lastName)<=0) //verifico si son iguales
                        {
                            if (list[i].sector<list[j].sector) //verifico los sectores
                            {
                                listAux=list[i];
                                list[i]=list[j];
                                list[j]=listAux;
                                resultado=1;
                            }
                        }

                    }

                }
            }
        }
    }
    if (order==0)
    {
        for (int i=0; i<len-1; i++)
        {
            for (int j=i+1; j<len; j++)
            {
                if (strcmp(list[i].lastName,list[j].lastName)<0)
                {
                    if(list[i].isEmpty == 1) //aca verifico cual es el apellido de forma descendente
                    {
                        listAux=list[j];
                        list[j]=list[i];
                        list[i]=listAux;
                        resultado=1;

                        if (strcmp(list[i].lastName,list[j].lastName)>=0) //verifico si son iguales
                        {
                            if (list[i].sector>list[j].sector) //verifico los sectores
                            {
                                listAux=list[i];
                                list[i]=list[j];
                                list[j]=listAux;
                                resultado=1;
                            }
                        }

                    }

                }
            }
        }
    }


    return resultado;

}

int printEmployees(Employee* list, int length)
{
    printf("   Id    Nombre    Apellido     Salario     Sector\n\n");

    for(int i=0; i < length; i++)
    {

        if( list[i].isEmpty == 1)
        {
            printf("%4d %10s %10s     %6.2f %10d %10d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector, i);
        }
    }

    return 0;
}


