#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
int idPantalla;
int isEmpty; //lleno=0 o vacio=1
char nombre[50];
char direccion [200];
float precio;
int tipo;

}Pantalla;

int pantalla_Inicializar(Pantalla* pantalla, int cantidad);
int pantalla_buscar(Pantalla* pantalla, int cantidad,char* mensaje, char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve);
int pantalla_buscarLibre(Pantalla* pantalla, int cantidad, int* devuelve);
int pantalla_Alta(Pantalla* pantalla, int cantidad, int posLibre);
int pantalla_asignarPantalla(Pantalla* pantalla, int posLibre);
void pantalla_generadorId(Pantalla* pantalla,int pos, int* id);
void pantalla_mostrar (Pantalla* pantalla, int cantidad);
void pantalla_modificar(Pantalla* pantalla, int cantidad, int posicion);

#endif // PANTALLA_H_INCLUDED
