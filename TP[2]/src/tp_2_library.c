/*
 * tp_2_library.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */

#include "tp_2_library.h"

//MENU
int menuPrincipal() {
	int auxOpcionMenuPrincipal;
	printf("\n1. ALTA DEL ASOCIADO.");
	printf("\n2. MODIFICAR DATOS DEL ASOCIADO.");
	printf("\n3. BAJA DEL ASOCIADO.");
	printf("\n4. NUEVA LLAMADA.");
	printf("\n5. ASIGNAR AMBULANCIA.");
	printf("\n6. INFORMAR.");
	printf("\n7. EXIT.");

	scanf("%d", &auxOpcionMenuPrincipal);

	return auxOpcionMenuPrincipal;
}

//Calcula ID
int calcularId() {

	static int id = 999;
	id++;
	return id;
}











