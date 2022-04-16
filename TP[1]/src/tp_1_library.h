/*
 * tp_1_library.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef TP_1_LIBRARY_H_
#define TP_1_LIBRARY_H_

int tp_Uno_PrintPreciosDelMenu(float precioVueloAerolineas,
		float precioVueloLatam, float precioTarjetaDebitoAerolineas,
		float precioTarjetaDebitoLatam, float precioTarjetaCreditoAerolineas,
		float precioTarjetaCreditoLatam, float precioBitcoinAerolineas,
		float precioBitcoinLatam, float precioPorKmAerolineas,
		float precioPorKmLatam, float diferenciaLatamAerolineas);

int tp_Uno_MenuPrincipal(float kilometrosIngresados, float precioVueloAerolineas, float precioVueloLatam);

#endif /* TP_1_LIBRARY_H_ */
