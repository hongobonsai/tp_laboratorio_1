#include "inputs.h"


int esNumerica(char *cadena, int limite);
int getInt(int *pResultado);
int getString(char *cadena, int longitud);

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

/**
*brief Utiliza las funciones getFloat y esNumerica, para obtener y validar
*brief una cadena como flotante respectivamente, si salio ok,
*brief transforma la cadena en un entero.
*
* * \param *cadena
* * \param *limite
* \return Devuelve 0 si esta ok, -1 Si fallo
*/
int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
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

/// @brief Obtiene la cadena desde myGets
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return   Retorna 1 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int getFloat(float* pResultado){
	int retorno;
	retorno = -1;
	char buffer[64];

	if(pResultado != NULL){
		if(getString(buffer,sizeof(buffer)) ==0 && esNumericaDecimal(buffer)==1){
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 *brief Verifica si la cadena flotante es numerica y contiene los simbolos "," o "."
 *
 * * \param *cadena
 * * \param *limite
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int esNumericaDecimal(char* cadena){
	int i = 0;
	int retorno = 1;

	if(cadena != NULL){
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ',')
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
