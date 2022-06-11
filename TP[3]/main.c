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
	char floatchar[11];
	int retorno;

	//ACORDARSE QUE FUNCIONA MEDIO PARA EL ORTO. (ROMPEN TODAS LAS FUNCIONES.) PERO HEY, LEVANTA LOS 1000

	LinkedList *listaPasajeros = ll_newLinkedList();
	do {
		option = printMenuPrincipal();
		switch (option) {
		case 1://LISTO
			controller_loadFromText(DATA_CSV, listaPasajeros);
			break;
		case 2:
			controller_loadFromBinary(DATA_BIN, listaPasajeros);
			break;
		case 3://LISTO
			if(controller_addPassenger(listaPasajeros)==0){
				printf("\n-Se agregó al pasajero correctamente-");
			} else{
				printf("\n-No se pudo agregar al pasajero-");
			}
			break;
		case 4:
//			retorno = getValidFloatChar(floatchar,
//								"\nIntroduzca el precio del pasaje del pasajero: ",
//								"\n-Ingrese un precio valido-\n", 8);
//			printf("%d %s", retorno, floatchar);
			controller_editPassenger(listaPasajeros);
			break;
		case 5:
//			for(int i = 0; i <ll_len(listaPasajeros); i++){
//				Passenger* pLinked;
//				pLinked = (Passenger*)ll_get(listaPasajeros, i);
//				printf("espacio LL: %d, %d %s %s %s %f %d %s", i, pLinked->id, pLinked->nombre, pLinked->apellido, pLinked->flyCode, pLinked->precio, pLinked->typePassenger,pLinked->statusFlight);
//			}
			controller_removePassenger(listaPasajeros);
			break;
		case 6:
			controller_ListPassenger(listaPasajeros);
			break;
		case 7:
			controller_sortPassenger(listaPasajeros);
			break;
		case 8:
			controller_saveAsText(DATA_CSV, listaPasajeros);
			break;
		case 9:
			controller_saveAsBinary(DATA_BIN, listaPasajeros);
			break;
		case 10:
			printf("CHAU");
			break;

		}
	} while (option != 10);
	return 0;
}

