#include "Informes.h"




/** \brief Ordena los elementos en la matriz de pasajeros por código de vuelo
*  y estado de vuelo de manera ascendente o descendente.
*
* \param list Passenger*
* \param len int
* \param order [1] Indica ascendente - [0] Indica descendente
*/
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
/** \brief Imprime el contenido de la estructura de pasajeros con codigo de vuelo incluido.
 *
* \param list Passenger*
* \param list Flight*
* \param len int
* \return int
*/
int printPassengerByCode(Passenger *pasajeros, Flight *vuelos, int len) {

	char tipoChar[15];
	int tipo;
	int estado;
	char estadoChar[15];
	char auxFlycode[10];
	int retorno = -1;
	int auxIndiceEstado;



	if (pasajeros != NULL && vuelos != NULL && len > 0) {

	printf(
			"\n+-----------------------------------------------------------------------------------------------------------------------+"
			"\n|ID             |FLYCODE        |ESTADO DE VUELO|APELLIDO       |NOMBRE         |PRECIO                 |TIPO           |"
			"\n+---------------+---------------+---------------+---------------+---------------+-----------------------+---------------+");
	for (int i = 0; i < len; i++) {
		if (pasajeros[i].isEmpty == 0) {

			tipo = pasajeros[i].typePassenger;
			strncpy(auxFlycode, pasajeros[i].flycode, sizeof(auxFlycode));

			switch(tipo){

			case 1:
				strncpy(tipoChar, "ECONOMIC\0", sizeof(tipoChar));
				break;
			case 2:
				strncpy(tipoChar, "BUSSINESS\0", sizeof(tipoChar));
				break;
			case 3:
				strncpy(tipoChar, "FIRST CLASS\0", sizeof(tipoChar));
				break;
			}
			auxIndiceEstado = findFlightByCode(vuelos, len, auxFlycode);
			estado = vuelos[auxIndiceEstado].statusFlight;

			switch(estado){
			case 1:
				strncpy(estadoChar, "ACTIVO\0", sizeof(estadoChar));
				break;
			case 2:
				strncpy(estadoChar, "DEMORADO\0", sizeof(estadoChar));
				break;
			case 3:
				strncpy(estadoChar, "CANCELADO\0", sizeof(estadoChar));
				break;
			}
			printf("\n|%-15d|%-15s|%-15s|%-15s|%-15s|%-23.2f|%-12s   |"
					"\n+--------------------------------------------"
					"---------------------------------------------------------------------------+",
					pasajeros[i].id, pasajeros[i].flycode, estadoChar, pasajeros[i].lastName, pasajeros[i].name,
					pasajeros[i].price, tipoChar);
		}
	}
	return 0;
	}
	return retorno;
}

/** \brief HARDCODEA valores de usuario a las dos estructuras (VUELOS Y PASAJEROS)
* Los carga siempre en los indices del 0 al 9, sin importar si tienen contenido o no.
*
* \param list Passenger*
* \param list Flight*
* \return int
*/
int hardCode(Passenger *pasajeros, Flight *vuelos){

	printf("SE PISARAN LOS DATOS INGRESADOS");
	pasajeros[0].isEmpty = 0;
	vuelos[0].isEmpty = 0;
	pasajeros[0].id = calcularId();
	strcpy(pasajeros[0].name, "Jorge");
	strcpy(pasajeros[0].lastName, "Perez");
	pasajeros[0].price = 43234.66;
	pasajeros[0].typePassenger = 1;

	strcpy(pasajeros[0].flycode, "aaaa0000");
	strcpy(vuelos[0].flycode, "aaaa0000");
	vuelos[0].statusFlight = 1;

	//

	pasajeros[1].isEmpty = 0;
	vuelos[1].isEmpty = 0;
	pasajeros[1].id = calcularId();
	strcpy(pasajeros[1].name, "Gandalf");
	strcpy(pasajeros[1].lastName, "Vejete");
	pasajeros[1].price = 123.123;
	pasajeros[1].typePassenger = 3;

	strcpy(pasajeros[1].flycode, "lord9999");
	strcpy(vuelos[1].flycode, "lord9999");
	vuelos[1].statusFlight = 1;

	//

	pasajeros[2].isEmpty = 0;
	vuelos[2].isEmpty = 0;
	pasajeros[2].id = calcularId();
	strcpy(pasajeros[2].name, "Juana");
	strcpy(pasajeros[2].lastName, "Dearco");
	pasajeros[2].price = 1810.2505;
	pasajeros[2].typePassenger = 1;

	strcpy(pasajeros[2].flycode, "juan4202");
	strcpy(vuelos[2].flycode, "juan4202");
	vuelos[2].statusFlight = 3;

	//

	pasajeros[3].isEmpty = 0;
	vuelos[3].isEmpty = 0;
	pasajeros[3].id = calcularId();
	strcpy(pasajeros[3].name, "Frodo");
	strcpy(pasajeros[3].lastName, "Delanillo");
	pasajeros[3].price = 5307.65;
	pasajeros[3].typePassenger = 2;

	strcpy(pasajeros[3].flycode, "aaaa0000");
	strcpy(vuelos[3].flycode, "aaaa0000");
	vuelos[3].statusFlight = 1;

	//

	pasajeros[4].isEmpty = 0;
	vuelos[4].isEmpty = 0;
	pasajeros[4].id = calcularId();
	strcpy(pasajeros[4].name, "Pablito");
	strcpy(pasajeros[4].lastName, "Lescano");
	pasajeros[4].price = 777.77;
	pasajeros[4].typePassenger = 2;

	strcpy(pasajeros[4].flycode, "cumb1400");
	strcpy(vuelos[4].flycode, "cumb1400");
	vuelos[4].statusFlight = 2;

	//

	pasajeros[5].isEmpty = 0;
	vuelos[5].isEmpty = 0;
	pasajeros[5].id = calcularId();
	strcpy(pasajeros[5].name, "Chuck");
	strcpy(pasajeros[5].lastName, "Schuldiner");
	pasajeros[5].price = 2001.2812;
	pasajeros[5].typePassenger = 3;

	strcpy(pasajeros[5].flycode, "ripp0000");
	strcpy(vuelos[5].flycode, "ripp0000");
	vuelos[5].statusFlight = 3;

	//

	pasajeros[6].isEmpty = 0;
	vuelos[6].isEmpty = 0;
	pasajeros[6].id = calcularId();
	strcpy(pasajeros[6].name, "Jesucristo");
	strcpy(pasajeros[6].lastName, "Salvador");
	pasajeros[6].price = 234.22;
	pasajeros[6].typePassenger = 2;

	strcpy(pasajeros[6].flycode, "godd7777");
	strcpy(vuelos[6].flycode, "godd7777");
	vuelos[6].statusFlight = 1;

	//

	pasajeros[7].isEmpty = 0;
	vuelos[7].isEmpty = 0;
	pasajeros[7].id = calcularId();
	strcpy(pasajeros[7].name, "Roberto");
	strcpy(pasajeros[7].lastName, "Almafuerte");
	pasajeros[7].price = 48881;
	pasajeros[7].typePassenger = 3;

	strcpy(pasajeros[7].flycode, "laHL020");
	strcpy(vuelos[7].flycode, "laHL020");
	vuelos[7].statusFlight = 2;

	//

	pasajeros[9].isEmpty = 0;
	vuelos[9].isEmpty = 0;
	pasajeros[9].id = calcularId();
	strcpy(pasajeros[9].name, "Hijo");
	strcpy(pasajeros[9].lastName, "Delgerente");
	pasajeros[9].price = 9.99;
	pasajeros[9].typePassenger = 3;

	strcpy(pasajeros[9].flycode, "davi1400");
	strcpy(vuelos[9].flycode, "davi1400");
	vuelos[9].statusFlight = 1;

	//

	pasajeros[10].isEmpty = 0;
	vuelos[10].isEmpty = 0;
	pasajeros[10].id = calcularId();
	strcpy(pasajeros[10].name, "Dieguito");
	strcpy(pasajeros[10].lastName, "Maradona");
	pasajeros[10].price = 1010.10;
	pasajeros[10].typePassenger = 3;

	strcpy(pasajeros[10].flycode, "lolo1010");
	strcpy(vuelos[10].flycode, "lolo1010");
	vuelos[10].statusFlight = 3;

	//


	return 0;
}


