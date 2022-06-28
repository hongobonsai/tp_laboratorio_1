/*
 * Utn.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */


#include "Utn.h"

int esNumerica(char *cadena, int limite);
int getInt(int *pResultado);
int getString(char *cadena, int longitud);

/**
*brief Obtiene un string, Verifica que sean solo espacios o letras A-Z
*
* \param char *string
* \param int len
* \param char *mensaje
* \param char *mensajeError
* \param int reintentos
* \return Devuelve 0 si esta ok, -1 Si fallo
*/
int getEspaciosYLetras(char *string, int len, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -1;
	char bufferString[len];

	if (string != NULL && len > 0) {
		printf("%s", mensaje);
		do {
			if (getString(bufferString, sizeof(bufferString)) == 0
					&& isName(bufferString) == 1) {
				strncpy(string, bufferString, sizeof(bufferString));
				retorno = 0;
				break;

			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s", mensajeError);
				} else {
					printf("\n-Se quedo sin reintentos-\n");
				}
			}
		} while (reintentos > 0);
	}
	return retorno;
}
/**
*brief Verifica si la cadena recibida Es un nombre
*
* * \param char *string
* \return Devuelve 1 si es, 0 si no es
*/
int isName(char *string) { //retorna 1 si es alfa, 0 si no
	int retorno = 1;
	int i = 0;
	int isAlpha;

	if (string != NULL) {
		while (string[i] != '\0') {
			isAlpha = isalpha(string[i]);
			if (isAlpha != 0 || string[i] == ' ') {
				i++;
			} else {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
/**
 * \brief Solicita un numero al usuario, luego de verificar que sea flotante (Que solo contenga numeros, ',' o '.'),
 * devuelve el resultado por parametro
 * \param float *pResultado
 * \param char *pMensaje Es el mensaje a ser mostrado
 * \param char *pMensajeError Es el mensaje de Error a ser mostrado
 * \param int minimo valor minimo
 * \param int maximo valor maximo
 * \param int len Largo maximo del float
 * \return 0 si se obtuvo el numero y -1 si no
 *
 */
int utnGetFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	float buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos>0){
			printf(pMensaje);
			if(getFloat(&buffer)==1){
				if(buffer<=maximo && buffer>=minimo){
					break;
				}
			}
			fflush(stdin);
			reintentos--;
			printf(pMensajeError);
		}
		if(reintentos==0){
			retorno=-1;
		}
		else{
		retorno=0;
		*pResultado = buffer;
		}
	}
	return retorno;
}

/// @brief Verifica si la cadena ingresada es numerica decimal
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return   Retorna 1 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int getFloat(float* pResultado){
	int retorno;
	retorno = -1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer)) ==0 && esNumericaDecimal(buffer)==1){
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

/// @brief Verifica si la cadena ingresada es flotante
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
int esNumericaDecimal(char* cadena){
	int i = 0;
	int retorno = 1;

	if(cadena != NULL){
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ',' || cadena[i] == '.')
			{
				if(cadena[i] == ','){
					cadena[i]= '.';
				}
				i++;
			}
			else{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
/// * un máximo de 'longitud - 1' caracteres.
///
///
/// @param cadena o Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud Define el tamaño de cadena
/// @return  Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
int myGets(char* cadena, int longitud){
	int retorno;
	retorno =-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
	retorno=0;
	}

return retorno;
}

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
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	do {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);

	return retorno;
}
/**
 *brief Utiliza las funciones getString y esNumerica, para obtener y validar
 *brief una cadena como numero respectivamente, si salio ok,
 *brief transforma la cadena en un entero.
 *
 * * \param *cadena
 * * \param *limite
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];
	if (pResultado != NULL && getString(bufferString, sizeof(bufferString)) == 0
			&& esNumerica(bufferString, sizeof(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);

	}
	return retorno;
}

/**
 *brief Verifica si la cadena recibida es numerica, si contiene solo
 *brief los caracteres "1 al 9", "+" y "-"
 *
 * * \param *cadena
 * * \param *limite
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int esNumerica(char *cadena, int limite) {
	int retorno = -1; // ERROR
	int i;
	if (cadena != NULL && limite > 0) {
		retorno = 1; // VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/**
 *brief Obtiene un string, reemplaza los caracteres correspondientes
 *brief al enter si los encuentra, y los reemplaza con el caracter terminante
 *brief de la cadena
 *
 * * \param *cadena
 * * \param *longitud
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int getString(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096];
	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}


/** \brief Valida si el string recibido es una palabra A-Z, a-z
 *
 * \param string
 * \return Devuelve 0 si es una palabra, 1 Si no lo es.
 */
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
/** \brief Obtiene un string, y valida si el string recibido es una palabra A-Z, a-z
 *
 * \param *cadena puntero a string
 * * \param *mensaje Recibe el mensaje a mostrar cuando se obtiene el dato
 * * \param *mensajeError Recibe el mensaje de error para cuando no es un dato valido
 * * \param len
 * \return Devuelve 0 si esta ok, -1 Si no pudo obtener el string
 */
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

/**
*brief Verifica si la cadena recibida Es un Flycode
*
* * \param char *string
* \return Devuelve 1 si es, 0 si no es
*/
int isFlycode(char *string) { // retorna 1 si es flycode, 0 si no
	int retorno = 1;
	int i = 0;
	int isAlpha;
	int isDigit;

	if (string != NULL) {
		while (string[i] != '\0') {
			isAlpha = isalpha(string[i]);
			isDigit = isdigit(string[i]);
			if ((isAlpha != 0 || isDigit != 0) && strlen(string) == 7) {
				i++;
			} else {
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = -1;
	}

	return retorno;
}
/**
*brief Obtiene un Flycode, convierte a mayusculas todas las letras, lo devuelve por parametro
*
* \param char *string
* \param int len
* \param char *mensaje
* \param char *mensajeError
* \param int reintentos
* \return Devuelve 0 si OK, -1 si fallo
*/
int getFlyCode(char *string, int len, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -1;
	char flyCodeStr[len];

	if (string != NULL && mensaje != NULL && mensajeError != NULL && len > 0) {
		do {
			printf("%s", mensaje);
			if (getString(flyCodeStr, sizeof(flyCodeStr)) == 0
					&& isFlycode(flyCodeStr) == 1) {
				for(int i = 0; i < strlen(flyCodeStr); i++){
						flyCodeStr[i] = toupper(flyCodeStr[i]);
				}
				strcpy(string, flyCodeStr);
				retorno = 0;
				break;

			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s", mensajeError);
				} else {
					printf("\n-Se quedo sin reintentos-\n");
				}
			}
		} while (reintentos > 0);
	}
	return retorno;
}
