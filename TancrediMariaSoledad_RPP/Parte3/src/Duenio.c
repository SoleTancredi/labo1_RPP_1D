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

/**
 * @fn void inicializarDuenio(Duenio*, int)
 * @brief se inicializa el isEmpty solamente ya que despues guiandome por ese dato, si esta vacio directamente
 * no muestro el dato y si sucede lo contrario si.
 *
 * @param array
 * @param tam
 */
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

/**
 * @fn void cargarDuenioHarcode(Duenio*, int*)
 * @brief harcodeo de algunos elementos
 *
 * @param arrayDuenio
 * @param id
 */
void cargarDuenioHarcode(Duenio* arrayDuenio, int* id)
{
		Duenio bufferDuenio[] =
		{
			{30000, "Alan", "Gonzales", "1596351203",1},
			{31000, "Lucia", "Perez", "1168451236",1},
			{32000, "Pedro", "Alvarez", "48429672",1},
			{33000, "Lucia", "Morel", "1589452301",1},
			{34000, "Ernesto", "Luces","48425632",1},
			{35000, "Alan", "Passucci","48425697",1},
			{36000, "Martin", "Ramirez", "48429683",1}
		};

		for(int i = 0; i < 7; i++)
		{
			arrayDuenio[i] = bufferDuenio[i];
			(*id)++;
		}
}

/**
 * @fn void cartelMostrarDuenio()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelMostrarDuenio()
{
	printf("\n\t\t\t## LISTADO DE DUENIOS ##");
	printf("\n__________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID DUENIO","NOMBRE ","APELLIDO ","TELEFONO DE CONTACTO ");
	printf("__________________________________________________________________________\n");
}

/**
 * @fn int mostrarUnidadDuenio(Duenio)
 * @brief muestra un solo elemento
 *
 * @param unDuenio
 * @return
 */
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

/**
 * @fn void mostrarListaDuenios(Duenio*, int)
 * @brief muestra la lista completa de elementos existentes
 *
 * @param arrayDuenio
 * @param tam
 */
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

/**
 * @fn int eliminarDuenio(Duenio*)
 * @brief elimina un elemento
 *
 * @param unidadDuenio
 * @return
 */
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

/**
 * @fn int findEmptyDuenio(Duenio*, int)
 * @brief recibe por parametro el array de tipo perro y su tamaño, recorre cada a elemento y compara el valor
 * del campo isEmpty con 0 (ha encontrado un lugar libre), si NO es 0 la posicion esta ocupada.
 *
 * @param arrayDuenio
 * @param tam
 * @return
 */
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

/**
 * @fn int indexByIdDuenio(Duenio*, int, int, int*)
 * @brief busca el id ingresado en cada elemento del array, y al encontrarlo devuelde por puntero el
 * la ubicacion especifica del elemento segun su indice
 *
 * @param arrayDuenio
 * @param tam
 * @param id
 * @param indice
 * @return
 */
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

/**
 * @fn int menuDuenio()
 * @brief muesrta cartel de menu
 *
 * @return
 */
int menuDuenio()
{
	int option;

	printf("\n***** MENU ABM DUENIO *****\n");

	if(utn_getNumber(&option, "\n --> Ingrese la opcion que desee realizar: "
				"\n[1] Dar de alta un DUENIO. "
				"\n[2] Dar de Baja un DUENIO. "
				"\n[3] Modificar un DUENIO."
				"\n[4] Listar todos los DUENIOS."
				"\n[5] Salir. "
				, "\n × ERROR. Reingrese la opcion. \n"
				, 1, 5, 1) == 0)
	{
		printf("\n » Usted ha ingresado la opcion nº %d\n", option);

	}

return option;

}

/**
 * @fn int addDuenio(Duenio*, int, int*, char*, char*, char*)
 * @brief ubica los datos pedidos por paramentro en la estructura
 *
 * @param pUnidadDuenio
 * @param tam
 * @param id
 * @param name
 * @param apellido
 * @param telefono
 * @return
 */
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

/**
 * @fn int altaDuenio(Duenio*, int, int*)
 * @brief recibe por paramentro un puntero al array que va a ser modificado, el tamaño y un puntero a la variable
 * id; luego de ubicar un lugar libre con la funcion isEmpty, pide los datos al usuario y los mismos se pasan
 * como argumento a la funcion add que ubica los datos en la estructura.
 *
 * @param arrayDuenio
 * @param tam
 * @param id
 * @return
 */
int altaDuenio(Duenio* arrayDuenio, int tam, int* id)
{
	int retorno = -1;
	int i;
	Duenio bufferDuenio;

	if(arrayDuenio != NULL)
	{
		i = findEmptyDuenio(arrayDuenio, tam);

		if(i != -1 && utn_nombreOapellido(bufferDuenio.nombre, "\n --> Ingrese el nombre del duenio: ", "\n × ERROR. Reingrese el nombre.\n"
			, TAM_D,1 ) == 0 && utn_nombreOapellido(bufferDuenio.apellido, "\n --> Ingrese el apellido: ", "\n × ERROR. Reingrese el apellido.\n", TAM_D, 1) == 0
			&& utn_telephoneNumber(bufferDuenio.telefono,"\n -->Ingrese el telefono de contacto: "
					, "\n × ERROR. Reingrese el telefono.", tam, 1) == 0)
		{
			addDuenio(&arrayDuenio[i], tam, id, bufferDuenio.nombre, bufferDuenio.apellido, bufferDuenio.telefono);
			retorno = 0;
		}

	}

	return retorno;
}

/**
 * @fn int menuModificarDuenio(Duenio*, int, int*, int*)
 * @brief muestra un cartel con opciones para la modificacion
 *
 * @param arrayDuenio
 * @param len
 * @param indice
 * @param option
 * @return
 */
int menuModificarDuenio(Duenio* arrayDuenio, int len, int* indice, int* option)
{
	int retorno = -1;
	int idBuscado;

	if(arrayDuenio != NULL)
	{
		printf("\n***** MODIFICAR DATOS *****\n");

		mostrarListaDuenios(arrayDuenio, len);

		if( utn_getNumber(&idBuscado, "\n --> Ingrese el ID del duenio que desea modificar: ","\n × ERROR. Reingrese el ID."
				, 30000, 60000, 1) == 0 && indexByIdDuenio(arrayDuenio, len, idBuscado, indice) == 0)
		{
			if(utn_getNumber(option, "\n --> Ingrese la opcion del dato que desea modificar:"
					"\n[1] NOMBRE."
					"\n[2] APELLIDO."
					"\n[3] NUMERO DE TELEFONO. "
					"\n[4] SALIR. ", "\n × ERROR. Reingrese la opcion", 1, 4, 1) == 0)
			{
				printf("\n » Usted ha ingresado la opcion nº %d", *option);
				retorno = 0;

			}

		}
		else
		{
			printf("\n > El ID ingreado es inexistente.");
		}

	}

	return retorno;
}

/**
 * @fn int modificarDuenio(Duenio*, int)
 * @brief segun la eleccion del ususario va modificando cada uno de los datos del elemento.
 *
 * @param arrayDuenio
 * @param len
 * @return
 */
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
					if(utn_nombreOapellido(bufferDuenio.nombre,"\n -->Ingrese el nombre del duenio: "
							, "\n × ERROR. Reingrese el nombre.", TAM_D, 1) == 0)
					{
						printf("\n » El nuevo nombre es: %s", bufferDuenio.nombre);
						strcpy(arrayDuenio[indice].nombre,bufferDuenio.nombre);
					}
					else
					{
						printf("\n >> No se ha podido realizar la modificacion de manera correcta");
					}
					break;
				case 2:
					if(utn_nombreOapellido(bufferDuenio.apellido, "\n --> Ingrese el apellido: "
							, "\n × ERROR. Reingrese el apellido", TAM_D, 1) == 0)
					{
						printf("\n » El apellido ingresado es: %s", bufferDuenio.apellido);
						strcpy(arrayDuenio[indice].apellido, bufferDuenio.apellido);
					}
					break;
				case 3:
					if(utn_telephoneNumber(bufferDuenio.telefono,"\n --> Ingrese el nuevo telefono de contacto:"
							,"\n × ERROR. Reingrese el numero.", len, 1) == 0)
					{
						printf("\n » El telefono de contacto ingresado es: %s", bufferDuenio.telefono);
						strcpy(arrayDuenio[indice].telefono, bufferDuenio.telefono);
					}
					else
					{
						printf("\n >> No se ha podido realizar la modificacion de manera correcta");
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

/**
 * @fn int darDeBajaDuenio(Duenio*, int)
 * @brief elimina un elemento del array, mediante el ingreso del ID del mismo
 *
 * @param arrayDuenio
 * @param len
 * @return
 */
int darDeBajaDuenio(Duenio* arrayDuenio, int len)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayDuenio != NULL)
	{
		printf("\n***** DAR DE BAJA UN PERRITO *****\n");

		mostrarListaDuenios(arrayDuenio, len);

		if( utn_getNumber(&id, "\n --> Ingrese el ID del perro que desea eliminar: ","\n × ERROR. Reingrese el ID."
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

/**
 * @fn int validIdDuenio(Duenio*, int, int)
 * @brief valida la existencia del Id
 *
 * @param arrayDuenio
 * @param tam
 * @param id
 * @return
 */
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



