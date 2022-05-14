/*
 * Utn.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */

#include "Utn.h"

int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int getString(char* cadena, int longitud);


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

//VALIDA SI SOLO SE INGRESARON DE LA "A" A LA "Z"
int validateWordChar(char string[]) {
	int retorno = -1;
	int i = 0;
	if (string != NULL) {
		if (string[strnlen(string, 50) - 1] == '\n') {
			string[strnlen(string, 50) - 1] = '\0';
		}
		while (string[i] != '\0') {
			if (!(isalpha(string[i]))) {
				retorno = -1;
				break;
			} else {
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}
//OBTIENE UNA PALABRA A/Z VALIDA.
int getValidWord(char *cadena, char *mensaje, char *mensajeError, int len) {
	char auxCadena[len];
	int validacion;
	if (mensaje != NULL && mensajeError != NULL && len > 0) {
		do {
			printf("%s", mensaje);
			fgets(auxCadena, len, stdin);
			if (auxCadena[strnlen(auxCadena, len) - 1] == '\n') {
				auxCadena[strnlen(auxCadena, len) - 1] = '\0';
			}
			if (validateWordChar(auxCadena) == -1) {
				printf("%s", mensajeError);
				fflush(stdin);
				validacion = -1;
			} else {
				validacion = 0;
			}
		} while (validacion == -1);
	}
	strncpy(cadena, auxCadena, len);
	return 0;
}

int getValidFloat(float *numero, char *mensaje, char *mensajeError, int len) {
	char charNumero[len];
	float numeroFinal;
	int validacion;
	if (mensaje != NULL && mensajeError != NULL && len > 0) {
			do {
				printf("%s", mensaje);
				fgets(charNumero, len, stdin);
				if(charNumero[strnlen(charNumero, 50)-1] == '\n'){
					charNumero[strnlen(charNumero, 50)-1] = '\0';
				}
				if (validateFloatChar(charNumero) == -1) {
					printf("%s", mensajeError);
					fflush(stdin);
					validacion = -1;
				} else {
					validacion = 0;
				}
			} while (validacion == -1);
			numeroFinal = atof(charNumero);
		}
		*numero = numeroFinal;
		return 0;
	}

int validateFloatChar(char string[]) {
	int retorno = -1;
	int i = 0;
	int contadorPuntos = 0;
	if (string != NULL) {
		if(string[strnlen(string, 50)-1] == '\n'){
			string[strnlen(string, 50)-1] = '\0';
					}
		while (string[i] != '\0') {
			if (string[i] == '.') {
				contadorPuntos++;
				if (contadorPuntos > 1) {
					retorno = -1;
					break;
				}
			}
			if (!(string[i] >= 48 && string[i] <= 57) && (string[i] != '.')) {
				retorno = -1;
				break;
			} else {
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}

//int validateNumberChar(char string[]) {
//	int retorno = -1;
//	if (string != NULL) {
//		if (string[strnlen(string, 50) - 1] == '\n') {
//					string[strnlen(string, 50) - 1] = '\0';
//				}
//		for (int i = 0; i < strlen(string); i++) {
//			if (!(string[i] >= 48 && string[i] <= 57)
//					|| !(isdigit(string[i]))) {
//				retorno = -1;
//				break;
//			} else {
//				retorno = 0;
//			}
//		}
//	}
//	return retorno;
//
//}
//OBTIENE UN NUMERO ENTERO VALIDO.
//int getValidInt(int *numero, char *mensaje, char *mensajeError, int len) {
//	char charNumero[len];
//	int numeroFinal;
//	int validacion;
//	if (mensaje != NULL && mensajeError != NULL && len > 0) {
//		do {
//			printf("%s", mensaje);
//			fgets(charNumero, len, stdin);
//			if (validateNumberChar(charNumero) == -1) {
//				printf("%s", mensajeError);
//				fflush(stdin);
//				validacion = -1;
//			} else {
//				validacion = 0;
//			}
//		} while (validacion == -1);
//		numeroFinal = atoi(charNumero);
//	}
//	*numero = numeroFinal;
//	return 0;
//}
