/*
 * ArrayPassenger.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */


#include "ArrayPassenger.h"

int initPassengers(Passenger *list, int lenght) {
	int Return = -1;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			list[i].isEmpty = 1;
		}
		Return = 0;
	}

	return Return;
}

/** \brief Encuentra un espacio vacio en la estructura pasajeros (espacio vacio = IsEmpty 1).
*
* \param list passenger*
* \param len int
* \return Retorna el lugar disponible (indice)
*/
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

/** \brief agrega en una lista existente de pasajeros los valores recibidos como parámetros
* en la primera posición vacía
*
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Retorna (-1) si hay algun Error [Longitud inválida, puntero NULL o sin
espacio libre] - (0) si está bien.
*/
int addPassenger(Passenger list[], int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[]) {
	int retorno = -1;
	int indiceVacio;
	if (list != NULL && len > 0 && name != NULL && lastName != NULL && price > 0
			&& typePassenger > 0 && flycode != NULL ) {
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
			printf("\n-NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL PASAJERO-");
		}

	}

	return retorno;
}

int removePassenger(Passenger *list, int len, int id) {
	int retorno = -1;
	int passengerIndex;
	if(list != NULL && len > 0 && id >= 1000){
		if ((passengerIndex = findPassengerById(list, len, id)) != -1){
			if (list[passengerIndex].isEmpty == 0) {
				list[passengerIndex].isEmpty = 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int printPassenger(Passenger *list, int len) {

	char tipoChar[12];
	int tipo;
	int retorno = -1;
	if (list != NULL && len > 0) {

	printf("\n+-------------------------------------------------------------------------------------------------------+"
			"\n|ID             |APELLIDO       |NOMBRE         |PRECIO                 |TIPO           |FLYCODE        |"
			"\n+---------------+---------------+---------------+-----------------------+---------------+---------------+");
		for (int i = 0; i < len; i++) {
			if ((list[i].isEmpty) == 0) {
				tipo = list[i].typePassenger;
				switch(tipo){

				case 1:
					strncpy(tipoChar, "Economy", sizeof(tipoChar));
					break;
				case 2:
					strncpy(tipoChar, "Ejecutive", sizeof(tipoChar));
					break;
				case 3:
					strncpy(tipoChar, "First Class", sizeof(tipoChar));
					break;
				}
				printf("\n|%-15d|%-15s|%-15s|%-23.2f|%-15s|%-15s|"
						"\n+-------------------------------------------------------------------------------------------------------+", list[i].id,
						list[i].lastName, list[i].name, list[i].price,
						tipoChar, list[i].flycode);
			}
		}
		return 0;
	}
	return retorno;
}

/** \brief Busca si hay algo cargado en nuestra estructura de pasajeros.
*
* \param list passenger*
* \param len int
* \return Retorna 0 si encuentra algun lugar disponible.
*/
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

/** \brief encuentra un pasajero en la estructura recibiendo su ID
* devuelve la posición del índice en la matriz.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Retorna la posición del índice de pasajeros o (-1) si [Longitud o
Puntero NULL recibido o pasajero no encontrado]
*/
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

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
 */
int sortPassengersByCode(Passenger *list, int len, int order) {
	int retorno;
	int i;
	int estaOrdenado;
	retorno = -1;

	Passenger aux;

	if (list != NULL && len > 0) {
		if (order == 0) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].flycode, list[i + 1].flycode) < 0) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);
			retorno = 0;
		} else if (order == 1) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].flycode, list[i + 1].flycode) > 0) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);
		}
	}

	return retorno;
}
