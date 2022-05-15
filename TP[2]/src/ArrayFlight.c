/*
 * ArrayFlight.c
 *
 *  Created on: 13 may. 2022
 *      Author: Hongo
 */

#include "ArrayFlight.h"

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en VERDADERO en todas las posiciones de la estructura
* posición de la matriz
*
* \param list Flight* Puntero a la estructura
* \param len Largo del array
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*/
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
int addFlight(Flight *list, char auxFlycode[], int len) {
	int auxIndiceVacio;
	int validacion = 0;
	int auxStatusFlight;
	int retorno;
	retorno = -1;
	for (int i = 0; i < len; i++) {
		if (stricmp(auxFlycode, list[i].flycode) == 0) {
			printf(
					"\nEste codigo ya existe. Se actualizara el estado del vuelo. ");
			utn_getNumero(&auxStatusFlight,
					"\nIngrese el estado del vuelo (1- ACTIVO, "
							"2- DEMORADO, 3- CANCELADO): ",
					"\nIngrese un estado valido.", 1, 3, 5);
			list[i].statusFlight = auxStatusFlight;
			validacion = 1;
			retorno = 0;
			break;
		}
	}
	if (validacion == 0) {
		printf("\nSe cargó el nuevo codigo de vuelo");
		auxIndiceVacio = findEmptyFlight(list, len);
		strncpy(list[auxIndiceVacio].flycode, auxFlycode, sizeof(list[auxIndiceVacio].flycode));
		utn_getNumero(&auxStatusFlight,
							"\nIngrese el estado del vuelo (1- ACTIVO, "
									"2- DEMORADO, 3- CANCELADO): ",
							"\nIngrese un estado valido.", 1, 3, 5);
		list[auxIndiceVacio].statusFlight = auxStatusFlight;
		list[auxIndiceVacio].isEmpty = 0;
		retorno = 0;
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
