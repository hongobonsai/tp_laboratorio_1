/*
 * biblioteca_utn.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECA_UTN_H_
#define BIBLIOTECA_UTN_H_

int utn_RealizarDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento);

int utn_RealizarInteres(float numero, float porcentajeInteres, float *numeroConInteres);

int utn_CalcularConversionValor(float valorInicial, float relacionConversion, float *valorConvertido);

int utn_ValorPorUnidad(float cantidadUnidades, float valorTotal, float *valorPorUnidad);

int utn_ObtenerDiferenciaEntreValores(float primerValor, float segundoValor, float *valorDiferencia);

int utn_HardcodearTresFloat(float valorUno, float valorDos,
		float valorTres, float *varUno, float *varDos, float *varTres);


#endif /* BIBLIOTECA_UTN_H_ */
