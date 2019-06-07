#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){
    return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

    Employee* empleado = employee_new();
    if(empleado != NULL){
        employee_setId(empleado, *idStr);
        employee_setNombre(empleado, nombreStr);
        employee_setHorasTrabajadas(empleado, *horasTrabajadasStr);
        employee_setSueldo(empleado, *sueldoStr);
    }
    return empleado;

}

void employee_delete(){}


int employee_setId(Employee* this,int value){
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* value){
    int retorno = -1;
    if(this != NULL)
    {
        *value =this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* value){
    int retorno = -1;
    if(this != NULL ) ///agregar func de validacion de nombre
    {
        strcpy(this->nombre, value);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* value){
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(value, this->nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_setHorasTrabajadas(Employee* this,int value){
    int retorno = -1;
    if(this != NULL && value > 0 && value < 350)
    {
        this->horasTrabajadas = value;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* value){
    int retorno = -1;
    if(this != NULL )
    {
        *value = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int value){
    int retorno = -1;
    if(this != NULL && value > 0 )
    {
        this->sueldo = value;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* value){
    int retorno = -1;
    if(this != NULL )
    {
        *value = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


