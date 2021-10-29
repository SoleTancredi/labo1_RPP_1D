/*
 * nexo.h
 *
 *  Created on: 21 oct. 2021
 *      Author: sole
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "EstadiaDiaria.h"
#include "Perros.h"
#include "Duenio.h"

int altaEstadia(EstadiaDiaria* arrayEstadia, int tam, int* id, Perro* arrayPerro, int tamP, Duenio* arrayDuenio, int tamD);
int modificarEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerritos, int tamPerro, Duenio* arrayDuenio, int tamDuenio);
void mostrarPerrosConSusEstadias(Perro* arrayPerro, int tamPerro, EstadiaDiaria* arrayEstadia, int tamEstadia, Duenio* arrayDuenio, int tamDuenio);
void estadia_listarEstadiaConPerro(EstadiaDiaria estadia,Perro perro);
int estadia_listarEstadiasConPerros(EstadiaDiaria* estadia,int tamEstadia,Perro* perro,int tamPerro);
int mostrarUnidadEstadia(EstadiaDiaria unaEstadia, Perro arrayPerro, Duenio arrayDuenio);
void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam, Perro* arrayPerros, int tamPerro, Duenio* arrayDuenios, int tamDuenio);
int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerros, int tamPerro, Duenio* arrayDuenio, int tamDuenio);
void cartelMostrarEstadia();
void cartelVistaPrevia();
void cartelEstadiaElegida();
void cartelPerroIngresado();
void cartelEstadiaModificada();
void cartelVistaPreviaPerroIngresado();
void cartelMostrarEstadiaPorPerro(Perro unidadPerro);
int perroConMasEstadias(EstadiaDiaria* arrayEstadias, int tamE, Perro* arrayPerro, int tamP);

#endif /* NEXO_H_ */
