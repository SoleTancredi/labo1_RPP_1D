/*
 ============================================================================
 Name        : Parte3.c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Perros.h"
#include "EstadiaDiaria.h"
#include "Duenio.h"
#include "Inputs.h"
#include "Nexo.h"

#define CANT_P 30
#define CANT_E 30
#define CANT_D 30

int main(void)
{
	EstadiaDiaria arrayEstadias[CANT_E];
	Perro arrayPerros[CANT_P];
	Duenio arrayDuenio[CANT_D];
	int idPerro = 7000;
	int idDuenio = 30000;
	int id = 100000;
	int flagReserva = 0;
	int contadorEstadias = 0;
	int opcion;
	float promedioEdadPerritos;

	inicializarEstadia(arrayEstadias, CANT_E);
	inicializarPerro( arrayPerros,CANT_P);
	inicializarDuenio(arrayDuenio, CANT_D);
	cargarPerrosHarcode(arrayPerros, &idPerro);
	cargarDuenioHarcode(arrayDuenio, &idDuenio);

	do
	{
		opcion = menuEstadia();

		switch(opcion)
		{
			case 1:
				if(altaEstadia(arrayEstadias, CANT_E, &id, arrayPerros, CANT_P, arrayDuenio, CANT_D) == 0)
				{
					flagReserva = 1;
					contadorEstadias++;
				}
				else
				{
					printf("\n »» NO SE REALIZO LA RESERVA.");
				}
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 2:
				if(flagReserva == 1 && contadorEstadias > 0)
				{
					modificarEstadia(arrayEstadias, CANT_E, arrayPerros,CANT_P, arrayDuenio, CANT_D);
				}
				else
				{
					printf("\n »» NO SE PUDO REALIZAR LA MODIFICACION.");
				}
				systemPause(" »»»» Presione enter para continuar...");
				break;
			case 3:
				if(flagReserva == 1 && contadorEstadias > 0)
				{
					if(darDeBajaEstadia(arrayEstadias, CANT_E, arrayPerros, CANT_P, arrayDuenio, CANT_D)==0)
					{
						contadorEstadias--;
						printf("\n »»» ESTADIA ELIMINADA «««");
					}
					else
					{
						printf("\n »» NO SE DIO DE BAJA.");
					}
				}
				else
				{
					printf("\n »» NO HAY ESTADIAS RESERVADAS");
				}
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 4:
				if(flagReserva == 1 && contadorEstadias > 0)
				{
					ordenarEstadia(arrayEstadias, CANT_E);
					mostrarListaEstadias(arrayEstadias,CANT_E, arrayPerros, CANT_P, arrayDuenio, CANT_D);
				}
				else
				{
					printf("\n »» TODAVIA NO HAY NINGUNA ESTADIA RESERVADA. ");
				}
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 5:
				mostrarListaPerros(arrayPerros, CANT_P);
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 6:
				promedioEdadPerritos = promedioEdadPerros(arrayPerros, CANT_P);
				printf("\n »»» PROMEDIO EDAD DE LOS PERROS: [%.2f] años.",promedioEdadPerritos);
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 7:
				if(flagReserva == 1 && contadorEstadias > 0)
				{
					perroConMasEstadias(arrayEstadias, CANT_E, arrayPerros, CANT_P);
				}
				else
				{
					printf("\n »» TODAVIA NO HAY NINGUNA ESTADIA RESERVADA. ");
				}
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 8:
				if(flagReserva == 1 && contadorEstadias > 0)
				{
					mostrarPerrosConSusEstadias(arrayPerros, CANT_P, arrayEstadias, CANT_E,arrayDuenio, CANT_D);
				}
				else
				{
					printf("\n »» TODAVIA NO HAY NINGUNA ESTADIA RESERVADA. ");
				}
				systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 9:
		        if(altaPerrito(arrayPerros, CANT_P,&idPerro) == 0)
		        {
		        	printf("\n »»» CARGA COMPLETA «««");
		        }
		        else
		        {
		        	printf("\n »» NO SE DIO DE ALTA NINGUN PERRITO.");
		        }
		        systemPause("\n »»»» Presione enter para continuar...");
				break;
			case 10:

			  break;
			case 11:
				break;
			case 12:
				break;
		}

	}while(opcion != 12);


	return EXIT_SUCCESS;
}

