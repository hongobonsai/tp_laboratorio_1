/*
 * inputs.c
 *
 *  Created on: 5 jun. 2022
 *      Author: Hongo
 */
#include "inputs.h"

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

int printMenuPrincipal(){

		int auxOpcionMenuPrincipal;
		printf("\n*MENU*");
		printf("\n[1] Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)");
		printf("\n[2] Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)");
		printf("\n[3] Alta de pasajero");
		printf("\n[4] Modificar datos de pasajero");
		printf("\n[5] Baja de pasajero");
		printf("\n[6] Listar pasajeros");
		printf("\n[7] Ordenar pasajeros");
		printf("\n[8] Guardar los datos de los pasajeros en el archivo data.csv (modo texto)");
		printf("\n[9] Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
		printf("\n[10] Salir");

		utn_getNumero(&auxOpcionMenuPrincipal, "", "\nIngrese una opcion valida.", 1, 10, 5);

		return auxOpcionMenuPrincipal;

}
