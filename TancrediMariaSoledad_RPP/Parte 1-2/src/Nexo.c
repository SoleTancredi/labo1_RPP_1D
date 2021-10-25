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
#include "Fecha.h"

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
	int iPerro;
	int rtaSeguir;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL && id != NULL)
	{
		i = findEmptyEstadia(arrayEstadia, tam);
		cartelMostrarDuenio();
		mostrarListaDuenios(arrayDuenio, tam);
		if(utn_getNumber(&bufferE.idDuenio, "\n --> SELECCIONE UN DUENIO MEDIANTE ID:  ", "\nError.Reingrese.", 30000, 60000, 1) == 0)
		{
			if(indexByIdDuenio(arrayDuenio, tamD, bufferE.idDuenio,&iDuenio) == 0)
			{
				strcpy(bufferE.nombreDuenio,arrayDuenio[iDuenio].nombre);
				strcpy(bufferE.telefonoContacto,arrayDuenio[iDuenio].telefono);
			}
			else
			{
				printf("\nEl ID ingresado no existe.");
			}
		}
		if(i != -1 && cargarFecha(&bufferE.fechaEstadia) == 0 )
		{
			mostrarListaPerros(arrayPerro, tamP);
			if(utn_getNumber(&bufferE.idPerro, "\n --> SELECCIONE UN PERRO MEDIANTE ID: ", "\nError.Reingrese.", 7000, 10000, 1) == 0)
			{
				if(indexByIdPerro(arrayPerro, tamP,bufferE.idPerro, &iPerro) == 0)
				{
				    bufferE.id = *id;
                    cartelVistaPrevia();
                    mostrarUnidadEstadia(bufferE,arrayPerro[iPerro], arrayDuenio[iDuenio]);
                    if(utn_getNumber(&rtaSeguir,"\n » DESEA CARGAR LOS DATOS ?"
                    		"\n  [1] SI "
                    		"\n  [2] NO ", "\nError.",1,2, 1) == 0)
                    {
                    	if(rtaSeguir == 1)
                    	{
                    		if(addEstadia(&arrayEstadia[i], id,bufferE.nombreDuenio ,bufferE.telefonoContacto , bufferE.idPerro,bufferE.idDuenio, bufferE.fechaEstadia.dia, bufferE.fechaEstadia.mes, bufferE.fechaEstadia.anio) == 0)
							{
								printf("\n »»» CARGA COMPLETA «««");
								retorno = 0;
							}
                    	}
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
	int iPerro;
	int iDuenio;
	int indicePerro;
	int indiceDuenio;
	int bufferId;
	int rta1;
	int rta2;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL )
	{
		mostrarListaEstadias(arrayEstadia, tam, arrayPerritos, tamPerro, arrayDuenio, tamDuenio);
		if(utn_getNumber(&bufferId, "\n --> SELECCIONE UNA ESTADIA MEDIANTE ID:  "
				,"\n × ERROR. REINGRESE EL ID.\n",100000,150000, 1) == 0 &&
		findByIdEstadia(arrayEstadia, tam, bufferId,&indice) == 0)
		{
			indexByIdPerro(arrayPerritos, tamPerro, arrayEstadia[indice].idPerro, &iPerro);
			indexByIdDuenio(arrayDuenio, tamDuenio, arrayEstadia[indice].idDuenio, &iDuenio);
			cartelEstadiaElegida();
			mostrarUnidadEstadia(arrayEstadia[indice], arrayPerritos[iPerro], arrayDuenio[iDuenio]);
			do
			{
				if(subMenuModifEstadia(arrayEstadia, tam,&option) == 0)
				{
					switch(option)
				{
					case 1:
						printf("\n >> El numero actual es: [%s]\n", arrayEstadia[indice].telefonoContacto);
						if(utn_telephoneNumber(bufferE.telefonoContacto,"\n -> Ingrese nuevo telefono: \n"
								,"\n × Error. Reingrese el numero.", TAM_TEL, 1) == 0)
						{
							printf("\n » Nuevo telefono ingresado: [%s]\n", bufferE.telefonoContacto);
							if(utn_getNumber(&rta1,"\n » CONFIRMAR MODIFICACION ? "
		                    		"\n  [1] SI "
		                    		"\n  [2] NO ", "\n × Error.\n",1,2, 1) == 0)
							{
								if(rta1 == 1)
								{
									strcpy(arrayEstadia[indice].telefonoContacto, bufferE.telefonoContacto);
								}
							}
						}
						else
						{
							printf("\n »» NO SE REALIZO LA MODIFICACION.");
						}
						break;
					case 2:
						mostrarListaPerros(arrayPerritos, tam);
						if(utn_getNumber(&bufferE.idPerro, "\n --> Ingrese nuevo Id de perro. \n"
						, "\n × Error. Reingrese id valido.", 7000, 10000, 1) == 0
						&& indexByIdPerro(arrayPerritos, tam, bufferE.idPerro, &indicePerro) == 0)
						{
							cartelPerroIngresado();
							mostrarUnidadPerro(arrayPerritos[indicePerro]);
							if(utn_getNumber(&rta2,"\n » CONFIRMAR MODIFICACION ? "
		                    		"\n  [1] SI "
		                    		"\n  [2] NO ", "\n × Error.\n",1,2, 1) == 0)
							{
								if(rta2 == 1)
								{
									arrayEstadia[indice].idPerro = bufferE.idPerro;
								}
							}
						}
						break;
					case 3:
						if(rta1 == 1 || rta2 == 1)
						{   // cambios realizados :
							indexByIdDuenio(arrayDuenio, tamDuenio,arrayEstadia[indice].idDuenio, &indiceDuenio);
							cartelEstadiaModificada();
							mostrarUnidadEstadia(arrayEstadia[indice], arrayPerritos[indicePerro], arrayDuenio[indiceDuenio]);
							printf("\n »»» Saliendo al menu principal");
							//system pause
						}
						else
						{
							printf("\n »» NO HUBO CAMBIOS.\n");
							printf("\n »»» Saliendo al menu principal");
							// no hubo modificaciones,saliendo al menu principal...
						}
						break;
				}
				retorno = 0;
			}

			}while(option != 3);
		}


	}

	return retorno;
}

void mostrarPerrosConSusEstadias(Perro* arrayPerro, int tamPerro, EstadiaDiaria* arrayEstadia, int tamEstadia, Duenio* arrayDuenio, int tamDuenio)
{
	int iDuenio;



	if(arrayPerro != NULL && arrayEstadia != NULL)
	{
		for(int i = 0; i < tamPerro; i++)
		{
			cartelMostrarEstadiaPorPerro(arrayPerro[i]);

			for(int j = 0; j < tamEstadia; j++)
			{
				if(arrayPerro[i].id == arrayEstadia[j].idPerro)
				{
					indexByIdDuenio(arrayDuenio, tamDuenio, arrayEstadia[j].idDuenio, &iDuenio);
					mostrarUnidadEstadia(arrayEstadia[j], arrayPerro[i], arrayDuenio[iDuenio]);
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
		printf("   %-10d|   %-15s%-15s %-15s %-14s  %d/%d/%d\n",unaEstadia.id,unaEstadia.nombreDuenio,unaEstadia.telefonoContacto,arrayPerro.nombre,arrayPerro.raza,unaEstadia.fechaEstadia.dia,unaEstadia.fechaEstadia.mes,unaEstadia.fechaEstadia.anio);
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

	printf("\n\t\t\t\t\t\t\t\t\tCantidad de Estadias:%d \n",conteoEstadias);
}

int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arraPerros, int tamPerro, Duenio* arrayDuenio, int tamDuenio)
{
	int retorno = -1;
	int id;
	int indice;
	int indicePerro;
	int indiceDuenio;
	int rta;

	if(arrayEstadia!= NULL)
	{
		printf("\n***** DAR DE BAJA UNA ESTADIA *****\n");

		mostrarListaEstadias(arrayEstadia, tam, arraPerros, tamPerro, arrayDuenio, tamDuenio);

		if( utn_getNumber(&id, "\n --> SELECCIONE UNA ESTADIA MEDIANTE ID : ","\n × ERROR. REINGRESE EL ID."
					, 100000, 150000, 1) == 0 && findByIdEstadia(arrayEstadia, tam, id, &indice) == 0)

		{
			indexByIdPerro(arraPerros, tamPerro, arrayEstadia[indice].idPerro,&indicePerro);
			indexByIdDuenio(arrayDuenio, tamDuenio, arrayEstadia[indice].idDuenio, &indiceDuenio);
			cartelEstadiaElegida();
			mostrarUnidadEstadia(arrayEstadia[indice], arraPerros[indicePerro], arrayDuenio[indiceDuenio]);
			if(utn_getNumber(&rta,"\n » CONFIRMAR BAJA ? "
            		"\n  [1] SI "
            		"\n  [2] NO ", "\n × Error.\n",1,2, 1) == 0)
			{
				if(rta == 1 && eliminarEstadia(&arrayEstadia[indice]) == 0)
				{
					retorno = 0;
				}
			}

		}
	}
	return retorno;
}

void cartelMostrarEstadia()
{

	printf("\n\t\t\t\t## LISTADO DE ESTADIAS ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

void cartelVistaPrevia()
{

	printf("\n\n\t\t\t\t## VISTA PREVIA DE ESTADIA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");

}

void cartelEstadiaElegida()
{
	printf("\n\n\t\t\t\t## ESTADIA ELEGIDA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

void cartelEstadiaModificada()
{
	printf("\n\n\t\t\t\t## ESTADIA MODIFICADA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

void cartelPerroIngresado()
{
	printf("\n\t\t## NUEVO PERRO ELEGIDO ##");
	printf("\n__________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID PERRO ","NOMBRE ","RAZA ","EDAD ");
	printf("__________________________________________________________\n");
}

void cartelMostrarEstadiaPorPerro(Perro unidadPerro)
{

    if(unidadPerro.isEmpty == 1)
    {
    	printf("\n\t\t\t\t ESTADIAS DE »» [%s] «« ", unidadPerro.nombre);
		printf("\n________________________________________________________________________________________________\n");
		printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
		printf("________________________________________________________________________________________________\n");
    }

}

int perroConMasEstadias(EstadiaDiaria* arrayEstadias, int tamE, Perro* arrayPerro, int tamP)
{
	int retorno = -1;
	int contLobo = 0;
	int contSheila = 0;
	int contReina = 0;

	for(int i = 0; i < tamE; i++)
	{
		if(arrayEstadias[i].idPerro == arrayPerro[0].id)
		{
			contLobo++;
		}
		else
		{
			if(arrayEstadias[i].idPerro == arrayPerro[1].id)
			{
				contSheila++;
			}
			else
			{
				if(arrayEstadias[i].idPerro == arrayPerro[2].id)
				{
					contReina++;
				}
			}
		}
	}

	printf("\n >>> CANTIDAD DE ESTADIAS DE CADA PERRITO: \n");
    printf("\n  »»» LOBO   [%d]", contLobo);
    printf("\n  »»» SHEILA [%d]", contSheila);
    printf("\n  »»» REINA  [%d]", contReina);

	if(contLobo > contSheila && contLobo > contReina)
	{
		if(contLobo == contSheila)
		{
			printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Lobo y %s ««««", arrayPerro[1].nombre);
		}
		else
		{
			if(contLobo == contReina)
			{
				printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Lobo y %s ««««", arrayPerro[2].nombre);
			}
			else
			{
				printf("\n\n »»»» EL PERRITO CON MAS ESTADIAS ES LOBO ««««");
			}
		}
	}
	else
	{
		if(contSheila > contLobo && contSheila > contReina)
		{
			if(contSheila == contLobo)
			{
				printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Sheila y %s ««««", arrayPerro[0].nombre);
			}
			else
			{
				if(contSheila == contReina)
				{
					printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Sheila y %s ««««", arrayPerro[2].nombre);
				}
				else
				{
					printf("\n\n »»»» EL PERRITO CON MAS ESTADIAS ES SHEILA ««««");
				}
			}

		}
		else
		{
			if(contReina == contLobo)
			{
				printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Reina y %s ««««", arrayPerro[0].nombre);
			}
			else
			{
				if(contReina == contSheila)
				{
					printf("\n\n »»»» LOS PERRITOS CON MAS ESTADIAS SON: Reina y %s ««««", arrayPerro[1].nombre);
				}
				else
				{
					printf("\n\n »»»» EL PERRITO CON MAS ESTADIAS ES REINA ««««");
				}
			}
		}
	}



	return retorno;
}




