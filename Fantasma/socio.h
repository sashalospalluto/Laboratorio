#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    char sexo;
    float telefono;
    char email[TEXT_SIZE];
    int dia;
    int mes;
    int agno;
}Socio;


#endif // SOCIO_H_INCLUDED
int socio_todoVacio(Socio array[], int size);
void socio_hardcodeo(Socio arraySocio[]);
int socio_Inicializar(Socio array[], int size);                                    //cambiar socio
int socio_buscarEmpty(Socio array[], int size, int* posicion);                    //cambiar socio
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice);                    //cambiar socio
int socio_alta(Socio array[], int size, int* contadorID);                          //cambiar socio
int socio_baja(Socio array[], int sizeArray);                                      //cambiar socio
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado);
int socio_modificar(Socio array[], int sizeArray);                                //cambiar socio
void socio_ordenarPorString(Socio array[],int size);                              //cambiar socio
int socio_listar(Socio array[], int size);                      //cambiar socio


