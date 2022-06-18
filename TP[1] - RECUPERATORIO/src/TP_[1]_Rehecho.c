/*
 "\n******************************************************************************"
 1. Ingresar Kilómetros: (km= %.2f)
 2. Ingresar Precio de Vuelos: (Aerolíneas= $%.2f, Latam= $%.2f)

 3. Calcular todos los costos:
 a) Tarjeta de débito
 b) Tarjeta de crédito
 c) Bitcoin
 d) Mostrar precio por km
 e) Mostrar diferencia de precio ingresada

 4. Informar Resultados
 5. Carga forzada de datos
 "6. Salir \n******************************************************************************\n");
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "calculos.h"
#include "utilidades.h"

#define PORCENTAJE_INTERES 0.25
#define PORCENTAJE_DESCUENTO -0.10
#define CONVERSION_BITCOIN 4606954.55
int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int opcionSubMenu;

	float kilometrosIngresados = 0;
	float precioVueloAerolineas = 0;
	float precioVueloLatam = 0;

	float kilometrosIngresadosCalculado = 0;
	float precioVueloAerolineasCalculado = 0;
	float precioVueloLatamCalculado = 0;

	float precioTarjetaDebitoAerolineas;
	float precioTarjetaDebitoLatam;
	float precioTarjetaCreditoAerolineas;
	float precioTarjetaCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;

	float diferenciaLatamAerolineas;

	do {
		if ((opcionMenuPrincipal = tp_Uno_MenuPrincipal(kilometrosIngresados,
				precioVueloAerolineas, precioVueloLatam)) != -1) {
			switch (opcionMenuPrincipal) {

			case 1:
				utn_getFloat(&kilometrosIngresados,
						"\nIngrese los kilometros [MINIMO: 100Km, MAXIMO: 20000Km]: ",
						"--INGRESE UNA DISTANCIA VALIDA--\n", 100, 20000, 5);
				break;
			case 2:
				do {
					if (utn_getNumero(&opcionSubMenu,
							"\n[1] Ingresar el precio de vuelo para Aerolineas.\n"
									"[2] Ingresar el precio de vuelo para Latam.\n"
									"[3] Volver al menu principal.\n",
							"--INGRESE UNA OPCION VALIDA--\n", 1, 3, 0)
							== 0) {

						switch (opcionSubMenu) {
						case 1:
							utn_getFloat(&precioVueloAerolineas,
									"\nIngrese el precio de vuelo para Aerolineas [MINIMO: $2000, MAXIMO: $1000000]: ",
									"\n--INGRESE UN PRECIO VALIDO--\n", 2000,
									1000000, 5);
							break;
						case 2:
							utn_getFloat(&precioVueloLatam,
									"\nPor favor ingrese los kilometros [MINIMO: $2000, MAXIMO: $1000000]: ",
									"\n--INGRESE UN PRECIO VALIDO--\n", 2000,
									1000000, 5);
							break;
						}
					}

				} while (opcionSubMenu != 3);
				break;
			case 3:
				if(kilometrosIngresados != 0 && precioVueloAerolineas != 0 && precioVueloLatam != 0){
					calcularInteresYDescuentoEntreFlotantes(precioVueloAerolineas, PORCENTAJE_INTERES, &precioTarjetaCreditoAerolineas);
					calcularInteresYDescuentoEntreFlotantes(precioVueloLatam, PORCENTAJE_INTERES, &precioTarjetaCreditoLatam);
					calcularInteresYDescuentoEntreFlotantes(precioVueloAerolineas, PORCENTAJE_DESCUENTO, &precioTarjetaDebitoAerolineas);
					calcularInteresYDescuentoEntreFlotantes(precioVueloLatam, PORCENTAJE_DESCUENTO, &precioTarjetaDebitoLatam);

					calcularDivisionEntreDosFlotantes(precioVueloAerolineas, CONVERSION_BITCOIN, &precioBitcoinAerolineas);
					calcularDivisionEntreDosFlotantes(precioVueloLatam, CONVERSION_BITCOIN, &precioBitcoinLatam);
					calcularDivisionEntreDosFlotantes(precioVueloAerolineas, kilometrosIngresados, &precioPorKmAerolineas);
					calcularDivisionEntreDosFlotantes(precioVueloLatam, kilometrosIngresados, &precioPorKmLatam);

					utn_ObtenerDiferenciaEntreValores(precioVueloAerolineas, precioVueloLatam, &diferenciaLatamAerolineas);

					kilometrosIngresadosCalculado = kilometrosIngresados;
					precioVueloAerolineasCalculado = precioVueloAerolineas;
					precioVueloLatamCalculado = precioVueloLatam;
					printf("\n-Se realizaron los calculos-\n");
				}else{
					printf("\n-No se puede calcular sin haber ingresado todos los datos-\n");
				}
				break;
			case 4:
				if(kilometrosIngresados != 0 && precioVueloAerolineas != 0 && precioVueloLatam != 0){

					if(kilometrosIngresados == kilometrosIngresadosCalculado && precioVueloAerolineas == precioVueloAerolineasCalculado && precioVueloLatam == precioVueloLatamCalculado){
						tp_Uno_PrintPreciosDelMenu(precioVueloAerolineas, precioVueloLatam, precioTarjetaDebitoAerolineas,
												precioTarjetaDebitoLatam, precioTarjetaCreditoAerolineas,
												precioTarjetaCreditoLatam, precioBitcoinAerolineas,
												precioBitcoinLatam, precioPorKmAerolineas,
												precioPorKmLatam, diferenciaLatamAerolineas);
					} else{
						printf("\n-Se deben calcular los nuevos valores ingresados antes de informar\n");
					}
				}else{
					printf("\n-No se puede informar sin haber ingresado todos los datos-\n");
				}
				break;
			case 5:
				utn_HardcodearTresFloat(7090, 162965,
						159339, &kilometrosIngresados, &precioVueloAerolineas, &precioVueloLatam);
				calcularInteresYDescuentoEntreFlotantes(precioVueloAerolineas, PORCENTAJE_INTERES, &precioTarjetaCreditoAerolineas);
				calcularInteresYDescuentoEntreFlotantes(precioVueloLatam, PORCENTAJE_INTERES, &precioTarjetaCreditoLatam);
				calcularInteresYDescuentoEntreFlotantes(precioVueloAerolineas, PORCENTAJE_DESCUENTO, &precioTarjetaDebitoAerolineas);
				calcularInteresYDescuentoEntreFlotantes(precioVueloLatam, PORCENTAJE_DESCUENTO, &precioTarjetaDebitoLatam);

				calcularDivisionEntreDosFlotantes(precioVueloAerolineas, CONVERSION_BITCOIN, &precioBitcoinAerolineas);
				calcularDivisionEntreDosFlotantes(precioVueloLatam, CONVERSION_BITCOIN, &precioBitcoinLatam);
				calcularDivisionEntreDosFlotantes(precioVueloAerolineas, kilometrosIngresados, &precioPorKmAerolineas);
				calcularDivisionEntreDosFlotantes(precioVueloLatam, kilometrosIngresados, &precioPorKmLatam);

				utn_ObtenerDiferenciaEntreValores(precioVueloAerolineas, precioVueloLatam, &diferenciaLatamAerolineas);

				kilometrosIngresadosCalculado = kilometrosIngresados;
				precioVueloAerolineasCalculado = precioVueloAerolineas;
				precioVueloLatamCalculado = precioVueloLatam;
				break;
			case 6:
				printf("\n--EJECUCION FINALIZADA--\n");
				break;
			}
		}
	} while (opcionMenuPrincipal != 6);

	return EXIT_SUCCESS;

}
