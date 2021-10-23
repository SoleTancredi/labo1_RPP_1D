/*
 * EstadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "EstadiaDiaria.h"
#include "Nexo.h"


/**
 * @fn int menuEstadia()
 * @brief muestra el cartel Menu de opciones
 *
 * @return
 */

int menuEstadia()
{
	int option;

	printf("\n    		 *****GUARDERIA DE PERRITOS*****\n\n");

	if(utn_getNumber(&option, "     		      ** MENU PRINCIPAL **"
			"  \n"
			"\n [1] RESERVAR ESTADIA. "
			"\n [2] MODIFICAR ESTADIA. "
			"\n [3] CANCELAR ESTADIA. "
			"\n [4] LISTAR ESTADIAS. "
			"\n [5] LISTAR PERROS. "
			"\n [6] PROMEDIO DE EDAD DE LOS PERROS. "
			"\n [7] PERRO CON MAS ESTADIAS RESERVADAS."
			"\n [8] LISTADO DE PERROS CON SUS ESTADIAS DIARIAS RESERVADAS."
			"\n [9] FINALIZAR.\n"
			"\n --> INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA:  "
			, "Error. Reingrese la opcion. "
			, 1, 9, 1) == 0)
	{
		printf("\nUsted ha ingresado la opcion nº %d\n", option);
	}

return option;

}
/**
 * @fn void inicializarEstadia(EstadiaDiaria*, int)
 * @brief inicializa el array
 *
 * @param array
 * @param tam
 */
void inicializarEstadia(EstadiaDiaria* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}


void cartelMostrarEstadia()
{

	printf("\n\t\t## LISTADO DE ESTADIAS CON SUS DATOS CORRESPONDIENTES ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");

}

/**
 * @fn void mostrarListaEstadias(EstadiaDiaria*, int)
 * @brief imprime el array completo de elementos
 *
 * @param arrayEstadias
 * @param tam
 */


/**
 * @fn int eliminarEstadia(EstadiaDiaria*)
 * @brief da la baja logica de un elemento del array
 *
 * @param unidadEstadia
 * @return
 */
int eliminarEstadia(EstadiaDiaria* unidadEstadia)
{
	int retorno=-1;

	if(unidadEstadia!=NULL)
	{
		(*unidadEstadia).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}

/**
 * @fn int findEmptyEstadia(EstadiaDiaria*, int)
 * @brief encuntra un lugar vacio dentro del array
 *
 * @param arrayEstadia
 * @param tam
 * @return
 */
int findEmptyEstadia(EstadiaDiaria* arrayEstadia, int tam)
{
	int indice = -1;

	if(arrayEstadia != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/**
 * @fn int findByIdEstadia(EstadiaDiaria*, int, int, int*)
 * @brief realiza la busqueda de un elemento mediante el Id y devuelve por referencia su ubicacion
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @param indice
 * @return
 */
int findByIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayEstadia != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 1 && arrayEstadia[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;

}
/**
 * @fn int addEstadia(EstadiaDiaria*, int*, char*, char*, int, int, int, int)
 * @brief toma por parametro los datos y los ubica en cada campo correspondiente en el elemento del array
 *
 * @param unidadEstadia
 * @param id
 * @param nombreDuenio
 * @param telefono
 * @param idPerro
 * @param dia
 * @param mes
 * @param anio
 * @return
 */
int addEstadia(EstadiaDiaria* unidadEstadia,int* id, char* nombreDuenio, char* telefono, int idPerro,int idDuenio, int dia, int mes, int anio)
{
	int retorno = -1;

	if(unidadEstadia != NULL && nombreDuenio != NULL && telefono != NULL)
	{
		(*unidadEstadia).isEmpty = 1;
		(*unidadEstadia).id = *id;
		strcpy((*unidadEstadia).nombreDuenio, nombreDuenio);
		strcpy((*unidadEstadia).telefonoContacto,telefono);
		(*unidadEstadia).idPerro = idPerro;
		(*unidadEstadia).idDuenio = idDuenio;
		(*unidadEstadia).fechaEstadia.dia = dia;
		(*unidadEstadia).fechaEstadia.mes = mes;
		(*unidadEstadia).fechaEstadia.anio = anio;
		(*id)++;
		retorno = 0;

	}

	return retorno;
}


/**
 * @fn int subMenuModifEstadia(EstadiaDiaria*, int, int*)
 * @brief muestra el cartel de un subMenu de opciones para realizar modificaciones
 *
 * @param arrayEstadia
 * @param tam
 * @param option
 * @return
 */
int subMenuModifEstadia(EstadiaDiaria* arrayEstadia, int tam,int* option)
{
	int retorno = -1;
	if(arrayEstadia != NULL)
	{
		printf("\n########## MODIFICAR DATOS ##########\n");

		if(utn_getNumber(option, "\nIngrese la opcion del dato que desea modificar:"
						"\n1. TELEFONO DE CONTACTO."
						"\n2. PERRO segun su Identificador."
						"\n3. SALIR. "
						, "Error. Reingrese la opcion", 1, 3, 1) == 0)
		{
			printf("\nUsted ha ingresado la opcion nº %d", *option);
			retorno = 0;
		}

	}

	return retorno;
}


/**
 * @fn int validIdEstadia(EstadiaDiaria*, int, int)
 * @brief valida la existencia de un Id
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @return
 */
int validIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id)
{
	int retorno = -1;

	if(arrayEstadia != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if(arrayEstadia[i].isEmpty == 1 && arrayEstadia[i].id == id)
				{
					retorno = 0;
				}
			}
		}

	return retorno;
}

/**
 * @fn int ordenarEstadia(EstadiaDiaria*, int)
 * @brief ordena por fecha cada elemento del array, en caso de tener igualdad de fechas ordena
 * por orden alfabetico el nombre de los dueños
 *
 * @param arrayEstadia
 * @param tam
 * @return
 */
int ordenarEstadia(EstadiaDiaria* arrayEstadia,int tam)
{
	int retorno=-1;
	int flag = 1;
	int newTam;
	EstadiaDiaria aux;

	if(arrayEstadia != NULL)
	{
		newTam = tam -1;

		do
		{
			flag = 1;

			for(int i = 0; i < newTam; i++)
			{
				if(arrayEstadia[i].fechaEstadia.anio < arrayEstadia[i+1].fechaEstadia.anio)
				{
					flag = 0;
					aux = arrayEstadia[i];
					arrayEstadia[i]=arrayEstadia[i+1];
					arrayEstadia[i+1]=aux;
					retorno = 0;
				}
				else
				{
					if(arrayEstadia[i].fechaEstadia.anio == arrayEstadia[i+1].fechaEstadia.anio)
					{
						if(arrayEstadia[i].fechaEstadia.mes < arrayEstadia[i+1].fechaEstadia.mes)
						{
							flag = 0;
							aux = arrayEstadia[i];
							arrayEstadia[i]=arrayEstadia[i+1];
							arrayEstadia[i+1]=aux;
							retorno = 0;
						}
						else
						{
							if(arrayEstadia[i].fechaEstadia.mes == arrayEstadia[i+1].fechaEstadia.mes)
							{
								if(arrayEstadia[i].fechaEstadia.dia < arrayEstadia[i+1].fechaEstadia.dia)
								{
									flag = 0;
									aux = arrayEstadia[i];
									arrayEstadia[i]=arrayEstadia[i+1];
									arrayEstadia[i+1]=aux;
									retorno = 0;
								}
								else
								{
									if(arrayEstadia[i].fechaEstadia.dia == arrayEstadia[i+1].fechaEstadia.dia)
									{
										if(strcmp(arrayEstadia[i].nombreDuenio, arrayEstadia[i+1].nombreDuenio) > 0)
										{
											flag = 0;
											aux = arrayEstadia[i];
											arrayEstadia[i]=arrayEstadia[i+1];
											arrayEstadia[i+1]=aux;
											retorno = 0;
										}
									}
								}
							}
						}
					}
				}
				newTam--;
			}

		}while(flag == 0);
	}




	return retorno;
}













