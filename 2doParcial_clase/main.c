#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "LinkedList.h"
#include "Parser.h"

int generarArchivo(char* fileName,LinkedList* listaRegistros);

int main()
{
    LinkedList* listaRegistros;
    listaRegistros=ll_newLinkedList();

    controller_loadFromText("data.csv",listaRegistros);
    controller_ListRegistro(listaRegistros);

    printf("cantidad total de registros: ");

    return 0;
}
