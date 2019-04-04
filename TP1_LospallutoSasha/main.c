#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numeroA;
    float numeroB;
    char seguir='s';
    int opcion;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialA;
    int factorialB;
    int resultadoDivision; //resultado de la funcion "funcionDividir"



    int rta;
        while (seguir=='s')
    {
        system("cls");
        printf("\t\tMENU");
        printf("\n\n1-Ingresar 1er operando (A=%.2f)",numeroA);
        printf("\n\n2-Ingresar 2do operando (B=%.2f)",numeroB);
        printf("\n\n3-Calcular todas las operaciones");
        printf("\n\n4-Informar resultados");
        printf("\n\n5-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }while (opcion<1 || opcion>5);

      switch (opcion)

                {
                case 1:
                    system("cls");
                    printf("Ingrese el primer operando: ");
                    scanf("%f",&numeroA);
                    break;
                case 2:
                    system("cls");
                    printf("Ingrese el segundo operando: ");
                    scanf("%f",&numeroB);
                    break;
                case 3:
                    funcionSuma(numeroA, numeroB,&suma);
                    funcionResta(numeroA, numeroB,&resta);
                    funcionMultiplicar(numeroA, numeroB, &multiplicacion);
                    resultadoDivision=funcionDividir(numeroA, numeroB,&division);
                    funcionFactorial(&numeroA,&factorialA);
                    funcionFactorial(&numeroB, &factorialB);
                    printf("\n\nProceso realizado\n");
                    system("pause");
                    break;
                case 4:
                    //SUMA
                    printf("\nLa suma de %.2f + %.2f es: %.2f\n\n", numeroA, numeroB, suma);
                    //RESTA
                    printf("La resta de %.2f - %.2f es: %.2f\n\n", numeroA,numeroB, resta);
                    //MULTIPLICACION
                    printf("La multiplicacion de %.2f * %.2f es: %.2f\n\n", numeroA,numeroB, multiplicacion);
                    //DIVISION
                    if (resultadoDivision==0)
                    {
                        printf("La division de %.2f / %.2f es: %.2f\n\n", numeroA,numeroB, division);
                    }
                    else
                    {
                        printf("No se puede dividir por cero\n\n");
                    }
                    //FACTORIAL
                    funcionMostrarFactorial(numeroA,factorialA);
                    //funcionMostrarFactorial(numeroB,factorialB);


                    system("pause");
                    break;
                case 5:
                    seguir='f';
                    break;
                }
    }

}
