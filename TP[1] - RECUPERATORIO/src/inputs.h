/*
 * inputs.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Hongo
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

int getInt(int *pResultado);

int esNumerica(char *cadena, int limite);

int getString(char *cadena, int longitud);

int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);

int getFloat(float* pResultado);

int esNumericaDecimal(char* cadena);

#endif /* INPUTS_H_ */
