/*
 * tp_2_library.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */
#include "Utn.h"

/** \brief Imprime el menu principal del programa
*
*/
int menuPrincipal() {
	int auxOpcionMenuPrincipal;
	printf("\n*MENU*");
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJA");
	printf("\n4. INFORMAR");
	printf("\n5. CARGA FORZADA");
	printf("\n6. EXIT\n");

	utn_getNumero(&auxOpcionMenuPrincipal, "", "\nIngrese una opcion valida.", 1, 6, 5);

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











