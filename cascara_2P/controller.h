#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
int controller_loadFromText(char* path, LinkedList* this);
int controller_saveAsText(char* path, LinkedList* this);

int controller_printRegistro(LinkedList* this, int index);
int controller_printAllRegistros(LinkedList* this);
#endif // CONTROLLER_H_INCLUDED
