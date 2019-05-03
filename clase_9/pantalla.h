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
int pantalla_buscarPorId(Pantalla* pantalla, int cantidad,char* mensaje, char*mensajeError,int minimo,int maximo,int reintentos, int* devuelve);
int pantalla_buscarLibre(Pantalla* pantalla, int cantidad, int* devuelve);
int pantalla_Alta(Pantalla* pantalla, int cantidad, int* posLibre, int * pantalla_id);
void pantalla_cargarArray(Pantalla * pantalla,int posLibre, int tipoPantalla, char nombre[50],char direccion[200], float precio);
int pantalla_asignarPantalla(int* tipoPantalla);
void pantalla_generadorId(Pantalla* pantalla,int pos);
void pantalla_mostrar (Pantalla* pantalla, int cantidad);
void pantalla_modificar(Pantalla* pantalla, int posicion);
void pantalla_baja(Pantalla* pantalla, int posicion);
int pantalla_buscarPorId2(Pantalla* pantalla, int cantidad,int id, int* devuelve);


#endif // PANTALLA_H_INCLUDED
