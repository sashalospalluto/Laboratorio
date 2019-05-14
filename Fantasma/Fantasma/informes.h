#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


//int Informes_listarPorCriterio(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ, char* criterio);int Informes_listarCriterioContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
//int Informes_maxContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
void informe_totalGeneral(Prestamo array[], int size);
void informe_libroDeterminado(Socio arraySocio[], Prestamo arrayPrestamo[],Libro arrayLibro[], int size);
void informe_mostrar(Autor arrayAutor[], Libro arrayLibro[], Socio arraySocio[], Prestamo arrayPrestamo[], int size);



#endif // INFORMES_H_INCLUDED
