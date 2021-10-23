/*
 * Biblioteca2021.h
 *
 *  Created on: 12 sep. 2021
 *      Author: sole
 */

#ifndef BIBLIOTECAUTN2021_H_
#define BIBLIOTECAUTN2021_H_

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumberFloat(float* pResultadoF, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getCharacter(char* pResultado, char mensaje[] , char* mensajeError, int reintentos);
int utn_nombreOapellido(char* string, char* pMensaje, char *pMensajeError, int tam, int reintentos);
int utn_cargarArrayNumeros(int arrayNumeros[], int tam, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_ordenarArrayCreciente(int* array, int tam);
int utn_ordenarArrayDecreciente(int* array, int tam);
int utn_mostrarNumeros(int* array, char* mensaje, int tam);
int inicializacionArray(int array[], int tam);
int utn_promedio(int numerador, int denominador, float* pResultadoF);
int utn_telephoneNumber(char* string, char* mensaje, char* mensajeError, int tam, int reintentos);



#endif /* BIBLIOTECAUTN2021_H_ */
