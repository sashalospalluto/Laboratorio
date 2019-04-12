#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char numero[10];
    getString(numero,"\nIngrese string: ","\nError",1,10,10);
    printf("\n %s",numero);
    return 0;
}
