#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"
#include "parser.h"

#define DATA_BIN "data.bin"
#define DATA_CSV "data.csv"

#define ECONOMY_CLASS 1
#define EXECUTIVE_CLASS 2
#define FIRST_CLASS 3

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int flagCargarAlgo = 0; //0 Para nada cargado, 1 Para Cargado desde add, 2 para Cargado desde archivo
	int flagGuardarAlgo = 0; //0 para nada Guardado, 1 Para Guardado csv, 2 Para Guardaro desde bin
	int llLen;
	int confirmacionExit = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();
	do {
		option = printMenuPrincipal();
		switch (option) {
		case 1: //LISTO
			if (flagCargarAlgo == 0) {
				if (controller_loadFromText(DATA_CSV, listaPasajeros) == 0) {
					flagCargarAlgo = 2;
				}
			} else {
				printf("\nNo se pudo cargar el archivo CSV\n");
			}
			break;
		case 2: //LISTO
			if (flagCargarAlgo == 0) {
				if (controller_loadFromBinary(DATA_BIN, listaPasajeros) == 0) {
					flagCargarAlgo = 2;
				}
			} else {
				printf("\nNo se pudo cargar el archivo BIN\n");
			}
			break;
		case 3: //LISTO
			if (controller_addPassenger(listaPasajeros) == 0) {
				printf("\n-Se agregó al pasajero correctamente-\n");
				flagCargarAlgo = 1;
			} else {
				printf("\n-No se pudo agregar al pasajero-\n");
			}
			break;
		case 4: //LISTO
			if (flagCargarAlgo != 0) {
				if (controller_editPassenger(listaPasajeros) == -1) {
					printf("\n-No se pudo agregar al pasajero-\n");
				}
			} else {
				printf(
						"\n-Debe haber algo cargado para realizar una modificacion!-\n");
			}
			break;
		case 5: //LISTO
			if (flagCargarAlgo != 0) {
				controller_removePassenger(listaPasajeros);
				llLen = ll_isEmpty(listaPasajeros);
			} else {
				printf("\n-Debe haber algo cargado para realizar una baja!-\n");
			}
			if (llLen == 1) {
				printf("\n-La lista de pasajeros ahora se encuentra vacia.-\n");
				flagCargarAlgo = 0;
			}
			break;
		case 6: //LISTO
			if (flagCargarAlgo != 0) {
				controller_ListPassenger(listaPasajeros);
			} else {
				printf("\n-No hay pasajeros cargados en la lista");
			}
			break;
		case 7:
			if (flagCargarAlgo != 0) {
				controller_sortPassenger(listaPasajeros);
			} else {
				printf("\n-No hay pasajeros cargados en la lista");
			}
			break;
		case 8: //LISTO
			if (flagCargarAlgo == 2) {
				controller_saveAsText(DATA_CSV, listaPasajeros);
				controller_saveAsBinary(DATA_BIN, listaPasajeros); //Permite que no esten desfasados los archivos. al guardar uno, se actualiza el otro
				flagGuardarAlgo = 1;
			} else {
				printf(
						"\n-No se puede guardar sin haber cargado antes algun archivo-\n");
			}
			break;
		case 9: //LISTO
			if (flagCargarAlgo == 2) {
				controller_saveAsBinary(DATA_BIN, listaPasajeros);
				controller_saveAsText(DATA_CSV, listaPasajeros); //Permite que no esten desfasados los archivos. al guardar uno, se actualiza el otro
				flagGuardarAlgo = 2;
			} else {
				printf(
						"\n-No se puede guardar sin haber cargado antes algun archivo-\n");
			}
			break;
		case 10:
			if (flagGuardarAlgo == 0) {
				utn_getNumero(&confirmacionExit,
						"\n-¡No se realizó ningun guardado. Se perderan los cambios-\n  Desea Finalizar? ([1]- SI, [2]- NO)",
						"\n-Ingrese una opción valida-", 1, 2, 5);
			} else {
				confirmacionExit = 1;
			}
			break;
		}
	} while (option != 10 || confirmacionExit != 1);
	printf("\n--EJECUCION FINALIZADA--\n");
	ll_deleteLinkedList(listaPasajeros);
	return 0;
}

