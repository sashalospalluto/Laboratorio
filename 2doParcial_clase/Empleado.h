#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_registro
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_registro Registro;

void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
