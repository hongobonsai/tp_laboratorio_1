/*
 * ArrayFlight.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */


#include "ArrayFlight.h"

int initFlights(Flight list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief agrega en la primera posición vacía de una lista existente
*  de vuelos los valores recibidos como parámetros
*
* \param list flight*
* \param auxFlycode[] char
* \param len int
* \return int Retorna (-1) si hay algun Error [Longitud inválida, puntero NULL o sin
espacio libre] - (0) si está bien.
*/
int addFlight(Flight *list, char auxFlycode[], int len, int statusFlight) {
	int auxIndiceVacio;
	int validacion = 0;
	int auxStatusFlight = statusFlight;
	int retorno = -1;
	if (list != NULL && len > 0 && auxFlycode != NULL && statusFlight > 0) {
		for (int i = 0; i < len; i++) {
			if(list[i].isEmpty == 0){
				if (stricmp(auxFlycode, list[i].flycode) == 0) {
					printf("\n-Este codigo ya existe. Se actualizara el estado del vuelo-\n");
					list[i].statusFlight = auxStatusFlight;
					validacion = 1;
					retorno = 0;
					break;
				}
			}
		}
		if (validacion == 0) {
			printf("\n-Se cargó el nuevo codigo de vuelo-\n");
			auxIndiceVacio = findEmptyFlight(list, len);
			strncpy(list[auxIndiceVacio].flycode, auxFlycode, sizeof(list[auxIndiceVacio].flycode));
			list[auxIndiceVacio].statusFlight = auxStatusFlight;
			list[auxIndiceVacio].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Encuentra un espacio vacio en la estructura vuelos (espacio vacio = IsEmpty 1).
*
* \param list flight*
* \param len int
* \return Retorna el lugar disponible (indice)
*/
int findEmptyFlight(Flight list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Busca si existen estado de vuelos activos en nuestra esctructura vuelos
*
* \param list passenger*
* \param len int
* \return Retorna 0 si encuentra algun lugar disponible.
*/
int isThereAnyActiveFlight(Flight list[], int len) {
	int retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0 && list[i].statusFlight == 1) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** \brief encuentra un vuelo en la estructura recibiendo su flycode
* devuelve la posición del índice en la matriz.
*
* \param list flight*
* \param len int
* \param id int
* \return Retorna la posición del índice de vuelos o (-1) si [Longitud o
Puntero NULL recibido o pasajero no encontrado]
*/
int findFlightByCode(Flight *list, int len, char flycode[]) {
	int retorno = -1;
	if (list != NULL && len > 0 && flycode != NULL) {
		for (int i = 0; i < len; i++) {
			if ((strcmp(list[i].flycode, flycode)) == 0 && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	} else {
		printf("El codigo de vuelo no esta cargado.");
	}
	return retorno;
}
