/*
 * utilidades.c
 *
 *  Created on: 15 jun. 2022
 *      Author: Hongo
 */


#include "utilidades.h"

#include "inputs.h"

/// @brief FUNCION PROPIA DEL TP, basicamente imprime todos los precios de la
/// 		opción 4 mediante printf.
/// @param Cada uno de los parametros recibe los valores ingresados en menús
/// 		anteriores, y la función los envia al printf.
/// @return Retorna 0 si finalizó la función.
int tp_Uno_PrintPreciosDelMenu(float precioVueloAerolineas,
		float precioVueloLatam, float precioTarjetaDebitoAerolineas,
		float precioTarjetaDebitoLatam, float precioTarjetaCreditoAerolineas,
		float precioTarjetaCreditoLatam, float precioBitcoinAerolineas,
		float precioBitcoinLatam, float precioPorKmAerolineas,
		float precioPorKmLatam, float diferenciaLatamAerolineas) {
	printf("\n   Precio Aerolineas: $%.2f\n"
			"   a) Precio con tarjeta de débito: $%.2f\n"
			"   b) Precio con tarjeta de crédito: $%.2f\n"
			"   c) Precio pagando con bitcoin: %.8f BTC\n"
			"   d) Precio unitario: $%.2f\n\n"
			"   Precio Latam: $%.2f\n"
			"   a) Precio con tarjeta de débito: $%.2f\n"
			"   b) Precio con tarjeta de crédito: $%.2f\n"
			"   c) Precio pagando con bitcoin: %.8f BTC\n"
			"   d) Precio unitario: $%.2f\n\n"
			"   La diferencia de precio es: $%.2f\n\n", precioVueloAerolineas,
			precioTarjetaDebitoAerolineas, precioTarjetaCreditoAerolineas,
			precioBitcoinAerolineas, precioPorKmAerolineas, precioVueloLatam,
			precioTarjetaDebitoLatam, precioTarjetaCreditoLatam,
			precioBitcoinLatam, precioPorKmLatam, diferenciaLatamAerolineas);

	printf("-PRESIONE ENTER PARA CONTINUAR-");
	getchar();
	return 0;
}
/// @brief FUNCION PROPIA DEL TP, basicamente imprime la totalidad del menú principal,
/// 		con los correspondientes valores ingresados
/// @param Cada uno de los parametros recibe los valores ingresados en los menús que
/// 		se encuentran dentro del menú principal, que son impresos por printf.
/// @return Retorna 0 si finalizó la función.
int tp_Uno_MenuPrincipal(float kilometrosIngresados, float precioVueloAerolineas, float precioVueloLatam){
	int auxOpcionMenuPrincipal = -1;
	printf("\n******************************************************************************"
							"\n[1] Ingresar Kilómetros: (km= %.2f)\n\n",
							kilometrosIngresados);

			printf("[2] Ingresar Precio de Vuelos: (Aerolíneas= $%.2f, Latam= $%.2f) \n\n",
					precioVueloAerolineas, precioVueloLatam);

			printf("[3] Calcular todos los costos: \n"
					"   a) Tarjeta de débito\n"
					"   b) Tarjeta de crédito\n"
					"   c) Bitcoin\n"
					"   d) Mostrar precio por km\n"
					"   e) Mostrar diferencia de precio ingresada\n\n");

			printf("[4] Informar Resultados\n");
			printf("[5] Carga forzada de datos \n");
			printf("[6] Salir \n******************************************************************************\n");

			utn_getNumero(&auxOpcionMenuPrincipal, "", "\n--INGRESE UNA OPCION VALIDA--\n",
					1, 6, 0);

	return auxOpcionMenuPrincipal;
}

int utn_HardcodearTresFloat(float valorUno, float valorDos,
		float valorTres, float *pValorUno, float *pValorDos, float *pValorTres){
	int retorno = -1;
	if(pValorUno != NULL && pValorDos != NULL && pValorTres != NULL){
		*pValorUno = valorUno;
		*pValorDos = valorDos;
		*pValorTres = valorTres;
		retorno = 0;
	}
	return retorno;
}
