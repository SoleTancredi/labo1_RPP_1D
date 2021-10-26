/*
 * Duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Duenio.h"
#include "Inputs.h"

void inicializarDuenio(Duenio* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}

void cargarDuenioHarcode(Duenio* arrayDuenio, int* id)
{
		Duenio bufferDuenio[] =
		{
			{30000, "Abel", "Gonzales", "1596351203",1},
			{31000, "Carlos", "Perez", "1168451236",1},
			{32000, "Pedro", "Alvarez", "48429672",1},
			{33000, "Zahira", "Zarate", "1589452301",1},
			{34000, "Ernesto", "Luces","48425632",1}
		};

		for(int i = 0; i < 5; i++)
		{
			arrayDuenio[i] = bufferDuenio[i];
			(*id)++;
		}
}

void cartelMostrarDuenio()
{
	printf("\n\t\t\t## LISTADO DE DUENIOS ##");
	printf("\n__________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID DUENIO","NOMBRE ","APELLIDO ","TELEFONO DE CONTACTO ");
	printf("__________________________________________________________________________\n");
}

int mostrarUnidadDuenio(Duenio unDuenio)
{
	int ok=-1;
	if(unDuenio.isEmpty == 1)
	{
		ok=0;
		printf("   %-10d|   %-15s %-15s %-15s\n",unDuenio.id,unDuenio.nombre,unDuenio.apellido,unDuenio.telefono);
		printf("--------------------------------------------------------------------------\n");
	}
	return ok;
}

void mostrarListaDuenios(Duenio* arrayDuenio, int tam)
{
	int conteoDuenios=0;
	for(int i =0; i < tam; i++)
	{
		//printf("\nmostrar I valor: %d\n", i);
		if(arrayDuenio[i].isEmpty == 1)
		{
			mostrarUnidadDuenio(arrayDuenio[i]);
			conteoDuenios++;
		}
	}

	printf("\n\t\t\t\t\t\tCantidad de Duenios:%d \n",conteoDuenios);
}

int eliminarDuenio(Duenio* unidadDuenio)
{
	int retorno=-1;

	if(unidadDuenio!=NULL)
	{
		(*unidadDuenio).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}

int findEmptyDuenio(Duenio* arrayDuenio, int tam)
{
	int indice = -1;

	if(arrayDuenio != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayDuenio[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int indexByIdDuenio(Duenio* arrayDuenio, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayDuenio != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayDuenio[i].isEmpty == 1 && arrayDuenio[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int menuDuenio()
{
	int option;

	printf("\n***** MENU ABM DUENIO *****\n");

	if(utn_getNumber(&option, "\nIngrese la opcion que desee realizar: "
				"\n1.Dar de alta un DUENIO. "
				"\n2.Dar de Baja un DUENIO. "
				"\n3.Modificar un DUENIO."
				"\n4.Listar todos los DUENIOS."
				"\n5.Salir. "
				, "\nError. Reingrese la opcion. \n"
				, 1, 5, 1) == 0)
	{
		printf("\nUsted ha ingresado la opcion nº %d\n", option);

	}

return option;

}

int addDuenio(Duenio* pUnidadDuenio,int tam, int* id, char* name, char* apellido, char* telefono)
{
	int retorno = -1;

	if(pUnidadDuenio != NULL && id != NULL && name != NULL && apellido != NULL && telefono != NULL)
	{

		(*pUnidadDuenio).isEmpty = 1;
		strcpy((*pUnidadDuenio).nombre, name);
		strcpy((*pUnidadDuenio).apellido, apellido);
		strcpy((*pUnidadDuenio).telefono, telefono);
		(*pUnidadDuenio ).id = (*id)++;
		retorno = 0;
	}

	return retorno;
}

int altaDuenio(Duenio* arrayDuenio, int tam, int* id)
{
	int retorno = -1;
	int i;
	Duenio bufferDuenio;

	if(arrayDuenio != NULL)
	{
		i = findEmptyDuenio(arrayDuenio, tam);

		if(i != -1 && utn_nombreOapellido(bufferDuenio.nombre, "\nIngrese el nombre del duenio: ", "\nError. Reingrese el nombre.\n"
			, TAM_D,1 ) == 0 && utn_nombreOapellido(bufferDuenio.apellido, "\nIngrese el apellido: ", "\nError. Reingrese el apellido.\n", TAM_D, 1) == 0
			&& utn_telephoneNumber(bufferDuenio.telefono,"\nIngrese el telefono de contacto: "
					, "\nError. Reingrese el telefono.", tam, 1) == 0)
		{
			addDuenio(&arrayDuenio[i], tam, id, bufferDuenio.nombre, bufferDuenio.apellido, bufferDuenio.telefono);
			retorno = 0;
		}

	}

	return retorno;
}

int menuModificarDuenio(Duenio* arrayDuenio, int len, int* indice, int* option)
{

	int retorno = -1;
	int idBuscado;

	if(arrayDuenio != NULL)
	{

		printf("\n***** MODIFICAR DATOS *****\n");

		mostrarListaDuenios(arrayDuenio, len);

		if( utn_getNumber(&idBuscado, "\nIngrese el ID del duenio que desea modificar: ","\nError. Reingrese el ID."
				, 30000, 60000, 1) == 0 && indexByIdDuenio(arrayDuenio, len, idBuscado, indice) == 0)
		{
			if(utn_getNumber(option, "\nIngrese la opcion del dato que desea modificar:"
					"\n1. NOMBRE."
					"\n2. APELLIDO."
					"\n3. NUMERO DE TELEFONO. "
					"\n4. SALIR. ", "Error. Reingrese la opcion", 1, 4, 1) == 0)
			{
				printf("\nUsted ha ingresado la opcion nº %d", *option);
				retorno = 0;

			}

		}
		else
		{
			printf("\nEl ID ingreado es inexistente.");
		}

	}

	return retorno;
}

int modificarDuenio(Duenio* arrayDuenio, int len)
{
	int retorno = -1;
	int indice;
	int option;
	Duenio bufferDuenio;

	if(arrayDuenio != NULL )
	{
		do
		{
			if(menuModificarDuenio(arrayDuenio, len, &indice, &option ) == 0)
		{
			switch(option)
			{
				case 1:
					if(utn_nombreOapellido(bufferDuenio.nombre,"\nIngrese el nombre del duenio: "
							, "\nError. Reingrese el nombre.", TAM_D, 1) == 0)
					{
						printf("\nEl nuevo nombre es: %s", bufferDuenio.nombre);
						strcpy(arrayDuenio[indice].nombre,bufferDuenio.nombre);
					}
					else
					{
						printf("\nNo se ha podido realizar la modificacion de manera correcta");
					}
					break;
				case 2:
					if(utn_nombreOapellido(bufferDuenio.apellido, "\nIngrese el apellido: "
							, "\nError. Reingrese el apellido", TAM_D, 1) == 0)
					{
						printf("\nEl apellido ingresado es: %s", bufferDuenio.apellido);
						strcpy(arrayDuenio[indice].apellido, bufferDuenio.apellido);
					}
					break;
				case 3:
					if(utn_telephoneNumber(bufferDuenio.telefono,"\nIngrese el nuevo telefono de contacto:"
							,"\nError. Reingrese el numero.", len, 1) == 0)
					{
						printf("\nEl telefono de contacto ingresado es: %s", bufferDuenio.telefono);
						strcpy(arrayDuenio[indice].telefono, bufferDuenio.telefono);
					}
					else
					{
						printf("\nNo se ha podido realizar la modificacion de manera correcta");
					}
					break;
				case 4:
					printf(" Salir.");
					break;
			}
			retorno = 0;
		}

		}while(option != 4);
	}

	return retorno;
}

int darDeBajaDuenio(Duenio* arrayDuenio, int len)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayDuenio != NULL)
	{
		printf("\n***** DAR DE BAJA UN PERRITO *****\n");

		mostrarListaDuenios(arrayDuenio, len);

		if( utn_getNumber(&id, "\nIngrese el ID del perro que desea eliminar: ","\nError. Reingrese el ID."
					, 30000, 60000, 1) == 0 && indexByIdDuenio(arrayDuenio, len, id, &indice) == 0)

		{
			if(eliminarDuenio(&arrayDuenio[indice]) == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}


int validIdDuenio(Duenio* arrayDuenio, int tam, int id)
{
	int retorno = -1;

	if(arrayDuenio!= NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if(arrayDuenio[i].isEmpty == 1 && arrayDuenio[i].id == id)
				{
					retorno = 0;
				}
			}
		}

	return retorno;
}



