/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Hongo
 */

#include "ArrayPassenger.h"
int initPassengers(Passenger list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int addPassenger(Passenger list[], int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[]) {
	int retorno = -1;
	int indiceVacio;
	if (list != NULL && len > 0) {
		indiceVacio = findEmptySpace(list, len);
		if (indiceVacio != -1) {
			list[indiceVacio].id = id;
			strcpy(list[indiceVacio].name, name);
			strcpy(list[indiceVacio].lastName, lastName);
			list[indiceVacio].price = price;
			list[indiceVacio].typePassenger = typePassenger;
			strcpy(list[indiceVacio].flycode, flycode);
			list[indiceVacio].isEmpty = 0; //Escribe el empty
			retorno = 0;
		} else {
			printf(
					"\n NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL PASAJERO.");
		}

	}

	return retorno;
}

int findEmptySpace(Passenger list[], int len) {
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

int isThereAnyPassenger(Passenger *list, int len) {
	int retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int findPassengerById(Passenger *list, int len, int id) {
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger *list, int len, int id) {
	int retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].id == id && list[i].isEmpty == 0) {
			list[i].isEmpty = 1;
			break;
		}
	}
	return retorno;
}

int sortPassengers(Passenger *list, int len, int order) {

	int i;
	int estaOrdenado;
	int retorno = -1;

	Passenger auxPass;

	if (list != NULL && len > 0) {

		if (order == 1) {

			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].lastName, list[i + 1].lastName) > 0) {
						auxPass = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPass;
						estaOrdenado = 0;
					}
					if (stricmp(list[i].lastName, list[i + 1].lastName) == 0
							&& list[i].typePassenger
									> list[i + 1].typePassenger) {
						auxPass = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPass;
						estaOrdenado = 0;
					}
				}

			} while (estaOrdenado == 0);
			retorno = 0;

		} else if (order == 0) {

			do {

				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].lastName, list[i + 1].lastName) < 0) {
						auxPass = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPass;
						estaOrdenado = 0;
					}
					if (stricmp(list[i].lastName, list[i + 1].lastName) == 0
							&& list[i].typePassenger
									< list[i + 1].typePassenger) {
						auxPass = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPass;
						estaOrdenado = 0;
					}
				}

			} while (estaOrdenado == 0);
			retorno = 0;
		}
	}
	return retorno;
}

int printPassenger(Passenger *list, int len) {

	int retorno = -1;
	if (list != NULL && len > 0) {

	printf(
			"\n+-----------------------------------------------------------------------------------------------+"
			"\n|ID             |APELLIDO       |NOMBRE         |PRECIO         |TIPO           |FLYCODE        |"
			"\n+---------------+---------------+---------------+---------------+---------------+---------------+");
	for (int i = 0; i < len; i++) {
		if ((list[i].isEmpty) == 0) {
//			printf("\n%d %s %s %.2f %d %s", list[i].id, list[i].lastName,
//					list[i].name, list[i].price, list[i].typePassenger,
//					list[i].flycode);
			printf("\n|%-15d|%-15s|%-15s|%-15.2f|%-15d|%-15s|"
					"\n+-----------------------------------------------------------------------------------------------+", list[i].id,
					list[i].lastName, list[i].name, list[i].price,
					list[i].typePassenger, list[i].flycode);
		}
	}
	return 0;
	}
	return retorno;
}

int averagePassengerPrice(Passenger *list, int len){
	int retorno = -1;
	float acumuladorPrecio = 0;


	if (list != NULL && len > 0) {
	for (int i = 0; i < len; i++) {
			if ((list[i].isEmpty) == 0) {

			acumuladorPrecio += list[i].price;

			}
		}
	retorno = 0;
	}
	return retorno;
}



