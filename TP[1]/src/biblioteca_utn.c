/*
 * biblioteca_utn.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Hongo
 */

#include "biblioteca_utn.h"


/// @brief Realiza un descuento a un flotante, y devuelve el resultado por puntero.
/// @param numero: Trae el flotante a realizar el descuento.
/// @param porcentajeDescuento: Trae el porcentaje (1 = 100%, 0.5 = 50%, 0.0 = 5%, etc)
/// @param *numeroConDescuento: Devuelve el resultado por puntero.
/// @return Retorna 0 si finalizó la función.
int utn_RealizarDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento) {
	float valorDescuento;
	valorDescuento = numero * porcentajeDescuento;
	*numeroConDescuento = numero - valorDescuento;

	return 0;
}
/// @brief Realiza un interes a un flotante, y devuelve el resultado por puntero.
/// @param numero: Trae el flotante a realizar el interes.
/// @param porcentajeInteres: Trae el interes (1 = 100%, 0.5 = 50%, 0.0 = 5%, etc)
/// @param *numeroConInteres: Devuelve el resultado por puntero.
/// @return Retorna 0 si finalizó la función.
int utn_RealizarInteres(float numero, float porcentajeInteres, float *numeroConInteres) {
	float valorInteres;
	valorInteres = numero * porcentajeInteres;
	*numeroConInteres = numero + valorInteres;

	return 0;
}
/// @brief Realiza una conversión de un valor inicial a otro cualquiera (Puede ser un valor monetario,
/// 		medidas, cualquier conversión mientras se tenga la relación 1/1 entre valores.
/// 		Devuelve por puntero.
/// @param valorInicial: Trae el valor que se desea convertir.
/// @param relacionConversion: Trae la relación 1/x entre el valor principal y el valor a convertir.
/// 		(EJEMPLO: Si se desean convertir 350 pesos a dolares, en valorInicial introducimos 350, y en
/// 		relacionConversion introducimos 113.99 (Que es el valor de cada dolar en pesos).
/// @param *valorConvertido: Devuelve el resultado por puntero.
/// @return Retorna 0 si finalizó la función.
int utn_CalcularConversionValor(float valorInicial, float relacionConversion, float *valorConvertido){

	*valorConvertido = valorInicial / relacionConversion;


	return 0;
}
/// @brief Calcula el valor de una unidad en un conjunto de unidades, que entre sí valen "n".
/// 		Realiza "n/q" (Valor del conjunto sobre cantidad de unidades). (TENIENDO EN CUENTA QUE
/// 		LA DIVISIÓN ENTRE UNIDADES ES HOMOGÉNEA SOBRE EL TOTAL). Devuelve por puntero.
/// @param cantidadUnidades: Trae la cantidad de unidades dentro del total.
/// @param valorTotal: Trae el valor total.
/// @param *valorPorUnidad: Devuelve el valor individual de cada una de las unidades ingresadas.
/// @return Retorna 0 si finalizó la función.
int utn_ValorPorUnidad(float cantidadUnidades, float valorTotal, float *valorPorUnidad){

	*valorPorUnidad = valorTotal / cantidadUnidades;

	return 0;

}
/// @brief Calcula la diferencia entre dos valores y devuelve el resultado por puntero.
/// @param primerValor: Trae el primer valor a calcular.
/// @param segundoValor: Trae el segundo valor a calcular.
/// @param *valorDiferencia: Devuelve la diferencia entre los dos valores por puntero.
/// @return Retorna 0 si finalizó la función.
int utn_ObtenerDiferenciaEntreValores(float primerValor, float segundoValor, float *valorDiferencia){

	if (primerValor >= segundoValor){
		*valorDiferencia = primerValor - segundoValor;
	} else {
		*valorDiferencia = segundoValor - primerValor;
	}
	return 0;
}
/// @brief Asigna de manera forzada un valor especifico a 3 variables flotantes.
/// @param valorUno:  Trae el valor a asignar a varUno.
/// @param valorDos:  Trae el valor a asignar a varDos.
/// @param valorTres: Trae el valor a asignar a varTres.
/// @param *varUno:  Asigna por puntero el primer valor ingresado a una variable de nuestro programa.
/// @param *varDos:  Asigna por puntero el segundo valor ingresado a una variable de nuestro programa.
/// @param *varTres: Asigna por puntero el tercer valor ingresado a una variable de nuestro programa.
/// @return Retorna 0 si finalizó la función.
int utn_HardcodearTresFloat(float valorUno, float valorDos,
		float valorTres, float *varUno, float *varDos, float *varTres){

	*varUno = valorUno;
	*varDos = valorDos;
	*varTres = valorTres;

	return 0;
}
