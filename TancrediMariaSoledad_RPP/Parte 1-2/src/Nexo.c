/*
 * nexo.c
 *
 *  Created on: 21 oct. 2021
 *      Author: sole
 */

#include "Nexo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "EstadiaDiaria.h"
#include "Perros.h"
#include "Duenio.h"

/**
 * @fn int altaEstadia(EstadiaDiaria*, int, int*, Perro*, int)
 * @brief pide lo datos al usuario para que de de alta un nuevo elemento
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @param arrayPerro
 * @param tamP
 * @return
 */
int altaEstadia(EstadiaDiaria* arrayEstadia, int tam, int* id, Perro* arrayPerro, int tamP, Duenio* arrayDuenio, int tamD)
{
	int retorno = -1;
	int i;
	int iDuenio;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL && id != NULL)
	{
		i = findEmptyEstadia(arrayEstadia, tam);
		cartelMostrarDuenio();
		mostrarListaDuenios(arrayDuenio, tam);
		//pregunto por el cliente de la estadia
		if(utn_getNumber(&bufferE.idDuenio, "\nSELECCIONE UN DUENIO MEDIANTE EL ID:  ", "\nError.Reingrese.", 30000, 60000, 1) == 0)
		{
			if(validIdDuenio(arrayDuenio, tamD, bufferE.idDuenio) == 0)
			{
				if(indexByIdDuenio(arrayDuenio, tamD, bufferE.idDuenio,&iDuenio) == 0)
				{
					strcpy(bufferE.nombreDuenio, arrayDuenio[iDuenio].nombre);
					strcpy(bufferE.telefonoContacto, arrayDuenio[iDuenio].telefono);
				}
			}
			else
			{
				printf("\nEl ID ingresado no existe.");
			}

		}
		if(i != -1 && utn_getNumber(&bufferE.fechaEstadia.dia, "INGRESE FECHA\nDia: ","\nError. Reintente."
			,1, 31, 1) == 0 && utn_getNumber(&bufferE.fechaEstadia.mes,"Mes: ","\nError. Reintente."
			, 1, 12,1) == 0 && utn_getNumber(&bufferE.fechaEstadia.anio,"Año: ", "\nError. Reintente.", 1990, 2021, 1)  == 0)
		{
			cartelMostrarPerros();
			mostrarListaPerros(arrayPerro, tamP);
			if(utn_getNumber(&bufferE.idPerro, "\nIngrese PERRO mediante ID:", "\nError.Reingrese.", 7000, 10000, 1) == 0)
			{
				if(validIdPerro(arrayPerro, tamP, bufferE.idPerro) == 0)
				{
					if(addEstadia(&arrayEstadia[i], id,bufferE.nombreDuenio ,bufferE.telefonoContacto , bufferE.idPerro,bufferE.idDuenio, bufferE.fechaEstadia.dia, bufferE.fechaEstadia.mes, bufferE.fechaEstadia.anio) == 0)
					{
						printf("perfecto");
						retorno = 0;
					}

				}
				else
				{
					printf("\nEl ID ingresado no existe.");
				}

			}

		}

	}

	return retorno;
}

/**
 * @fn int modificarEstadia(EstadiaDiaria*, int, Perro*)
 * @brief modifica algunos datos de la estadia segun eleccion del usuario
 *
 * @param arrayEstadia
 * @param tam
 * @param arrayPerritos
 * @return
 */
int modificarEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerritos, int tamPerro, Duenio* arrayDuenio, int tamDuenio)
{
	int retorno = -1;
	int option;
	int indice;
	int bufferId;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL )
	{
		mostrarListaEstadias(arrayEstadia, tam, arrayPerritos, tamPerro, arrayDuenio, tamDuenio);
		if(utn_getNumber(&bufferId, "\nIngrese el ID de la ESTADIA que desea modificar:  "
				,"\nError. Reingrese.",100000,150000, 1) == 0 &&
		findByIdEstadia(arrayEstadia, tam, bufferId,&indice) == 0)
		{
			do
			{
				if(subMenuModifEstadia(arrayEstadia, tam,&option) == 0)
			{
				switch(option)
				{
					case 1:
						if(utn_telephoneNumber(bufferE.telefonoContacto,"\nIngrese el nuevo telefono de contacto:"
								,"\nError. Reingrese el numero.", tam, 1) == 0)
						{
							printf("\nEl telefono de contacto ingresado es: %s", bufferE.telefonoContacto);
							strcpy(arrayEstadia[indice].telefonoContacto, bufferE.telefonoContacto);
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 2:
						mostrarListaPerros(arrayPerritos, tam);
						if(utn_getNumber(&bufferE.idPerro, "\nIngrese el nuevo Id del perro."
						, "\nError. Reingrese el id.", 7000, 10000, 1) == 0
						&& validIdPerro(arrayPerritos, tam, bufferE.idPerro) == 0
						)
						{
							printf("\nEl ID ingreado es: %d",bufferE.idPerro);
							arrayEstadia[indice].idPerro = bufferE.idPerro;
						}
						break;
					case 3:
						printf(" Salir de modificaciones.");
						break;
				}
				retorno = 0;
			}

			}while(option != 3);
		}


	}

	return retorno;
}

void mostrarPerrosConSusEstadias(Perro* arrayPerro, int tamPerro, EstadiaDiaria* arrayEstadia, int tamEstadia)
{

	if(arrayPerro != NULL && arrayEstadia != NULL)
	{
		for(int i = 0; i < tamPerro; i++)
		{
			for(int j = 0; j < tamEstadia; j++)
			{
				if(arrayPerro[i].id == arrayEstadia[j].idPerro)
				{
					//mostrarUnidadEstadia(arrayEstadia[j]);
     			}

			}
		}
	}
}



int mostrarUnidadEstadia(EstadiaDiaria unaEstadia, Perro arrayPerro, Duenio arrayDuenio)
{
	int ok=-1;

	if(unaEstadia.isEmpty == 1)
	{
		ok=0;
		printf("%-10d|\t %-15s %-15s %-15s %-15s %d/%d/%d\n",unaEstadia.id,unaEstadia.nombreDuenio,unaEstadia.telefonoContacto,arrayPerro.nombre,arrayPerro.raza,unaEstadia.fechaEstadia.dia,unaEstadia.fechaEstadia.mes,unaEstadia.fechaEstadia.anio);
	}
	return ok;
}

void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam, Perro* arrayPerros, int tamPerro, Duenio* arrayDuenios, int tamDuenio)
{
	int conteoEstadias=0;
	int indexPerro;
	int indexDuenio;

	cartelMostrarEstadia();
	for(int i =0; i < tam; i++)
	{
		//printf("\nmostrar I valor: %d\n", i);
		//id estadia, id perro, telefon, nombreduenio, fecha
		indexByIdPerro(arrayPerros, tamPerro, arrayEstadias[i].idPerro, &indexPerro);
		indexByIdDuenio(arrayDuenios, tamDuenio, arrayEstadias[i].idDuenio, &indexDuenio);
		if(mostrarUnidadEstadia(arrayEstadias[i], arrayPerros[indexPerro], arrayDuenios[indexDuenio]) == 0)
		{
			printf("------------------------------------------------------------------------------------------------\n");
			conteoEstadias++;
		}
	}

	printf("\n\t\t\t\t\t\tCantidad de Estadias:%d \n",conteoEstadias);
}

int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arraPerros, int tamPerro, Duenio* arrayDuenio, int tamDuenio)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayEstadia!= NULL)
	{
		printf("\n***** DAR DE BAJA UNA ESTADIA *****\n");

		mostrarListaEstadias(arrayEstadia, tam, arraPerros, tamPerro, arrayDuenio, tamDuenio);

		if( utn_getNumber(&id, "\nIngrese el ID de la ESTADIA que desea cancelar: ","\nError. Reingrese el ID."
					, 100000, 150000, 1) == 0 && findByIdEstadia(arrayEstadia, tam, id, &indice) == 0)

		{
			if(eliminarEstadia(&arrayEstadia[indice]) == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

