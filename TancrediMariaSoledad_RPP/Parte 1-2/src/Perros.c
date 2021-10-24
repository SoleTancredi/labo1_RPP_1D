/*
 * Perros.c
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
#include "Perros.h"

/**
 * @fn void inicializarPerro(Perro*, int)
 * @brief se inicializa el isEmpty solamente ya que despues guiandome por ese dato, si esta vacio directamente
 * no muestro el dato y si sucede lo contrario si.
 *
 * @param array
 * @param tam
 */
void inicializarPerro(Perro* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}

void cartelMostrarPerros()
{
	printf("\n\t\t## LISTADO DE PERROS ##");
	printf("\n__________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID PERRO ","NOMBRE ","RAZA ","EDAD ");
	printf("__________________________________________________________\n");
}

/**
 * @fn int mostrarUnidadPerro(Perro)
 * @brief muestra los campos de un solo elemento del array
 *
 * @param unPerro
 * @return ok 0 si todo salio bien
 */
int mostrarUnidadPerro(Perro unPerro)
{
	int ok=-1;
	if(unPerro.isEmpty == 1)
	{
		ok=0;
		printf("  %-6d|\t %-15s%-15s %-15d\n",unPerro.id,unPerro.nombre,unPerro.raza,unPerro.edad);
		printf("----------------------------------------------------------\n");
	}
	return ok;
}
/**
 * @fn void mostrarListaPerros(Perro*, int)
 * @brief muestra el listado completo de elementos ingreados
 *
 * @param arrayPerros
 * @param tam
 */

void mostrarListaPerros(Perro* arrayPerros, int tam)
{
	int conteoPerros=0;
	cartelMostrarPerros();
	for(int i =0; i < tam; i++)
	{
		//printf("\nmostrar I valor: %d\n", i);
		if(mostrarUnidadPerro(arrayPerros[i]) == 0)
		{
			conteoPerros++;
		}
	}

	printf("\n\t\t\t\t Cantidad de perros :%d \n",conteoPerros );
}

/**
 * @fn void cargarPerrosHarcode(Perro*, int*)
 * @brief harcodeo de algunos elementos
 *
 * @param arrayPerros
 * @param id
 */
void cargarPerrosHarcode(Perro* arrayPerros, int* id)
{
		Perro bufferPerrito[] =
		{
			{7000, "Lobo", "Sharpei", 2,1},
			{7001, "Sheila", "Golden", 12,1},
			{7002, "Reina", "Galgo",13,1}
		};

		for(int i = 0; i < 3; i++)
		{
			arrayPerros[i] = bufferPerrito[i];
			(*id)++;
		}
}

/**
 * @fn int eliminarPerro(Perro*)
 * @brief borra un elemento del array
 *
 * @param unidadPerro
 * @return  0 en caso de exito, -1 en caso contrario
 */
int eliminarPerro(Perro* unidadPerro)
{
	int retorno=-1;

	if(unidadPerro!=NULL)
	{
		(*unidadPerro).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}

/**
 * @fn int findEmpty(Perro*, int)
 * @brief recibe por parametro el array de tipo perro y su tamaño, recorre cada a elemento y compara el valor
 * del campo isEmpty con 0 (ha encontrado un lugar libre), si NO es 0 la posicion esta ocupada.
 *
 * @param arrayPerrito
 * @param tam
 * @return retorna la variable indice, que toma el valor de i cuando esta coincide con el valor 0.
 */
int findEmpty(Perro* arrayPerrito, int tam)
{
	int indice = -1;

	if(arrayPerrito != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayPerrito[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/**
 * @fn int altaPerrito(Perro*, int, int*)
 * @brief recibe por paramentro un puntero al array que va a ser modificado, el tamaño y un puntero a la variable
 * id; luego de ubicar un lugar libre con la funcion isEmpty, pide los datos al usuario y los mismos se pasan
 * como argumento a la funcion add que ubica los datos en la estructura.
 *
 * @param arrayPerrito
 * @param tam
 * @param id
 * @return  0 si todo salio bien, - si hubo errores.
 */
int altaPerrito(Perro* arrayPerrito, int tam, int* id)
{
	int retorno = -1;
	int i;
	Perro bufferPerrito;

	if(arrayPerrito != NULL)
	{
		i = findEmpty(arrayPerrito, tam);

		if(i != -1 && utn_nombreOapellido(bufferPerrito.nombre, "\nIngrese el nombre del perro: ", "\nError. Reingrese el nombre.\n"
			, TAM,1 ) == 0 && utn_nombreOapellido(bufferPerrito.raza, "\nIngrese la raza: ", "\nError. Reingrese la raza.\n", TAM, 1) == 0
			&& utn_getNumber(&bufferPerrito.edad, "\nIngrese la edad: ", "\nError. Reingrese la edad.\n", 1,50, 1) == 0)
		{
			addPerrito(&arrayPerrito[i], tam, id, bufferPerrito.nombre, bufferPerrito.raza, bufferPerrito.edad);
			retorno = 0;
		}

	}

	return retorno;
}

/**
 * @fn int addPerrito(Perro*, int, int*, char*, char*, int)
 * @brief ubica los datos pedidos por paramentro en la estructura
 *
 * @param pUnidadPerrito
 * @param len
 * @param id
 * @param name
 * @param race
 * @param age
 * @return - si hubo error, 0 si todo funciono bien
 */
int addPerrito(Perro* pUnidadPerrito, int len, int* id, char* name, char* race, int age)
{
	int retorno = -1;

	if(pUnidadPerrito != NULL && id != NULL && name != NULL && race != NULL)
	{

		(*pUnidadPerrito).isEmpty = 1;
		strcpy((*pUnidadPerrito).nombre, name);
		strcpy((*pUnidadPerrito).raza, race);
		(*pUnidadPerrito).edad = age;
		(*pUnidadPerrito).id = (*id)++;
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int menuModificar(Perro*, int)
 * @brief menu que muestra el cartel con las instrucciones ara que el usuario
 * valla mofidificando los datos.
 *
 * @param arrayPerritos
 * @param len
 * @return retorna el numero de la opcion seleccionada.
 */
int menuModificar(Perro* arrayPerritos, int len, int* indice, int* option)
{

	int retorno = -1;
	int idBuscado;

	if(arrayPerritos != NULL)
	{

		printf("\n***** MODIFICAR DATOS *****\n");

		mostrarListaPerros(arrayPerritos, len);

		if( utn_getNumber(&idBuscado, "\nIngrese el ID del perro que desea modificar: ","\nError. Reingrese el ID."
				, 7000, 10000, 1) == 0 && indexByIdPerro(arrayPerritos, len, idBuscado, indice) == 0)
		{
			if(utn_getNumber(option, "\nIngrese la opcion del dato que desea modificar:"
					"\n1. NOMBRE."
					"\n2. RAZA."
					"\n3. EDAD. "
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

/**
 * @fn int findById(Perro*, int, int, int*)
 * @brief busca el id ingresado en cada elemento del array, y al encontrarlo devuelde por puntero el
 * la ubicacion especifica del elemento segun su indice
 *
 * @param arrayPerritos
 * @param tam
 * @param id
 * @param indice
 * @return
 */
int indexByIdPerro(Perro* arrayPerritos, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayPerritos != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayPerritos[i].isEmpty == 1 && arrayPerritos[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;

}
/**
 * @fn int validIdPerro(Perro*, int, int)
 * @brief valida la existencia del Id
 *
 * @param arrayPerritos
 * @param tam
 * @param id
 * @return
 */
int validIdPerro(Perro* arrayPerritos, int tam, int id)
{
	int retorno = -1;

	if(arrayPerritos != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if(arrayPerritos[i].isEmpty == 1 && arrayPerritos[i].id == id)
				{
					retorno = 0;
				}
			}
		}

	return retorno;
}


/**
 * @fn int modificarPerrito(Perro*, int)
 * @brief segun la eleccion del ususario va modificando cada uno de los datos del elemento.
 *
 * @param arrayPerritos
 * @param len
 * @return
 */
int modificarPerrito(Perro* arrayPerritos, int len)
{
	int retorno = -1;
	int indice;
	int option;
	Perro bufferPerrito;

	if(arrayPerritos != NULL )
	{
		do
		{
			if(menuModificar(arrayPerritos, len, &indice, &option ) == 0)
		{
			switch(option)
			{
				case 1:
					if(utn_nombreOapellido(bufferPerrito.nombre,"\nIngrese el nombre: "
							, "\nError. Reingrese el nombre.", TAM, 1) == 0)
					{
						printf("\nEl nuevo nombre es: %s", bufferPerrito.nombre);
						strcpy(arrayPerritos[indice].nombre,bufferPerrito.nombre);
					}
					else
					{
						printf("\nNo se ha podido realizar la modificacion de manera correcta");
					}
					break;
				case 2:
					if(utn_nombreOapellido(bufferPerrito.raza, "\nIngrese la raza: "
							, "\nError. Reingrese la raza", TAM, 1) == 0)
					{
						printf("\nLa nueva raza es: %s", bufferPerrito.raza);
						strcpy(arrayPerritos[indice].raza, bufferPerrito.raza);
					}
					break;
				case 3:
					if(utn_getNumber(&bufferPerrito.edad, "\nIngrese la edad: "
							, "\nError. Reingrese la edad.", 1, 50, 1) == 0)
					{
						printf("\nLa nueva edad es: %d", bufferPerrito.edad);
						arrayPerritos[indice].edad = bufferPerrito.edad;
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
 * @fn int menuPerrito()
 * @brief menu que muestra un cartel con las opciones de ABM
 *
 * @return
 */
int menuPerrito()
{
	int option;


	printf("\n***** MENU ABM PERRITO *****\n");

	if(utn_getNumber(&option, "\nIngrese la opcion que desee realizar: "
				"\n1.Dar de alta un perrito. "
				"\n2.Dar de Baja un perrito. "
				"\n3.Modificar un perrito."
				"\n4.Listar todos los perritos."
				"\n5.Salir. "
				, "\nError. Reingrese la opcion. \n"
				, 1, 5, 1) == 0)
	{
		printf("\nUsted ha ingresado la opcion nº %d\n", option);

	}

return option;

}

/**
 * @fn int darDeBajaPerrito(Perro*, int)
 * @brief elimina un elemento del array, mediante el ingreso del ID del mismo
 *
 * @param arrayPerritos
 * @param len
 * @return
 */
int darDeBajaPerrito(Perro* arrayPerritos, int len)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayPerritos != NULL)
	{
		printf("\n***** DAR DE BAJA UN PERRITO *****\n");

		mostrarListaPerros(arrayPerritos, len);

		if( utn_getNumber(&id, "\nIngrese el ID del perro que desea eliminar: ","\nError. Reingrese el ID."
					, 7000, 10000, 1) == 0 && indexByIdPerro(arrayPerritos, len, id, &indice) == 0)

		{
			if(eliminarPerro(&arrayPerritos[indice]) == 0)
			{
				retorno = 0;
			}
		}


	}

	return retorno;
}
/**
 * @fn int contadorPerros(Perro*, int)
 * @brief cuenta la cantidad de perritos existentes
 *
 * @param arrayPerro
 * @param len
 * @return
 */

int contadorPerros(Perro* arrayPerro, int len)
{
	int cantidad = 0;

	for(int i = 0; i < len; i++)
	{
		if(arrayPerro[i].isEmpty==1)
		{
			cantidad++;
		}
	}
	return cantidad;
}

/**
 * @fn float promedioEdadPerros(Perro*, int)
 * @brief devuelve el promedio de edad de los perros ingresados
 *
 * @param arrayPerros
 * @param len
 * @return
 */
float promedioEdadPerros(Perro* arrayPerros, int len)
{
	float promedio;
	int totalEdades = 0;
	int cont;

	if(arrayPerros != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(arrayPerros[i].isEmpty==1)
			{
				totalEdades += arrayPerros[i].edad;
			}
		}
		cont = contadorPerros(arrayPerros, len);
		promedio = totalEdades / cont;
	}

	return promedio;
}




