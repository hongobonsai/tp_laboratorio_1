/*
 * Utn.h
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getString(char* cadena, int longitud);

int getValidInt(int *numero, char *mensaje, char *mensajeError, int len);
int getValidWord(char *cadena, char *mensaje, char *mensajeError, int len);
int getValidFloat(float *numero, char *mensaje, char *mensajeError, int len);
int validateNumberChar(char string[]);
int validateWordChar(char string[]);
int validateFloatChar(char string[]);

int utn_obtenerEntero(int *ingreso, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);

#endif /* UTN_H_ */
