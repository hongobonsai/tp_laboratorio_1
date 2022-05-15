/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Hongo
 */

#include "ArrayPassenger.h"

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en VERDADERO en todas las posiciones de la estructura
*
* \param list Passenger* Puntero a la estructura
* \param len Largo del array
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*/
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
	if (list != NULL && len > 0) {
		indiceVacio = findEmptySpace(list, len);
		if (indiceVacio != -1) {
			list[indiceVacio].id = id;
			strncpy(list[indiceVacio].name, name, sizeof(list[indiceVacio].name));
			strncpy(list[indiceVacio].lastName, lastName, sizeof(list[indiceVacio].name));
			list[indiceVacio].price = price;
			list[indiceVacio].typePassenger = typePassenger;
			strncpy(list[indiceVacio].flycode, flycode, sizeof(list[indiceVacio].name));
			list[indiceVacio].isEmpty = 0; //Escribe el empty
			retorno = 0;
		} else {
			printf(
					"\n NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL PASAJERO.");
		}

	}

	return retorno;
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
/** \brief Elimina a un pasajero por ID (pone la flag IsEmpty en 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return Devuelve (-1) si hay un error [Longitud no válida, puntero NULL o si no se puede
encontrar un pasajero] - (0) si está bien
*
*/
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
/** \brief Ordenar los elementos en la matriz de pasajeros, el orden de los argumentos
indicar orden ARRIBA o ABAJO
*
* \param list Passenger*
* \param len int
* \param order int [1] Indica ascendente - [0] Indica descendente
* \return Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*/
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
/** \brief Imprime el contenido de la estructura de pasajeros
 *
* \param list Passenger*
* \param length int
* \return int
*/
int printPassenger(Passenger *list, int len) {

	char tipoChar[12];
	int tipo;
	int retorno = -1;
	if (list != NULL && len > 0) {

	printf(
			"\n+-------------------------------------------------------------------------------------------------------+"
			"\n|ID             |APELLIDO       |NOMBRE         |PRECIO                 |TIPO           |FLYCODE        |"
			"\n+---------------+---------------+---------------+-----------------------+---------------+---------------+");
	for (int i = 0; i < len; i++) {
		if ((list[i].isEmpty) == 0) {

			tipo = list[i].typePassenger;
			switch(tipo){

			case 1:
				strncpy(tipoChar, "ECONOMIC", sizeof(tipoChar));
				break;
			case 2:
				strncpy(tipoChar, "BUSSINESS", sizeof(tipoChar));
				break;
			case 3:
				strncpy(tipoChar, "FIRST CLASS", sizeof(tipoChar));
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
/** \brief Imprime el contenido de la estructura de pasajeros
 *
* \param list Passenger*
* \param len
* \param *precioTotal Calcula el precio total de los pasajeros ingresados
* \param *promedio Calcula el promedio de precio de los pasajeros ingresados
* \param *superanPromedio Calcula la cantidad de pasajeros cuyo precio sea mayor que el promedio
* \return int
*/
int averageAndTotalPricePassenger(Passenger *list, int len, float *precioTotal, float * promedio, int *superanPromedio){
	int retorno = -1;
	int contadorPrecios = 0;
	int contadorSuperan = 0;
	float acumuladorPrecios = 0;
	float auxPromedio;



	if (list != NULL && len > 0) {
	for (int i = 0; i < len; i++) {
			if ((list[i].isEmpty) == 0) {

			acumuladorPrecios += list[i].price;
			contadorPrecios++;
			printf("\n%.3f", list[i].price);
			}
		}
	retorno = 0;
	}
	auxPromedio = acumuladorPrecios / contadorPrecios;
	*precioTotal = acumuladorPrecios;
	*promedio = auxPromedio;

	for (int i = 0; i < len; i++) {
			if (list[i].price > auxPromedio) {
				contadorSuperan++;
			}
		}
	*superanPromedio = contadorSuperan;
	return retorno;
}



