/*
 * Perros.h
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#ifndef PERROS_H_
#define PERROS_H_
#define TAM 21


struct
{
	int id;
	char nombre[TAM];
	char raza[TAM];
	int edad;
	int isEmpty;

}typedef Perro;

int menuPerrito();
void inicializarPerro(Perro* array, int tam);
int mostrarUnidadPerro(Perro unPerro);
void mostrarListaPerros(Perro* arrayPerros, int tam);
void cargarPerrosHarcode(Perro* arrayPerros, int* id);
int eliminarPerro(Perro* unidadPerro);
int findEmpty(Perro* arrayPerrito, int tam);
int altaPerrito(Perro* arrayPerrito, int tam, int* id);
int addPerrito(Perro* pUnidadPerrito, int len, int* id, char* name, char* race, int age);
int menuModificar(Perro* arrayPerritos, int len, int* indice, int* option);
int modificarPerrito(Perro* arrayPerritos, int len);
int indexByIdPerro(Perro* arrayPerritos, int tam, int id, int* indice);
int darDeBajaPerrito(Perro* arrayPerritos, int len);
int validIdPerro(Perro* arrayPerritos, int tam, int id);
int contadorPerros(Perro* arrayPerro, int len);
float promedioEdadPerros(Perro* arrayPerros, int len);



#endif /* PERROS_H_ */
