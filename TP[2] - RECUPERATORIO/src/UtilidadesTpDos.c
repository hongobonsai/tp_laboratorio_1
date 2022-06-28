/*
 * UtilidadesTpDos.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */


/** \brief Imprime el menu principal del programa
*
*/
#include "UtilidadesTpDos.h"
int menuPrincipal() {
	int auxOpcionMenuPrincipal;
	printf("\n------| MENU DE OPCIONES |------\n");
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJA");
	printf("\n4. INFORMAR");
	printf("\n5. CARGA FORZADA");
	printf("\n0. EXIT\n");
	printf("\n--------------------------------");

	utn_getNumero(&auxOpcionMenuPrincipal, "", "\nIngrese una opcion valida.", 0, 5, 5);

	return auxOpcionMenuPrincipal;
}

/** \brief Generador de ID autoincremental. Utiliza un valor static. Comienza en 1000
*
* \return Retorna el valor del ID,
*/

int calcularId() {

	static int id = 999;
	id++;
	return id;
}
