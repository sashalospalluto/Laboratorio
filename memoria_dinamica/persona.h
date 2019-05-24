#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define QTY_NAME 20

typedef struct
{
    int id;
    char nombre[QTY_NAME];
    char apellido[QTY_NAME];
    int edad;
}Persona;

Persona* persona_new();
Persona* persona_newParametros(int id, int edad, char*nombre,char*apellido,Persona* this);
int persona_inicializarArray(Persona* personas[],int len);
int persona_buscarLibre(Persona* personas[],int len);

int persona_delete(Persona* this);

int persona_setId(Persona* this,int value);
int persona_setEdad(Persona* this,int value);
int persona_setApellido(Persona* this,char* value);
int persona_setNombre(Persona* this,char* value);

int persona_getId(Persona* this,int* value);
int persona_getEdad(Persona* this,int* value);
int persona_getApellido(Persona* this,char* value);
int persona_getNombre(Persona* this,char* value);


int persona_inicializarArray(Persona* personas[],int len);
void persona_inicializarId(int valor);


#endif // PERSONA_H_INCLUDED
