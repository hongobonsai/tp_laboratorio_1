#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#include "ArrayPassenger.h"
#include "ArrayFlight.h"
#include "Utn.h"
#include "UtilidadesTpDos.h"
#include "Informes.h"
#define LEN_PASAJEROS 1000
#define LEN_VUELOS 1000
int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int opcionSubmenu;
	int criterioSorting;
	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;
	int statusFlightAux;

	int passengerIndex;

	Passenger pasajeros[LEN_PASAJEROS];
	Flight vuelos[LEN_VUELOS];

	if ((initPassengers(pasajeros, LEN_PASAJEROS) == 0)
			&& (initFlights(vuelos, LEN_VUELOS)) == 0) {

		do {
			fflush(stdin);

			opcionMenu = menuPrincipal();
			switch (opcionMenu) {

			case 1:
				if(findEmptySpace(pasajeros, LEN_PASAJEROS) != -1){
					printf("\n--ALTAS--\n");
					if(getEspaciosYLetras(nameAux, 51, "\nIngrese el nombre del pasajero: ","\n-Ingrese un nombre valido-\n", 3) == 0 &&
						getEspaciosYLetras(lastNameAux, 51, "\nIngrese el apellido del pasajero: ","\n-Ingrese un apellido valido-\n", 3) == 0 &&
						utnGetFloat(&priceAux,"\nIngrese el precio del viaje [Min: 1, Max: 1000000]: ","\n-Ingrese un valor valido-\n", 1, 1000000, 3) == 0 &&
						getFlyCode(flycodeAux, 8, "\nIngrese el codigo de vuelo del pasajero [Alfanumerico maximo 7 digitos]: ", "\n-Ingrese un codigo de vuelo valido-\n", 3) == 0 &&
						utn_getNumero(&typePassengerAux,"\nIngrese el tipo de pasajero [1- EconomyClass, 2- EjecutiveClass, 3- FirstClass]: ","\n-Ingrese una opcion valida-\n", 1,3, 3) == 0 &&
						utn_getNumero(&statusFlightAux,"\nIngrese el estado del vuelo [1- Activo, 2- Demorado, 3- Cancelado]: ","\n-Ingrese una opcion valida-\n", 1,3, 3) == 0){
						idAux = calcularId();
						if(addPassenger(pasajeros, LEN_PASAJEROS, idAux, nameAux,
								lastNameAux, priceAux, typePassengerAux, flycodeAux) == 0){
							if(addFlight(vuelos, flycodeAux, LEN_VUELOS, statusFlightAux) == 0){
								printf("\n-Se cargo al pasajero correctamente-\n");
							} else {
								printf("\n-No se pudo cargar el vuelo-\n");
							}
						} else {
							printf("\n-No se pudo cargar el pasajero-\n");
						}
					} else {
						printf("\n-No se completo la carga de datos. Regresando al menu principal-\n");
					}
				}
				break;
			case 2:
				if(isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0){

					printf("\n--MODIFICACIONES--\n");

					if ((utn_getNumero(&opcionSubmenu, "\n-Desea ver la lista de pasajeros? ([1] Si, [2] No)-", "\n-Ingrese una opcion valida-", 1, 2, 3)) == 0) {
						if (opcionSubmenu == 1) {
							printPassenger(pasajeros, LEN_PASAJEROS);
						}
					} else {
						printf("\n\n-Se acabaron los reintentos, no se mostrara la lista de pasajeros-\n");
					}

					if (utn_getNumero(&idAux,"\n-Ingrese el id del pasajero que desea modificar:-","\n-Por favor, ingrese un id valido-\n", 1000, 10000, 2) == 0) {
						if((passengerIndex = findPassengerById(pasajeros, LEN_PASAJEROS, idAux)) != -1) {
							if(utn_getNumero(&opcionSubmenu, "\nQue dato desea modificar?\n \n[1] Nombre \n[2] Apellido \n[3] Precio""\n[4] Tipo de pasajero "
									"\n[5] Codigo de vuelo \n[0] EXIT", "\n-Ingrese una opcion valida-\n", 0, 5, 3) == 0){

								switch (opcionSubmenu) {
								case 1:
									if(getEspaciosYLetras(nameAux, 51, "\nIngrese el nuevo nombre: ",
											"\n-Ingrese un nombre valido. Al superar los 3 reintentos, se cancelara la modificacion-\n", 3) == 0){
										strcpy(pasajeros[passengerIndex].name, nameAux);
									}
									break;
								case 2:
									if(getEspaciosYLetras(lastNameAux, 51, "\nIngrese el nuevo apellido: ",
											"\n-Ingrese un apellido valido. Al superar los 3 reintentos, se cancelara la modificacion-\n", 3) == 0){
										strcpy(pasajeros[passengerIndex].lastName, lastNameAux);
									}
									break;
								case 3:
									if(utnGetFloat(&priceAux, "\nIngrese el nuevo precio del pasaje: ",
											"\n-Ingrese un precio valido. Al superar los 3 reintentos, se cancelara la modificacion-\n", 1, 1000000, 3) == 0){
										pasajeros[passengerIndex].price = priceAux;
									}
									break;
								case 4:
									if(utn_getNumero(&typePassengerAux, "\nIngrese el nuevo tipo de pasajero: ",
											"\n-Ingrese un tipo valido. Al superar los 3 reintentos, se cancelara la modificacion-\n", 1, 3, 5) == 0){
										pasajeros[passengerIndex].typePassenger =
												typePassengerAux;
									}
									break;
								case 5:
									if(getFlyCode(flycodeAux, 8, "\nIngrese el nuevo codigo de vuelo [Alfanumerico maximo 7 digitos]: ",
											"\n-Ingrese un codigo de vuelo valido. Al superar los 3 reintentos, se cancelara la modificacion-\n", 3) == 0){
										strcpy(pasajeros[passengerIndex].flycode, flycodeAux);
										addFlight(vuelos, flycodeAux, LEN_VUELOS, statusFlightAux);
									}
									break;
								case 0:
									break;
								}
							} else {
								printf("\n-Regresando al menu principal-\n");
							}

						} else {
							printf("\n-El ID ingresado no existe-\n");
						}
					} else {
						printf("\n-Regresando al menu principal-\n");
					}
				} else {
					printf("\n-No se cargo ningun pasajero-\n");
				}
				break;
			case 3:
				if(isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0){

					printf("\n--BAJAS--\n");

					if ((utn_getNumero(&opcionSubmenu, "\n-Desea ver la lista de pasajeros? ([1] Si, [2] No)-", "\n-Ingrese una opcion valida-", 1, 2, 3)) == 0) {
							if (opcionSubmenu == 1) {
								printPassenger(pasajeros, LEN_PASAJEROS);
							}
						} else {
							printf("\n\n-Se acabaron los reintentos, no se mostrara la lista de pasajeros-\n");
						}
					if (utn_getNumero(&idAux,"\n-Ingrese el ID del pasajero que desea eliminar:-","\n-Ingrese un id valido-\n", 1000, 10000, 2) == 0) {
						if((passengerIndex = findPassengerById(pasajeros, LEN_PASAJEROS, idAux)) != -1) {
							if(removePassenger(pasajeros, LEN_PASAJEROS, idAux) == 0){
								printf("\n-Pasajero eliminado correctamente-\n");
							} else {
								printf("\n-No se pudo eliminar al pasajero-\n");
							}
						} else {
							printf("\n-El ID ingresado no existe-\n");
						}
					} else {
						printf("\n-Regresando al menu principal-\n");
					}

				} else {
					printf("\n-No se cargo ningun pasajero-\n");
				}
				break;
			case 4:
				if(isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0){
					if(utn_getNumero(&opcionSubmenu,
							"\n--INFORMES--\n"
							"\n[1] Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
							"\n[2] Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio"
							"\n[3] Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
							"\n[0] EXIT", "Ingrese una opcion valida", 0, 3, 5) == 0){
						switch(opcionSubmenu){

						case 1:
							if(utn_getNumero(&criterioSorting,
									"\n--SORT BY LASTNAME AND TYPE--\n"
									"\nSeleccione un criterio de ordenamiento:"
									"\n[1] Ordenar y listar de forma ascendente"
									"\n[0] Ordenar y listar de forma descendente", "\n-Ingrese un criterio de ordenamiento valido-\n",  0, 1, 3) == 0){
								sortPassengers(pasajeros, LEN_PASAJEROS, criterioSorting);
								printPassenger(pasajeros, LEN_PASAJEROS);
							} else {
								printf("\n-Volviendo al menu principal-\n");
							}
							break;
						case 2:
							if(printAverageAndTotalPricePassenger(pasajeros, LEN_PASAJEROS) != 0){
								printf("\n-No se pudieron imprimir los datos-\n");
							}
							break;
						case 3:
							if(isThereAnyActiveFlight(vuelos, LEN_VUELOS) == 0){
								if(utn_getNumero(&criterioSorting,
										"\n--SORT ACTIVE FLIGHTS BY FLYCODE--\n"
										"\nSeleccione un criterio de ordenamiento:"
										"\n[1] Ordenar y listar de forma ascendente"
										"\n[0] Ordenar y listar de forma descendente", "\n-Ingrese un criterio de ordenamiento valido-\n",  0, 1, 3) == 0){
									sortPassengersByCode(pasajeros, LEN_PASAJEROS, criterioSorting);
									printPassengerByCode(pasajeros, vuelos, LEN_PASAJEROS);
								} else {
									printf("\n-Volviendo al menu principal-\n");
								}
							} else {
								printf("\n-No existen vuelos activos-\n");
							}
							break;
						case 0:
							printf("\n-Volviendo al menu principal-\n");
							break;

						}
					}
				} else {
					printf("\n-No se cargo ningun pasajero-\n");
				}
				break;
			case 5:
				//No sabia que era lo correcto, si solo permitirle al usuario realizar una carga forzada por ejecucion, o que la realice las veces que quiera. En
				//todo caso, deje que lo haga las veces que quiera, pero se repetiran los datos por obvias razones.
				if(utn_getNumero(&opcionSubmenu,
					"\n--HARDCODE FIVE PASSENGER--\n\n¿Desea Hardcodear 5 pasajeros?\n|ATENCION| Si utiliza esta opcion mas de una vez por ejecucion, los pasajeros se duplicaran...\n\n[PRESIONE 1- Si, 0- No]", "\n-Ingrese una opcion valida-\n",  0, 1, 3) == 0){
					if(opcionSubmenu == 1){
						if(hardCodeFivePassenger(pasajeros, vuelos, LEN_PASAJEROS, LEN_VUELOS) == 0){
							printf("\n-SE CARGARON CORRECTAMENTE LOS 5 PASAJEROS-\n");
						} else {
							printf("\n-No se pudieron cargar los 5 pasajeros-\n");
						}
					} else {
						printf("\n-Regresando al menu principal-\n");
					}
				}
				break;
			case 0:
				printf("\n-EJECUCION FINALIZADA-\n");
				break;
			}
		} while (opcionMenu != 0);

	}

}

