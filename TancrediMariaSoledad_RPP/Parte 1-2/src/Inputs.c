/*
 * Inputs.c
 *
 *  Created on: 26 oct. 2021
 *      Author: sole
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int esLetra(char* cadena);
static int esFloat(char* cadena);
static int getFloat(float* pResultadoF);
static int ArrayIsEmpty(char* array);
static int esCifra(char* cadena);

/**
 * @fn int ArrayIsEmpty(char*)
 * @brief tiene en cuenta el posible caso de que el usuario ingrese enter o espacio nada mas
 *
 * @param array
 * @return retorna el resultado 0 si esta todo ok, -1 si el array esta vacio
 */


static int ArrayIsEmpty(char* array)
{
	int resultado=-1;
	if(array!= NULL && strlen(array)>1)
	{
		for(int i = 0; i < sizeof(array); i++)
		{
			if(array[i] == ' ')
			{
				break;
			}
			else
			{
				resultado = 0;
			}
		}
	}
	return resultado;
}
/**
 * @fn int myGets(char*, int)
 * @brief toma la medida del string con la funcion strlen y le resta un lugar para posicionarse en el \n
 * donde lo pisa y alli escribe un "\0".
 *
 * @param cadena
 * @param longitud
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferCadena[4016];

	if(cadena != NULL)
	{
		__fpurge(stdin);
		fgets(bufferCadena,longitud, stdin);

		if(ArrayIsEmpty(bufferCadena)==0)
		{
			bufferCadena[strlen(bufferCadena)-1]= '\0' ;
			strcpy(cadena, bufferCadena);
			retorno = 0;
		}
	}
	 return retorno;
}

/**
 * @fn int esNumerica(char*)
 * @brief se encarga de recorrer el array hasta el \0 y verifica posicion a posicion
 * que lo que contenga sea un numero. En caso de que en la posicion 0 halla un signo '-' se respeta ya que
 * seria un numero negativo.
 *
 * @param cadena
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */

static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for(; cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}
/**
 * @fn int getInt(int*)
 * @brief mediante la funcion atoi se encarga de convertir la cadena a numeros enteros.
 *
 * @param pResultado
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */
static int getInt(int* pResultado)
{
	int retorno=-1;
	char bufferInt[4096];

	if(myGets(bufferInt, sizeof(bufferInt)) == 0 && esNumerica(bufferInt))
	{
		retorno=0;
		*pResultado = atoi(bufferInt);
	}
	return retorno;
}

static int esFloat(char* cadena)
{
	int retorno = 1;
	int i = 0;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0)
	{
	     for(  ; cadena[i] != '\0'; i++)
	     {
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}

			if(cadena[i] == '.')
			{
				 contadorPuntos++;
			}

			if((cadena[i] > '9'||cadena[i] < '0') && contadorPuntos > 1)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getFloat(float* pResultadoF)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultadoF != NULL && myGets(buffer,4096) == 0 && esFloat(buffer) == 1)
	{
		 retorno = 0;
	    *pResultadoF = atof(buffer);
	}
	return retorno;
}

/**
 * @fn int esLetra(char*)
 * @brief recorre el array verificado que en cada una de sus posiciones halla un caracter, guiandose por el codigo ASCII.
 *
 * @param cadena
 * @return-1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */

static int esLetra(char* cadena)
{
	int retorno = -1;
	int i = 0;

	for(; cadena[i] != '\0'; i++)
	{
		if((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}

static int esCifra(char* cadena)
{
	int retorno = -1;
	int i = 0;

	for(; cadena[i] != '\0'; i++)
	{
		if(cadena[i] >= 48 && cadena[i] <= 57)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}

/**
 * @fn int utn_getNumber(int*, char*, char*, int, int, int)
 * @brief pide un numero entero. Valida lo ingresado utilizando las funciones estaticas, mygets, esNumerica, getInt
 * posee maximos y minimo, y cantidad de reintentos en caso de que el usuario se confunda en el ingreso.
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	 }
	return retorno;
}

/**
 * @fn int utn_getNumberFloat(float*, char*, char*, float, float, int)
 * @brief pide un numero flotante. Valida lo ingresado utilizando las funciones estaticas, mygets, esNumerica,
 * posee maximos y minimo, y cantidad de reintentos en caso de que el usuario se confunda en el ingreso.
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */
int utn_getNumberFloat(float* pResultadoF, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;

 	if(pResultadoF != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultadoF = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
		return retorno;
}

/**
 * @fn int utn_getCharacter(char*, char[], char*, int)
 * @brief pide un carcater. Valida lo ingresado utilizando las funciones estaticas, mygets, esLetra,
 * posee maximos y minimo, y cantidad de reintentos en caso de que el usuario se confunda en el ingreso.
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param reintentos
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */

int utn_getCharacter(char* pResultado, char mensaje[] , char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(myGets(buffer, sizeof(buffer)) == 0 && esLetra(buffer) == 1)
			{
				stpcpy(pResultado,buffer);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	 }
	return retorno;
}

/**
 * @fn int utn_nombreOapellido(char*, char*, char*, int, int)
 * @brief pide el ingreso de un string (nombres o apellidos), utiliza funciones myGets y esLetra.
 * con la funciones toUpper deja en mayuscula la primer letra del string y luego con toLower deja en minuscula
 * el resto de la cadena.
 *
 * @param string
 * @param mensaje
 * @param mensajeError
 * @param tam
 * @param reintentos
 * @return -1 si hubo errores o 0 en caso de que la funcion halla cumplido con su tarea
 */
int utn_nombreOapellido(char* string, char* mensaje, char* mensajeError, int tam, int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	int retornoMyGets;
	int retornoEsLetra;


	if(string != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
		   printf("%s\n", mensaje);

		   retornoMyGets = myGets(buffer, sizeof(buffer));
		   retornoEsLetra = esLetra(buffer);

			if(retornoMyGets == 0 && retornoEsLetra == 1 )
			{
			   retorno = 0;
			   char mayus;
			   char minus;
			   mayus = toupper(buffer[0]);
			   buffer[0] = mayus;

			   for( int i = 1; i < tam - 1; i++)
			   {
				   minus = tolower(buffer[i]);
				   buffer[i] = minus;
			   }

				strcpy(string, buffer);
				break;
			}
			else
			{
				printf("%s\n", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			printf("\nSe quedo sin intentos para ingresar correctamente sus datos.\n");
		}

		}

	return retorno;
}

int utn_telephoneNumber(char* string, char* mensaje, char* mensajeError, int tam, int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	int retornoMyGets;
	int retornoEsCifra;

	if(string != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
		   printf("%s\n", mensaje);

		   retornoMyGets = myGets(buffer, sizeof(buffer));
		   retornoEsCifra = esCifra(buffer);

			if(retornoMyGets == 0 && retornoEsCifra == 1 )
			{
			   retorno = 0;
		       strcpy(string, buffer);
		       break;
			}
			else
			{
				printf("%s\n", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			printf("\nSe quedo sin intentos para ingresar correctamente sus datos.\n");
		}
	}
	return retorno;
}



