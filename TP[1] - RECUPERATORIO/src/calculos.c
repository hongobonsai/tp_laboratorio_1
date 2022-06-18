/*
 * calculos.c
 *
 *  Created on: 15 jun. 2022
 *      Author: Hongo
 */

#include "calculos.h"


/// @brief Realiza un interes o un descuento a un flotante, y devuelve el resultado por puntero.
/// Para realizar un interes, el parametro porcentaje debe ser positivo (EJ: 0.37 = Interes del 37%). Para realizar un descuento,
/// el parametro porcentaje debe ser negativo(EJ: -0.37 = Descuento del 37%).
/// @param numero: Trae el flotante a realizar la operacion.
/// @param porcentaje: Trae el porcentaje de descuento/interes (1 = 100%, 0.5 = 50%, 0.05 = 5%, etc)
/// @param *numeroObtenido: Devuelve el resultado por puntero.
/// @return Retorna 0 si finalizó la función, -1 si falló.

int calcularInteresYDescuentoEntreFlotantes(float numero, float porcentaje, float *numeroObtenido){
	int retorno = -1;
	float valorMultiplicacion;
		if (numero > 0 && numeroObtenido != NULL){
			valorMultiplicacion = numero * (porcentaje);
			*numeroObtenido = numero + (valorMultiplicacion);
			retorno = 0;
		}
	return retorno;
}

/// @brief Realiza la division entre dos flotantes que recibe, devuelve el resultado por puntero.
/// @param dividendo: numero a dividir.
/// @param divisor: numero por el cual se divide.
/// @param *numeroObtenido: Devuelve el resultado por puntero.
/// @return Retorna 0 si finalizó la función, -1 si falló.
int calcularDivisionEntreDosFlotantes(float dividendo, float divisor, float *numeroObtenido){
	int retorno = -1;
	if(dividendo > 0 && divisor > 0 && numeroObtenido != NULL){
		*numeroObtenido = dividendo / divisor;
		retorno = 0;
	}
	return retorno;
}

/// @brief Calcula la diferencia entre dos valores y devuelve el resultado por puntero.
/// @param primerValor: Trae el primer valor a calcular.
/// @param segundoValor: Trae el segundo valor a calcular.
/// @param *valorDiferencia: Devuelve la diferencia entre los dos valores por puntero.
/// @return Retorna 0 si finalizó la función.
int utn_ObtenerDiferenciaEntreValores(float primerValor, float segundoValor, float *valorDiferencia){
	int retorno = -1;
	if(primerValor > 0 && segundoValor > 0 && valorDiferencia != NULL){
		if (primerValor >= segundoValor){
			*valorDiferencia = primerValor - segundoValor;
		} else {
			*valorDiferencia = segundoValor - primerValor;
			retorno = 0;
		}
	}
	return retorno;
}
