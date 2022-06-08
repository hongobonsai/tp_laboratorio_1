#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Utn.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger) {

	int retorno = -1;
	Passenger *auxPasajero;

	char idStrFile[51];
	char nombreStrFile[51];
	char apellidoStrFile[51];
	char precioStrFile[8];
	char flyCodeStrFile[8];
	char typePassengerStrFile[15];
	char statusFlightStrFile[2];

	if (pFile != NULL && pArrayListPassenger != NULL) {
		while (!feof(pFile)) {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					idStrFile, nombreStrFile, apellidoStrFile, precioStrFile,
					flyCodeStrFile, typePassengerStrFile, statusFlightStrFile)
					== 7) {
				auxPasajero = Passenger_newParametros(idStrFile, nombreStrFile,
						apellidoStrFile, precioStrFile, flyCodeStrFile,
						typePassengerStrFile, statusFlightStrFile);
				if (ll_add(pArrayListPassenger, auxPasajero) != -1 && esNumericaPositiva(idStrFile) == 0 && isName(nombreStrFile) == 1 && validateFloatChar(precioStrFile) == 0 &&
						isFlycode(flyCodeStrFile) == 1 && isName(typePassengerStrFile) == 1 && esNumericaPositiva(statusFlightStrFile) == 0) {
					retorno = 0;
				} else {
					Passenger_delete(pArrayListPassenger);
				}
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger) {
	int retorno = -1;
	Passenger *auxPasajero;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		while (!feof(pFile)) {
			auxPasajero = Passenger_new();
			fread(auxPasajero, sizeof(Passenger), 1, pFile);
			if (ll_add(pArrayListPassenger, auxPasajero) != -1) {
				retorno = 0;
			} else {
				Passenger_delete(pArrayListPassenger);
			}
		}
	}
	return retorno;
}
