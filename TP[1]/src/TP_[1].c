#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_utn.h"
#include "tp_1_library.h"

int main(void) {
	setbuf(stdout, NULL);

	float kilometrosIngresados = 0;
	float precioVueloAerolineas = 0;
	float precioVueloLatam = 0;

	float precioTarjetaDebitoAerolineas;
	float precioTarjetaDebitoLatam;
	float precioTarjetaCreditoAerolineas;
	float precioTarjetaCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;

	float diferenciaLatamAerolineas;

	int flagIngresoKilometros = 0;
	int flagIngresoPrecioAerolineas = 0;
	int flagIngresoPrecioLatam = 0;
	int flagIngresoCargaForzada = 0;
	/*las flag "Dos", son independientes de las anteriores. Permiten
	controlar errores de la Carga Forzada y la opción 4.*/
	int flagIngresoKilometrosDos = 0;
	int flagIngresoPrecioAerolineasDos = 0;
	int flagIngresoPrecioLatamDos = 0;

	int opcionMenuPrincipal;
	int opcionSubMenuInformar;
	int opcionSubMenuPrecios;

	float ultimoKmCalculado = 0;
	float ultimoPrecioAerolineasCalculado = 0;
	float ultimoPrecioLatamCalculado = 0;

	do {
		opcionMenuPrincipal = tp_Uno_MenuPrincipal(kilometrosIngresados,
				precioVueloAerolineas, precioVueloLatam);

		switch (opcionMenuPrincipal) {
		case 1:
			do {
				printf("\nPor Favor, Ingrese kilómetros: \n");
				flagIngresoKilometros = 1;
				scanf("%f", &kilometrosIngresados);
				if (flagIngresoCargaForzada == 1) {
					flagIngresoKilometrosDos = 1;
				}
			} while (kilometrosIngresados <= 0);
			break;
		case 2:
			do {
				do {
					fflush(stdin);
					printf("\nOprima '1' para ingresar el precio de vuelo para Aerolineas.\n"
							"Oprima '2' para ingresar el precio de vuelo para Latam.\n"
							"Oprima '0' para volver al menu principal.\n");
					scanf("%d", &opcionSubMenuPrecios);
					if (opcionSubMenuPrecios != 1 && opcionSubMenuPrecios != 2
							&& opcionSubMenuPrecios != 0) {
						printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
								"¡INGRESE UNA OPCIÓN VÁLIDA!\n"
								"XXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
					}
				} while (opcionSubMenuPrecios != 1 && opcionSubMenuPrecios != 2
						&& opcionSubMenuPrecios != 0);
				if (opcionSubMenuPrecios == 1) {
					do {
						printf("\nIngrese el precio de vuelo para Aerolineas: \n");
						scanf("%f", &precioVueloAerolineas);
						flagIngresoPrecioAerolineas = 1;
						if (flagIngresoCargaForzada == 1) {
							flagIngresoPrecioAerolineasDos = 1;
						}
						if (precioVueloAerolineas <= 0) {
							printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
									"¡INGRESE UNA OPCIÓN VÁLIDA!\n"
									"XXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
						}
					} while (precioVueloAerolineas <= 0);
				} else if (opcionSubMenuPrecios == 2) {
					do {
						printf("\nIngrese el precio de vuelo para Latam: \n");
						scanf("%f", &precioVueloLatam);
						flagIngresoPrecioLatam = 1;
						if (flagIngresoCargaForzada == 1) {
							flagIngresoPrecioLatamDos = 1;
						}
						if (precioVueloLatam <= 0) {
							printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
									"¡INGRESE UNA OPCIÓN VÁLIDA!\n"
									"XXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
						}
					} while (precioVueloLatam <= 0);
				}
			} while (opcionSubMenuPrecios != 0);
			break;
		case 3:
			ultimoKmCalculado = kilometrosIngresados;
			ultimoPrecioAerolineasCalculado = precioVueloAerolineas;
			ultimoPrecioLatamCalculado = precioVueloLatam;

			realizar_calculos:

			utn_RealizarDescuento(precioVueloAerolineas, 0.10, &precioTarjetaDebitoAerolineas);
			utn_RealizarDescuento(precioVueloLatam, 0.10, &precioTarjetaDebitoLatam);
			utn_RealizarInteres(precioVueloAerolineas, 0.25, &precioTarjetaCreditoAerolineas);
			utn_RealizarInteres(precioVueloLatam, 0.25, &precioTarjetaCreditoLatam);
			utn_CalcularConversionValor(precioVueloAerolineas, 4606954.55, &precioBitcoinAerolineas);
			utn_CalcularConversionValor(precioVueloLatam, 4606954.55, &precioBitcoinLatam);
			utn_ValorPorUnidad(kilometrosIngresados, precioVueloAerolineas, &precioPorKmAerolineas);
			utn_ValorPorUnidad(kilometrosIngresados, precioVueloLatam, &precioPorKmLatam);
			utn_ObtenerDiferenciaEntreValores(precioVueloAerolineas, precioVueloLatam, &diferenciaLatamAerolineas);

			if (opcionMenuPrincipal == 5) {
				goto imprimir_calculos; //Jump hacia donde se imprimen los calculos.
			}
			break;
		case 4:
			if (flagIngresoKilometros == 0 || flagIngresoPrecioAerolineas == 0
					|| flagIngresoPrecioLatam == 0) {
				if (flagIngresoCargaForzada == 1) {
					printf("SE REALIZO LA CARGA POR CARGA FORZADA, ");
				}
				do {
					printf("NO SE INGRESARON LOS SIGUIENTES DATOS: \n\n");
					if (flagIngresoKilometros == 0) {
						printf("-Kilometros totales. \n");
					}
					if (flagIngresoPrecioAerolineas == 0) {
						printf("-Precio del viaje por Aerolineas. \n");
					}
					if (flagIngresoPrecioLatam == 0) {
						printf("-Precio del viaje por Latam. \n\n");
					}
					printf("PRESIONE 0 PARA CONTINUAR");
					scanf("%d", &opcionSubMenuInformar);
				} while (opcionSubMenuInformar != 0);
			} else {
				if (flagIngresoKilometrosDos == 1
						&& flagIngresoPrecioAerolineasDos == 1
						&& flagIngresoPrecioLatamDos == 1) {
					flagIngresoCargaForzada = 0;
				}
				if (flagIngresoCargaForzada == 1) {
					printf("Los últimos datos ingresados corresponden a la carga forzada, \n"
							"por favor reingrese los Kilometros y Precios correspondientes.\n");
				} else {
					if (ultimoKmCalculado != kilometrosIngresados
							|| ultimoPrecioAerolineasCalculado != precioVueloAerolineas
							|| ultimoPrecioLatamCalculado != precioVueloLatam) {
						printf("¡SE DEBEN CALCULAR LOS ÚLTIMOS DATOS INGRESADOS ANTES DE INFORMAR!\n");
					} else {
						do {
							imprimir_calculos:
							fflush(stdin);
							tp_Uno_PrintPreciosDelMenu(precioVueloAerolineas,
									precioVueloLatam,
									precioTarjetaDebitoAerolineas,
									precioTarjetaDebitoLatam,
									precioTarjetaCreditoAerolineas,
									precioTarjetaCreditoLatam,
									precioBitcoinAerolineas, precioBitcoinLatam,
									precioPorKmAerolineas, precioPorKmLatam,
									diferenciaLatamAerolineas);
							printf("\n0. Volver al menú principal\n");
							scanf("%d", &opcionSubMenuInformar);
						} while (opcionSubMenuInformar != 0);
					}
				}
				break;
				case 5:
				do {
					if (flagIngresoCargaForzada == 0) {
						flagIngresoCargaForzada = 1;
					}
					flagIngresoKilometrosDos = 0;
					flagIngresoPrecioAerolineasDos = 0;
					flagIngresoPrecioLatamDos = 0;

					utn_HardcodearTresFloat(7090, 162965, 159339,
							&kilometrosIngresados, &precioVueloAerolineas,
							&precioVueloLatam);
					goto realizar_calculos; //Jump hacia donde se realizan los calculos.
				} while (opcionSubMenuInformar != 0);
				break;
				case 6:
				printf("\n|<><><><><><><><><><><><><><><><><><><><><><><><>|\n"
						"|     ADIÓS, EJECUCIÓN DEL T.P.1 FINALIZADA.     |\n"
						"|<><><><><><><><><><><><><><><><><><><><><><><><>|\n");
				break;
			}
		}
	} while (opcionMenuPrincipal != 6);
	return EXIT_SUCCESS;
}
