/*
 * Inputs.h
 *
 *  Created on: 26 oct. 2021
 *      Author: sole
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumberFloat(float* pResultadoF, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getCharacter(char* pResultado, char mensaje[] , char* mensajeError, int reintentos);
int utn_nombreOapellido(char* string, char* pMensaje, char *pMensajeError, int tam, int reintentos);
int utn_telephoneNumber(char* string, char* mensaje, char* mensajeError, int tam, int reintentos);

#endif /* INPUTS_H_ */
