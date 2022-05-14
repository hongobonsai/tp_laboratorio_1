#include "Informes.h"





int sortPassengersByCode(Passenger *pasajeros, Flight *vuelos, int len, int order) {

	int i;
	int estaOrdenado;
	int retorno = -1;

	Passenger auxPass;


	if (pasajeros != NULL && vuelos != NULL && len > 0) {

		if (order == 1) {

			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(pasajeros[i].flycode, pasajeros[i + 1].flycode) > 0) {
						auxPass = pasajeros[i];
						pasajeros[i] = pasajeros[i + 1];
						pasajeros[i + 1] = auxPass;
						estaOrdenado = 0;
					}
					if (vuelos[i].statusFlight != 1 && vuelos[i + 1].statusFlight == 1) {
						auxPass = pasajeros[i];
						pasajeros[i] = pasajeros[i + 1];
						pasajeros[i + 1] = auxPass;
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
					if (stricmp(pasajeros[i].flycode, pasajeros[i + 1].flycode) < 0) {
						auxPass = pasajeros[i];
						pasajeros[i] = pasajeros[i + 1];
						pasajeros[i + 1] = auxPass;
						estaOrdenado = 0;
					}
					if (vuelos[i].statusFlight != 1 && vuelos[i + 1].statusFlight == 1) {
						auxPass = pasajeros[i];
						pasajeros[i] = pasajeros[i + 1];
						pasajeros[i + 1] = auxPass;
						estaOrdenado = 0;
					}
				}

			} while (estaOrdenado == 0);
			retorno = 0;
		}
	}
	return retorno;
}

int printPassengerByCode(Passenger *pasajeros, Flight *vuelos, int len) {

	char tipoChar[15];
	int tipo;
	int estado;
	char estadoChar[9];
	char auxFlycode[10];
	int retorno = -1;
	char tipoCharDos[15];
	int auxIndiceEstado;
	if (pasajeros != NULL && vuelos != NULL && len > 0) {

	printf(
			"\n+-----------------------------------------------------------------------------------------------------------------------+"
			"\n|ID             |FLYCODE        |ESTADO DE VUELO|APELLIDO       |NOMBRE         |PRECIO                 |TIPO           |"
			"\n+---------------+---------------+---------------+---------------+---------------+-----------------------+---------------+");
	for (int i = 0; i < len; i++) {
		if ((pasajeros[i].isEmpty) == 0) {

			tipo = pasajeros[i].typePassenger;

			switch(tipo){

			case 1:
				strcpy(tipoChar, "ECONOMIC");
				printf("entro a 1 economic %s", tipoChar);
				break;
			case 2:
				strcpy(tipoChar, "BUSSINESS");
				printf("entro a 2 buss %s", tipoChar);
				break;
			case 3:
				strcpy(tipoChar, "FIRST CLASS");
				break;
			}
			strcpy(tipoCharDos, tipoChar);

			auxIndiceEstado = findFlightByCode(vuelos, 10, auxFlycode);
			estado = vuelos[auxIndiceEstado].statusFlight;

			switch(estado){

			case 1:
				strcpy(estadoChar, "ACTIVO");
				break;
			case 2:
				strcpy(estadoChar, "DEMORADO");
				break;
			case 3:
				strcpy(estadoChar, "CANCELADO");
				break;
			}
			printf("\n|%-15d|%-15s|%-15s|%-15s|%-15s|%-23.2f|%-12s|"
					"\n+--------------------------------------------"
					"---------------------------------------------------------------------------+",
					pasajeros[i].id, pasajeros[i].flycode, estadoChar, pasajeros[i].lastName, pasajeros[i].name,
					pasajeros[i].price, tipoCharDos);
		}
	}
	return 0;
	}
	return retorno;
}
