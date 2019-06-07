#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path,"rb");
    if(fp!=NULL)
    {
        return parser_EmployeeFromBinary(fp,pArrayListEmployee);
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int i,size;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    FILE* fp= fopen(path,"w+");
    if (fp!=NULL)
    {
        fprintf (fp, "id, nombre...");
        size=ll_len(pArrayListEmployee);

        for (i=0; i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);

            employee_getId(pArrayListEmployee,&auxId);
            employee_getNombre(pArrayListEmployee,auxNombre);
            employee_getHorasTrabajadas(pArrayListEmployee,&auxHoras);
            employee_getSueldo(pArrayListEmployee,&auxSueldo);
            fprintf(fp,"%d, %s,%d,%d\n",auxID,auxNombre,auxHoras,auxSueldo);
        }

        fclose(fp);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int i,size;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    FILE* fp= fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for (i=0; i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
        }
        fclose(fp);
    }
    return 1;
}

