/*
 ============================================================================
 Name        : Aux2_TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "Arraypassenger.h"
#include "ArrayFlight.h"
#include "tp_2_library.h"

#define LEN_PASAJEROS 5
#define LEN_VUELOS 5
#define MAXIMO_IDS 5000

int sortPassengers(Passenger *list, int len, int order);

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;

	int opcionSubMenu;
	int validacionSubMenu;
	int indiceSubmenu;

	int opcionInformes;
	char auxFlycode[10]; //COMPARTIDA

	int opcionSubmenuUnoInformes;

	int auxId; //passengers
	int auxTypePassenger;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;

	//informar 2
	float precioTotal;
	float promedioPrecios;
	int cantidadSuperanPromedio;


	Passenger pasajeros[LEN_PASAJEROS];
	Flight vuelos[LEN_VUELOS];

	if ((initPassengers(pasajeros, LEN_PASAJEROS) == 0)
			&& (initFlights(vuelos, LEN_VUELOS)) == 0) {
		do {
			printf("\n*MENU*");
			printf("\n1. ALTAS.");
			printf("\n2. MODIFICAR.");
			printf("\n3. BAJA");
			printf("\n4. INFORMAR");
			printf("\n5. CARGA FORZADA");
			printf("\n6. EXIT\n");

			utn_getNumero(&opcionMenu, "", "\nIngrese una opcion valida.", 1, 6,
					5);

			switch (opcionMenu) {
			case 1:
				printf("\n***ALTAS***\n");
				if ((findEmptySpace(pasajeros, LEN_PASAJEROS)) != -1) {
					getValidWord(auxName,
							"\n\nDATOS DEL PASAJERO:\nIngrese el nombre del pasajero: ",
							"\nIngrese un nombre valido.", 51);
					getValidWord(auxLastName,
							"\nIngrese el apellido del pasajero: ",
							"\nIngrese un apellido valido.", 51);
					getValidFloat(&auxPrice, "\nIngrese el precio del pasaje: ",
							"\nIngrese un precio valido", 8);
					utn_getNumero(&auxTypePassenger,
							"\nIngrese el tipo de pasajero (1- ECONOMIC, "
									"2- BUSSINESS, 3- FIRST CLASS): ",
							"\nIngrese un tipo valido.", 1, 3, 5);

					/*VALIDAR ESTO*/printf(
							"\n\nDATOS DEL VUELO:\nIngrese el codigo de vuelo");
					getString(auxFlycode, 10);

					auxId = calcularId();
					addPassenger(pasajeros, LEN_PASAJEROS, auxId, auxName,
							auxName, auxPrice, auxTypePassenger, auxFlycode);

					addFlight(vuelos, auxFlycode, LEN_VUELOS);

				} else {
					printf(
							"\n NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL PASAJERO.");
				}
				break;

			case 2:
				//modificar
				if (isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0) {
					do {
						printf("\n***MODIFICAR***\n");
						do {
							utn_getNumero(&auxId,
									"\nIngrese el ID del pasajero a modificar",
									"\nIngrese una opcion valida.", 1000,
									MAXIMO_IDS, 5);
							for (int i = 0; i < LEN_PASAJEROS; i++) {

								if (auxId == pasajeros[i].id) {
									validacionSubMenu = 0;
									indiceSubmenu = i;
									break;
								} else {
									validacionSubMenu = 1;
								}
							}
							if (validacionSubMenu == 1) {
								printf("\nEL ID INGRESADO NO EXISTE");
							}
						} while (!(validacionSubMenu == 0));

						utn_getNumero(&opcionSubMenu,
								"\nQue dato desea modificar?\n \n1. Nombre. \n2. Apellido. \n3. Precio."
										"\n4. Tipo de pasajero. \n5. Codigo de vuelo. \n0. EXIT.",
								"\nIngrese una opcion valida.", 0, 6, 5);

						switch (opcionSubMenu) {

						case 1:
							printf("caso 1"); //nombre
							getValidWord(auxName, "\nIngrese el nuevo nombre: ",
									"\nIngrese un nombre valido.", 51);
							strcpy(pasajeros[indiceSubmenu].name, auxName);
							break;
						case 2:
							printf("caso 2"); //apelido
							getValidWord(auxLastName,
									"\nIngrese el nuevo apellido: ",
									"\nIngrese un apellido valido.", 51);
							strcpy(pasajeros[indiceSubmenu].lastName,
									auxLastName);
							break;
						case 3:
							printf("caso 3"); //precio
							getValidFloat(&auxPrice,
									"\nIngrese el nuevo precio del pasaje: ",
									"\nIngrese un precio valido(1- ECONOMIC, "
									"2- BUSSINESS, 3- FIRST CLASS): ", 8);
							pasajeros[indiceSubmenu].price = auxPrice;
							break;
						case 4:
							printf("caso 4"); //tipo de pasajero
							utn_getNumero(&auxTypePassenger,
									"\nIngrese el nuevo tipo de pasajero: ",
									"\nIngrese un tipo valido.", 1, 3, 5);
							pasajeros[indiceSubmenu].typePassenger =
									auxTypePassenger;
							break;
						case 5:
							printf("caso 5"); //codigo de vuelo
							/*VALIDAR ESTO*/
							printf(
									"\n\nDATOS DEL VUELO:\nIngrese nuevo codigo de vuelo");
							getString(auxFlycode, 10);
							strcpy(pasajeros[indiceSubmenu].flycode,
									auxFlycode);
							addFlight(vuelos, auxFlycode, LEN_VUELOS);
							break;
						case 0:
							break;
						}
					} while ((opcionSubMenu != 0));
					break;
				} else {
					printf("\n¡NO HAY PASAJEROS INGRESADOS!");
					break;
				}
			case 3:
				if (isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0) {
				printf("\n***BAJA***\n");
				utn_getNumero(&auxId,
						"\n Ingrese el ID del usuario a dar de baja: ",
						"\nIngrese un dato valido.", 999, MAXIMO_IDS, 5);
				removePassenger(pasajeros, LEN_PASAJEROS, auxId);
				break;
				} else{
					printf("\n¡NO HAY PASAJEROS INGRESADOS!");
										break;
				}
			case 4:
				if (isThereAnyPassenger(pasajeros, LEN_PASAJEROS) == 0) {
				do {
					utn_getNumero(&opcionInformes,
							"\n*INFORMAR*"
									"\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
									"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
									"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
									"\n0. EXIT", "Ingrese una opcion valida", 0,
							3, 5);

					switch (opcionInformes) {
					case 1:
						//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
						utn_getNumero(&opcionSubmenuUnoInformes,
							"\n*INFORMAR*"
							"\n1. Ingrese 1 para ordenar de forma ascendente, 0 de forma descendente.",
							"Ingrese una opcion valida", 0, 1, 5);
						sortPassengers(pasajeros, LEN_PASAJEROS, opcionSubmenuUnoInformes);
						printPassenger(pasajeros, LEN_PASAJEROS);
						break;
					case 2:
						averageAndTotalPricePassenger(pasajeros, LEN_PASAJEROS, &precioTotal, &promedioPrecios, &cantidadSuperanPromedio);
						printf("\ntotal: %.2f prom: %.2f", precioTotal, promedioPrecios);

						printf("\n+-------------------------------------------------------+"
								"\n|TOTAL          |PROMEDIO       |MAYORES QUE EL PROMEDIO|"
								"\n+---------------+---------------+-----------------------+");
						printf("\n|%-15.2f|%-15.2f|%-23d|"
								"\n+---------------+---------------+-----------------------+", precioTotal, promedioPrecios, cantidadSuperanPromedio);
					//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
						break;
					case 3:
						break;
					case 0:
						break;
					}

				} while (opcionInformes != 0);
				break;
				} else{
					printf("\n¡NO HAY PASAJEROS INGRESADOS!");
										break;
				}

			case 5:
				for (int i = 0; i < 5; i++) {
					printf("\nPASAJEROS:"
							"\nid= %d"
							"\nnombre: %s"
							"\napellido: %s"
							"\nprecio: %.2f"
							"\ncodigo de vuelo: %s "
							"\ntipo de pasajero: %d"
							"\nestavacio: %d\n", pasajeros[i].id,
							pasajeros[i].name, pasajeros[i].lastName,
							pasajeros[i].price, pasajeros[i].flycode,
							pasajeros[i].typePassenger, pasajeros[i].isEmpty);

					printf("\nVUELOS:"
							"\ncodigo de vuelo:%s"
							"\nestado de vuelo: %d", vuelos[i].flycode,
							vuelos[i].statusFlight);
				}
				break;
			case 6:
				printf("\nSalio");
				break;
			}
		} while (opcionMenu != 6);
	}
	return EXIT_SUCCESS;
}
