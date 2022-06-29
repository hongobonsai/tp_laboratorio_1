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
	printf("\n[1] ALTAS.");
	printf("\n[2] MODIFICAR.");
	printf("\n[3] BAJA");
	printf("\n[4] INFORMAR");
	printf("\n[5] CARGA FORZADA");
	printf("\n[6] EXIT\n");
	printf("\n--------------------------------");

	utn_getNumero(&auxOpcionMenuPrincipal, "", "\n-Ingrese una opcion valida-\n", 1, 6, 0);

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
