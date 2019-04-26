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
int publicidad_buscarLibre(Publicidad* publicidad, int cantidad, int* devuelve);
int publicidad_Alta(Publicidad* publicidad, int cantidad, int posLibre);
int publicidad_buscarPorId(Publicidad* publicidad, int cantidad,char* mensaje,char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve);



#endif // PUBLICIDAD_H_INCLUDED
