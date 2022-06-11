#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Utn.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	int retorno = -1;
	FILE *file;
	if (pArrayListPassenger != NULL && path != NULL) {
		file = fopen(path, "r");
		if (file != NULL) {
			parser_PassengerFromText(file, pArrayListPassenger);
			retorno = 0;
		}
		fclose(file);
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int retorno = -1;
	char auxIdStr[11];
	int auxIdInt;
	Passenger* pPasajeroACrear;
	if (pArrayListPassenger != NULL) {
		printf("\nllega");
		if(parser_LastIdFromText("data_Id.csv", auxIdStr) == 0){
			auxIdInt = atoi(auxIdStr);
			auxIdInt++;
			printf("\n AUX ID INT %d", auxIdInt);
			snprintf(auxIdStr, 11, "%d", auxIdInt);

			pPasajeroACrear = Passenger_pedirDatosYCrearUnPasajero(auxIdStr);
			if (pPasajeroACrear != NULL) {
			}
				if (controller_saveLastId("data_Id.csv", auxIdStr) == 0) {
					retorno = ll_add(pArrayListPassenger, pPasajeroACrear);
			} else{
				free(pPasajeroACrear);
			}
		}
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	int retorno = -1;
	Passenger *punteroAUnPasajero;

	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char flyCode[8];
	int typePassenger;
	char statusFlight[11];

	char typePassengerStr[15];
	int llLen;

	if (pArrayListPassenger != NULL) {
		llLen = ll_len(pArrayListPassenger);
		if (llLen > 0) {
			printf(
					"\nID    NOMBRE    APELLIDO    PRECIO    FLYCODE    TIPO DE PASAJERO    ESTADO DE VUELO\n\n");
			for (int i = 0; i < llLen; i++) {
				punteroAUnPasajero = (Passenger*) ll_get(pArrayListPassenger,
						i);
				Passenger_getAllElements(punteroAUnPasajero, &id, nombre,
						apellido, &precio, flyCode, &typePassenger,
						statusFlight);
				Passenger_IntToTypePassenger(typePassenger, typePassengerStr);
				printf("%d %s %s %f %s %s %s\n", id, nombre, apellido, precio,
						flyCode, typePassengerStr, statusFlight);
				retorno = 0;
			}
		}

	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}
//controller
int controller_saveLastId(char* path, char* idParaAsignar) {
	FILE* pFile;
	int retorno = -1;

	pFile = fopen(path, "w");
	if (pFile != NULL) {
		fprintf(pFile, "%s\n", idParaAsignar);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}
