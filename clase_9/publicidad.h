#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
int idPublicidad;
int isEmpty; //lleno=0 o vacio=1
char cuit[20];
int dias;
char archivo[25];
int idPantalla;
}Publicidad;


int publicidad_Inicializar(Publicidad* publicidad, int cantidad);


#endif // PUBLICIDAD_H_INCLUDED
