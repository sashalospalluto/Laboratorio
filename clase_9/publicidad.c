#include <stdio.h>
#include <stdlib.h>
#include "publicidad.h"
#include "pantalla.h"
#include "empleado.h"
#include "funciones_string.h"
#include <string.h>
#include <ctype.h>
#define CANTPANTALLAS 100
#define CANCONTRATACIONES 1000

int publicidad_Inicializar(Publicidad* publicidad, int cantidad)
{
    int ret=1;
    for (int i=0; i<cantidad;i++)
    {
        publicidad[i].isEmpty=1;
        ret=0;
    }

    return ret;
}
