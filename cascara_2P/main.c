#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"

int main()
{
    LinkedList* registro;
    registro= ll_newLinkedList();
    if(registro!=NULL)
    {
        controller_loadFromText("data.csv",registro);
        controller_printAllRegistros(registro);
        controller_saveAsText("informe.txt",registro);
    }

    return 0;
}
