#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>

int main()
{
    char seguir='s';
    int opcion;
    int r;
    int n;
    char nombre[51];
    char apellido [51];
    float salario;
    int sector;
    int id=0;
    int aux;
    int manera;

    Employee Eemplo[ELEMENTS];

    r=initEmployees(Eemplo,ELEMENTS);


    while (seguir=='s')
    {
        system("cls");
        printf("\t\tMENU");
        printf("\n\n1-Alta de nuevo usuario");
        printf("\n\n2-Modificar usuario");
        printf("\n\n3-Baja");
        printf("\n\n4-Informar");
        printf("\n\n5-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>5);

        switch (opcion)
        {
        case 1:

            r=buscarEspacio(Eemplo,ELEMENTS);

            if (r==0)
            {
                system("cls");

                printf("\t\tCARGA DE EMPLEADO");
                fflush(stdin);
                printf("\n\nIngrese nombre: ");
                gets(nombre);
                fflush(stdin);
                printf("\nIngrese apellido: ");
                gets(apellido);
                fflush(stdin);
                printf("\nIngrese salario: ");
                scanf("%f",&salario);
                printf("\nIngrese sector: ");
                scanf("%d",&sector);

                r=addEmployee(Eemplo,ELEMENTS,id,nombre,apellido,salario,sector);

                printf("\ncarga exitosa!\n\n");
            }
            else
            {
                printf("El numero de empleados cargados llego al maximo\n\n");
            }

            system("pause");

            break;

        case 2:

            system("cls");

            r=buscarEspacioOcupado(Eemplo,ELEMENTS);

            if (r==-1)
            {
                printf("Debe ingresar un empleado primero\n");
            }
            else
            {
                printf("ingrese ID del empleado que desea modificar");
                scanf("%d",&id);
                aux=findEmployeeById(Eemplo,ELEMENTS,id);
                if (aux==-1)
                {
                    printf("\nNo se encontro ningun empleado con ese ID\n");
                }
                else
                {
                    system("cls");
                    printf("\t\tOPCIONES DE MODIFICACION");
                    printf("\n\n1-Nombre");
                    printf("\n\n2-Apellido");
                    printf("\n\n3-Salario");
                    printf("\n\n4-Sector");

                    printf("\n\tingrese opcion: ");
                    scanf("\n%d",&opcion);

                    switch (opcion)
                    {
                    case 1:

                        fflush(stdin);
                        printf("\n\nIngrese el nombre nuevo: ");
                        gets(nombre);
                        strcpy(Eemplo[aux].name,nombre);
                        printf("\n\n\nNuevo nombre agregado correctamente");
                        break;
                    case 2:

                        fflush(stdin);
                        printf("\n\nIngrese el apellido nuevo: ");
                        gets(apellido);
                        strcpy(Eemplo[aux].lastName,apellido);
                        printf("\n\n\nNuevo apellido agregado correctamente");
                        break;

                    case 3:

                        printf("\n\nIngrese el nuevo salario: ");
                        scanf("%f",&salario);
                        Eemplo[aux].salary=salario;
                        printf("\n\n\nNuevo salario guardado correctamente");
                        break;

                    case 4:

                        printf("\n\nIngrese el nuevo sector: ");
                        scanf("%d",&sector);
                        Eemplo[aux].sector=sector;
                        printf("\n\n\nNuevo sector guardado correctamente");
                    }

                }

            }

            system("pause");
            break;

        case 3:

            system("cls");

            r=buscarEspacioOcupado(Eemplo,ELEMENTS);

            if (r==-1)
            {
                printf("Debe ingresar un empleado primero\n");
            }
            else
            {
                printf("\nIngrese el ID del empleado que desea eliminar: ");
                scanf("%d",&id);
                r=removeEmployee(Eemplo,ELEMENTS,id);
                if (r==-1)
                {
                    printf("\nEl id del empleado no existe");
                }
                else
                {
                    printf("\n El empleado ha sido eliminado correctamente");
                }
            }

            system("pause");
            break;

        case 4:

            system("cls");

            r=buscarEspacioOcupado(Eemplo,ELEMENTS);

            if (r==-1)
            {
                printf("Debe ingresar un empleado primero\n");
            }
            else
            {
                printf("\n\topciones de orden");
                printf("\n1-Ascendente");
                printf("\n0-Descendente");
                printf("\n\tIngrese opcion: ");
                scanf("%d",&manera);

                n=sortEmployees(Eemplo,ELEMENTS,manera);

                n=printEmployees(Eemplo,ELEMENTS);
            }

            system("pause");
            break;

        case 5:

            seguir='c';

            break;
        }
    }

}


