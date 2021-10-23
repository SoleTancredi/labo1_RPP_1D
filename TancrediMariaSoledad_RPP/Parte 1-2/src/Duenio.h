/*
 * Duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: sole
 */

#ifndef DUENIO_H_
#define DUENIO_H_
#define TAM_D 41
#define TAM_TEL_DUENIO 25


struct
{
	int id;
	char nombre[TAM_D];
	char apellido[TAM_D];
	char telefono[TAM_TEL_DUENIO];
	int isEmpty;

}typedef Duenio;

int menuDuenio();
void inicializarDuenio(Duenio* array, int tam);
void cargarDuenioHarcode(Duenio* arrayDuenio, int* id);
int mostrarUnidadDuenio(Duenio unDuenio);
void mostrarListaDuenios(Duenio* arrayDuenio, int tam);
int eliminarDuenio(Duenio* unidadDuenio);
int findEmptyDuenio(Duenio* arrayDuenio, int tam);
int indexByIdDuenio(Duenio* arrayDuenio, int tam, int id, int* indice);
int addDuenio(Duenio* pUnidadDuenio,int tam, int* id, char* name, char* apellido, char* telefono);
int altaDuenio(Duenio* arrayDuenio, int tam, int* id);
int menuModificarDuenio(Duenio* arrayDuenio, int len, int* indice, int* option);
int modificarDuenio(Duenio* arrayDuenio, int len);
int darDeBajaDuenio(Duenio* arrayDuenio, int len);
int validIdDuenio(Duenio* arrayDuenio, int tam, int id);

#endif /* DUENIO_H_ */
