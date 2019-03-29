#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int num;
    int rta;

    rta=funciones_getNumber(&num,10,1,"Ingrese numero: ","Algo paso en la funcion",5,"cantidad de intentos: ");

    funciones_validoResultado(rta);


    return 0;
}
