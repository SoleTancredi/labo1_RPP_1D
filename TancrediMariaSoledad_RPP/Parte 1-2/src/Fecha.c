/*
 * Fecha.c
 *
 *  Created on: 22 oct. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Fecha.h"
#include "Inputs.h"

int cargarFecha(Fecha* fecha)
{
	int retorno = -1;
	Fecha bufferF;

	printf("\n --> INGRESE LA FECHA DE INGRESO.\n");
	if(utn_getNumber(&bufferF.dia, "\n >> DIA : ", "\n × ERROR. REINGRESE EL DIA.", 1, 31, 1) == 0)
	{
		if(utn_getNumber(&bufferF.mes,"\n >> MES : ", "\n × ERROR. REINGRESE EL MES.", 1, 12, 1) == 0)
		{
			if(utn_getNumber(&bufferF.anio,"\n >> ANIO : ", "\n × ERROR. REINGRESE EL ANIO.", 1990, 2022, 1) == 0)
			{
				*fecha = bufferF;
				retorno = 0;
			}
		}
	}
	return retorno;
}

