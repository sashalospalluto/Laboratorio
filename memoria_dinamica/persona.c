#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

int persona_setId(Persona* this,int value)
{
    int ret=-1;
    if(this!=NULL && value>=0)
    {
        this->id=value;
        ret=0;
    }
    return ret;
}

int persona_setEdad(Persona* this,int value)
{
    int ret=-1;
    if(this!=NULL && value>=0)
    {
        this->edad=value;
        ret=0;
    }
    return ret;
}

int persona_setNombre(Persona* this,char* value)
{
    int ret=-1;
    if(this!=NULL && value>=0)
    {
        strcpy(this->nombre,value);
        ret=0;
    }
    return ret;
}

int persona_setApellido(Persona* this,char* value)
{
    int ret=-1;
    if(this!=NULL && value>=0)
    {
        strcpy(this->apellido,value);
        ret=0;
    }
    return ret;
}

int persona_getId(Persona* this,int* value)
{
    int ret=-1;
    if(this!=NULL && value!=NULL)
    {
       *value=this->id;
        ret=0;
    }
    return ret;
}

int persona_getEdad(Persona* this,int* value)
{
    int ret=-1;
    if(this!=NULL && value!=NULL)
    {
       *value=this->edad;
        ret=0;
    }
    return ret;
}

int persona_getNombre(Persona* this,char* value)
{
    int ret=-1;
    if(this!=NULL && value!=NULL)
    {
        strcpy(value,this->nombre);
        ret=0;
    }
    return ret;
}

int persona_getApellido(Persona* this,char* value)
{
    int ret=-1;
    if(this!=NULL && value!=NULL)
    {
        strcpy(value,this->apellido);
        ret=0;
    }
    return ret;
}

Persona* persona_newParametros(int id, int edad,char*nombre,char*apellido,Persona* this)
{
    Persona* auxPersona;
    auxPersona=persona_new();
    if(auxPersona!=NULL)
    {
        persona_setId(auxPersona,id);
        persona_setEdad(auxPersona,edad);
        persona_setNombre(auxPersona,nombre);
        persona_setApellido(auxPersona,apellido);
    }
    return auxPersona;
}

static int contador=0;

static int generar(void)
{
    contador++;
    return contador;
}

void persona_inicializarId(int valor)
{
    contador=valor;
}

int persona_inicializarArray(Persona* personas[],int len)
{
    int i;
    int ret=-1;
    if(personas!=NULL)
    {
        ret=0;
        for(i=0; i<len;i++)
        {
            personas[i]=NULL;
        }
    }
    return ret;
}
