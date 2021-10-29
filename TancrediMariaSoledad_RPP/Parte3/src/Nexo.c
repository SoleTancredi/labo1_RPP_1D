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
#include "EstadiaDiaria.h"
#include "Perros.h"
#include "Duenio.h"
#include "Fecha.h"
#include "Inputs.h"

/**
 * @fn int altaEstadia(EstadiaDiaria*, int, int*, Perro*, int, Duenio*, int)
 * @brief toma por parametro los arrays de la 3 estructuras y sus tamaños, va pidiendo los datos
 * correspondientes a los campos que se necesiten para dar de alta una nueva estadia
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @param arrayPerro
 * @param tamP
 * @param arrayDuenio
 * @param tamD
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
		if(utn_getNumber(&bufferE.idDuenio, "\n --> SELECCIONE UN DUENIO MEDIANTE ID:  ", "\n × ERROR.Reingrese.", 30000, 60000, 1) == 0)
		{
			if(indexByIdDuenio(arrayDuenio, tamD, bufferE.idDuenio,&iDuenio) == 0)
			{
				strcpy(bufferE.nombreDuenio,arrayDuenio[iDuenio].nombre);
				strcpy(bufferE.telefonoContacto,arrayDuenio[iDuenio].telefono);
				if(i != -1 && cargarFecha(&bufferE.fechaEstadia) == 0 )
				{
					mostrarListaPerros(arrayPerro, tamP);
					if(utn_getNumber(&bufferE.idPerro, "\n --> SELECCIONE UN PERRO MEDIANTE ID: ", "\n × ERROR.Reingrese.", 7000, 10000, 1) == 0)
					{
						if(indexByIdPerro(arrayPerro, tamP,bufferE.idPerro, &iPerro) == 0)
						{
							bufferE.id = *id;
							bufferE.isEmpty=1;
							cartelVistaPrevia();
							mostrarUnidadEstadia(bufferE,arrayPerro[iPerro], arrayDuenio[iDuenio]);
							if(utn_getNumber(&rtaSeguir,"\n » DESEA CARGAR LOS DATOS ?"
									"\n  [1] SI "
									"\n  [2] NO ", "\n × ERROR.",1,2, 1) == 0)
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
							printf("\n »» El ID ingresado no existe.");
						}
					}
			}
			else
			{
				printf("\n »» El ID ingresado no existe.");
			}

		}

		}
	}
	return retorno;
}

/**
 * @fn int modificarEstadia(EstadiaDiaria*, int, Perro*, int, Duenio*, int)
 * @brief recibe por parametro los arrays de las 3 estructuras y sus tamaños, va modificando
 * los datos que el usuario solicite
 *
 * @param arrayEstadia
 * @param tam
 * @param arrayPerritos
 * @param tamPerro
 * @param arrayDuenio
 * @param tamDuenio
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
						{
							indexByIdDuenio(arrayDuenio, tamDuenio,arrayEstadia[indice].idDuenio, &indiceDuenio);
							cartelEstadiaModificada();
							mostrarUnidadEstadia(arrayEstadia[indice], arrayPerritos[indicePerro], arrayDuenio[indiceDuenio]);
							printf("\n »»» Saliendo...");
						}
						else
						{
							printf("\n »» NO HUBO CAMBIOS.\n");
							printf("\n »»» Saliendo...");
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

/**
 * @fn void mostrarPerrosConSusEstadias(Perro*, int, EstadiaDiaria*, int, Duenio*, int)
 * @brief muestra las estadias pertenecientes a cada perro, mostrando primero su nombre y debajo
 * cada estadia que fue reservada en su nombre, si no posee estadias reservadas el perro no se muestra
 *
 * @param arrayPerro
 * @param tamPerro
 * @param arrayEstadia
 * @param tamEstadia
 * @param arrayDuenio
 * @param tamDuenio
 */
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


/**
 * @fn int mostrarUnidadEstadia(EstadiaDiaria, Perro, Duenio)
 * @brief muestra una sola estadia
 *
 * @param unaEstadia
 * @param arrayPerro
 * @param arrayDuenio
 * @return
 */
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

/**
 * @fn void mostrarListaEstadias(EstadiaDiaria*, int, Perro*, int, Duenio*, int)
 * @brief muestra mas de una estadia
 *
 * @param arrayEstadias
 * @param tam
 * @param arrayPerros
 * @param tamPerro
 * @param arrayDuenios
 * @param tamDuenio
 */
void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam, Perro* arrayPerros, int tamPerro, Duenio* arrayDuenios, int tamDuenio)
{
	int conteoEstadias=0;
	int indexPerro;
	int indexDuenio;

	if(arrayEstadias != NULL && arrayPerros != NULL && arrayDuenios != NULL)
	{
		cartelMostrarEstadia();
		for(int i =0; i < tam; i++)
		{
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
}

/**
 * @fn int darDeBajaEstadia(EstadiaDiaria*, int, Perro*, int, Duenio*, int)
 * @brief elimina una estadia solicitada, la misma debe existir para poder ser dada de baja
 *
 * @param arrayEstadia
 * @param tam
 * @param arrayPerros
 * @param tamPerro
 * @param arrayDuenio
 * @param tamDuenio
 * @return
 */
int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerros, int tamPerro, Duenio* arrayDuenio, int tamDuenio)
{
	int retorno = -1;
	int id;
	int indice;
	int indicePerro;
	int indiceDuenio;
	int rta;

	if(arrayEstadia!= NULL && arrayPerros != NULL && arrayDuenio != NULL)
	{
		printf("\n\t\t\t  ***** DAR DE BAJA UNA ESTADIA *****\n");

		mostrarListaEstadias(arrayEstadia, tam, arrayPerros, tamPerro, arrayDuenio, tamDuenio);

		if( utn_getNumber(&id, "\n --> SELECCIONE UNA ESTADIA MEDIANTE ID : ","\n × ERROR. REINGRESE EL ID."
					, 100000, 150000, 1) == 0 && findByIdEstadia(arrayEstadia, tam, id, &indice) == 0)

		{
			indexByIdPerro(arrayPerros, tamPerro, arrayEstadia[indice].idPerro,&indicePerro);
			indexByIdDuenio(arrayDuenio, tamDuenio, arrayEstadia[indice].idDuenio, &indiceDuenio);
			cartelEstadiaElegida();
			mostrarUnidadEstadia(arrayEstadia[indice], arrayPerros[indicePerro], arrayDuenio[indiceDuenio]);
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

/**
 * @fn void cartelMostrarEstadia()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelMostrarEstadia()
{

	printf("\n\t\t\t\t## LISTADO DE ESTADIAS ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

/**
 * @fn void cartelVistaPrevia()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelVistaPrevia()
{
	printf("\n\n\t\t\t\t## VISTA PREVIA DE ESTADIA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

/**
 * @fn void cartelEstadiaElegida()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelEstadiaElegida()
{
	printf("\n\n\t\t\t\t## ESTADIA ELEGIDA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

/**
 * @fn void cartelEstadiaModificada()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelEstadiaModificada()
{
	printf("\n\n\t\t\t\t## ESTADIA MODIFICADA ##");
	printf("\n________________________________________________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
	printf("________________________________________________________________________________________________\n");
}

/**
 * @fn void cartelPerroIngresado()
 * @brief muestra un cartel, con un estilo determinado
 *
 */
void cartelPerroIngresado()
{
	printf("\n\t\t## NUEVO PERRO ELEGIDO ##");
	printf("\n__________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID PERRO ","NOMBRE ","RAZA ","EDAD ");
	printf("__________________________________________________________\n");
}

void cartelVistaPreviaPerroIngresado()
{
	printf("\n\t\t## VISTA PREVIA NUEVO PERRITO ##");
	printf("\n__________________________________________________________\n");
	printf("\n%-15s %-15s %-15s %-15s \n","ID PERRO ","NOMBRE ","RAZA ","EDAD ");
	printf("__________________________________________________________\n");
}

/**
 * @fn void cartelMostrarEstadiaPorPerro(Perro)
 * @brief muestra un cartel, con un estilo determinado
 *
 * @param unidadPerro
 */
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

void cartelMostrarEstadiasLucias(Duenio unidadDuenio)
{
    if(unidadDuenio.isEmpty == 1)
    {
    	printf("\n\t\t\t\t ESTADIAS DE »» [%s] «« ", unidadDuenio.nombre);
		printf("\n________________________________________________________________________________________________\n");
		printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n","ID ESTADIA","NOMBRE DUEÑO"," TEL. CONTACTO "," NOMBRE PERRO","RAZA PERRO","FECHA DE INGRESO");
		printf("________________________________________________________________________________________________\n");
    }

}

/**
 * @fn int perroConMasEstadias(EstadiaDiaria*, int, Perro*, int)
 * @brief muestra la cantidad de estadias por cada perro, y el perro con mayor cantidad de estadias
 * en caso de darse que coincidan dos perros con mayor cantidad de estadias se muestran ambos
 *
 * @param arrayEstadias
 * @param tamE
 * @param arrayPerro
 * @param tamP
 * @return
 */
int perroConMasEstadias(EstadiaDiaria* arrayEstadias, int tamE, Perro* arrayPerro, int tamP)
{
	int retorno = -1;
	int contLobo = 0;
	int contSheila = 0;
	int contReina = 0;

	if(arrayEstadias != NULL && arrayPerro != NULL)
	{
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
		if(contLobo != 0 || contReina!=0|| contSheila!=0)
		{
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
			retorno = 0;

	}

}
	return retorno;
}

void mostrarLuciasConSusEstadias(EstadiaDiaria* arrayEstadias, int tamE, Duenio* arrayDuenios, int tamD, Perro* arrayPerro, int tamP)
{
	//int retorno = -1;
	int iPerro;

	if(arrayEstadias != NULL && arrayDuenios != NULL && arrayPerro != NULL)
	{
		for(int i = 0; i < tamD; i++)
		{
			cartelMostrarEstadiasLucias(arrayDuenios[i]);

            for(int j = 0; j < tamE; j++)
            {
               if(strcmp(arrayDuenios[i].nombre, arrayEstadias[j].nombreDuenio) == 0)
               {
                  indexByIdPerro(arrayPerro, tamP, arrayEstadias[j].idPerro, &iPerro);
                  mostrarUnidadEstadia(arrayEstadias[j], arrayPerro[iPerro], arrayDuenios[i]);

               }

            }
		}
	}

}

int dueniosAlan(EstadiaDiaria* arrayEstadias, int tamE, Duenio* arrayDuenio, int tamD)
{
	int contAlan=0;

	if(arrayEstadias != NULL && arrayDuenio != NULL)
	{
		for(int i = 0; i < tamE; i++)
		{
			if(strcmp(arrayEstadias[i].nombreDuenio, "Alan") == 0)
			{
				contAlan++;
			}
		}
	}
	return contAlan;
}






