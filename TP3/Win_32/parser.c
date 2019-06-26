#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/// Parsea los datos de los empleados desde el archivo data.csv (modo texto).
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int retorno =0;
    Employee* pEmpleado;
    int aux;
    int id;
    char nombre [128];
    int horasTrabajo;
    int sueldo;

    if(pFile != NULL){
        aux= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", nombre, nombre, nombre, nombre);
        do{
            aux= fscanf(pFile, "%d,%[^,],%d,%d \n", &id, nombre, &horasTrabajo, &sueldo);
            if(aux ==4){
                pEmpleado = employee_newParametros(&id, nombre, &horasTrabajo,&sueldo);
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = 1;
            }
        }while(!feof(pFile));
    }

    return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int retorno =0;
    Employee empleado;
    Employee* pEmpleado;
    int aux;


   if(pFile != NULL){
        while(!feof(pFile)){

            aux = fread(&empleado,sizeof(Employee),1,pFile);
            if(aux==1){
                if(feof(pFile)){
                    break;
                }
                else{
                    pEmpleado = employee_newParametros(&empleado.id, empleado.nombre, &empleado.horasTrabajadas,&empleado.sueldo);
                    ll_add(pArrayListEmployee, pEmpleado);
                }
            }
        }
    }

    return retorno;
}
