/*
 * ArrayFlight.c
 *
 *  Created on: 13 may. 2022
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

int addFlight(Flight *list, char auxFlycode[], int len) {
	int auxIndiceVacio;
	int validacion = 0;
	int auxStatusFlight;

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
			break;
		}
	}
	if (validacion == 0) {
		printf("\nSe cargó el nuevo codigo de vuelo");
		auxIndiceVacio = findEmptyFlight(list, len);
		strcpy(list[auxIndiceVacio].flycode, auxFlycode);
		utn_getNumero(&auxStatusFlight,
							"\nIngrese el estado del vuelo (1- ACTIVO, "
									"2- DEMORADO, 3- CANCELADO): ",
							"\nIngrese un estado valido.", 1, 3, 5);
		list[auxIndiceVacio].statusFlight = auxStatusFlight;
		list[auxIndiceVacio].isEmpty = 0;
	}
	return 0;
}



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

int findFlightByCode(Flight *list, int len, char flycode[]) {
	int retorno = -1;
	if (list != NULL && len > 0 && flycode != NULL) {
		for (int i = 0; i < len; i++) {
			if (list[i].flycode == flycode && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	} else {
		printf("El codigo de vuelo no esta cargado.");
	}
	return retorno;
}
