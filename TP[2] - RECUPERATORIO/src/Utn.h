/*
 * Utn.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef UTN_H_
#define UTN_H_

int utnGetFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
int getFloat(float* pResultado);
int myGets(char* cadena, int longitud);
int esNumericaDecimal(char* cadena);

int isName(char* string);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getString(char* cadena, int longitud);
int getValidWord(char *cadena, char *mensaje, char *mensajeError, int len);
int validateWordChar(char string[]);
int getEspaciosYLetras(char* string, int len, char* mensaje, char* mensajeError, int reintentos);
int isName(char *string);
int getEspaciosYLetras(char *string, int len, char *mensaje, char *mensajeError,
		int reintentos);
int isFlycode(char *string);
int getFlyCode(char *string, int len, char *mensaje, char *mensajeError,
		int reintentos);
#endif /* UTN_H_ */
