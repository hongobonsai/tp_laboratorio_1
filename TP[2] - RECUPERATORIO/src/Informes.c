/*
 * Informes.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Hongo
 */

#include "ArrayPassenger.h"
#include "ArrayFlight.h"
#include "Informes.h"
#include "UtilidadesTpDos.h"

/** \brief Imprime el promedio de precio y la cantidad de pasajeros que superan este promedio
 *
* \param list Passenger*
* \param len
* \param *precioTotal Calcula el precio total de los pasajeros ingresados
* \param *promedio Calcula el promedio de precio de los pasajeros ingresados
* \param *superanPromedio Calcula la cantidad de pasajeros cuyo precio sea mayor que el promedio
* \return int
*/
int printAverageAndTotalPricePassenger(Passenger *list, int len) {
	int retorno = -1;
	int contadorPrecios = 0;
	int contadorSuperan = 0;
	float acumuladorPrecios = 0;
	float promedioPrecios = 0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				acumuladorPrecios += list[i].price;
				contadorPrecios++;
			}
		}
		if(acumuladorPrecios > 0){
			promedioPrecios = acumuladorPrecios / contadorPrecios;
			if(promedioPrecios > 0){
				for (int i = 0; i < len; i++) {
					if (list[i].price > promedioPrecios && list[i].isEmpty == 0) {
						contadorSuperan++;
					}
				}
					printf("\n+-------------------------------------------------------+"
							"\n|PRECIO TOTAL   |PRECIO PROMEDIO|MAYORES QUE EL PROMEDIO|"
							"\n+---------------+---------------+-----------------------+");
					printf("\n|%-15.2f|%-15.2f|%-23d|"
							"\n+---------------+---------------+-----------------------+\n",
							acumuladorPrecios, promedioPrecios, contadorSuperan);
				retorno = 0;
			}
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
int printPassengerByCode(Passenger *pasajeros, Flight *vuelos, int lenPasajeros) {

	char tipoChar[15];
	int tipo;
	int estado;
	char estadoChar[15];
	char auxFlycode[10];
	int retorno = -1;
	int auxIndiceEstado;



	if (pasajeros != NULL && vuelos != NULL && lenPasajeros > 0) {

		printf(
				"\n+-----------------------------------------------------------------------------------------------------------------------+"
				"\n|ID             |FLYCODE        |ESTADO DE VUELO|APELLIDO       |NOMBRE         |PRECIO                 |TIPO           |"
				"\n+---------------+---------------+---------------+---------------+---------------+-----------------------+---------------+");
		for (int i = 0; i < lenPasajeros; i++) {
			if (pasajeros[i].isEmpty == 0) {
				strcpy(auxFlycode, pasajeros[i].flycode);
				if((auxIndiceEstado = findFlightByCode(vuelos, lenPasajeros, auxFlycode)) != -1){
					if((estado = vuelos[auxIndiceEstado].statusFlight) == 1){
						tipo = pasajeros[i].typePassenger;

						switch(tipo){
						case 1:
							strcpy(tipoChar, "Economy");
							break;
						case 2:
							strcpy(tipoChar, "Ejecutive");
							break;
						case 3:
							strcpy(tipoChar, "First Class");
							break;
						}
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
						printf("\n|%-15d|%-15s|%-15s|%-15s|%-15s|%-23.2f|%-12s   |"
								"\n+--------------------------------------------"
								"---------------------------------------------------------------------------+",
								pasajeros[i].id, pasajeros[i].flycode, estadoChar, pasajeros[i].lastName, pasajeros[i].name,
								pasajeros[i].price, tipoChar);
					}
				}
			}
		}
		return 0;
	}
	return retorno;
}
/** \brief HARDCODEA valores de usuario a las dos estructuras (VUELOS Y PASAJEROS).
* No elimina los pasajeros ya cargado, respeta la numeracion del ID
*
* \param list Passenger*
* \param list Flight*
* \return int
*/
int hardCodeFivePassenger(Passenger *pasajeros, Flight *vuelos, int lenPasajeros, int lenVuelos){
	int retorno = -1;
	int idAux;

	idAux = calcularId();
	if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, "Jorge", "Perez", 3234.66, 1, "AJYV592") == 0 && addFlight(vuelos, "AJYV592", LEN_VUELOS, 1) == 0){
		idAux = calcularId();
		if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, "Fiorella", "Basualdo", 7665.50, 2, "JITZ305") == 0 && addFlight(vuelos, "JITZ305", LEN_VUELOS, 2) == 0){
			idAux = calcularId();
			if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, "Gandalf", "Mithrandir", 8330.30, 3, "AJYV592") == 0 && addFlight(vuelos, "AJYV592", LEN_VUELOS, 1) == 0){
				idAux = calcularId();
				if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, "Agustin", "Gauna", 4231.66, 1, "TATT744") == 0 &&
				addFlight(vuelos, "TATT744", LEN_VUELOS, 3) == 0){
					idAux = calcularId();
					if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, "Maria Jose", "Rodriguez", 9794.56, 3, "YGWL666") == 0 &&
					addFlight(vuelos, "YGWL666", LEN_VUELOS, 1) == 0){
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}
