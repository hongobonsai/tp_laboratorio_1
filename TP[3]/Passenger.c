/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

int Passenger_findPassengerById(LinkedList* pArrayListPassenger, int idBuscado){
	int retorno=-1;
	int len;
	int auxId;
	Passenger* punteroUnPasajero=NULL;
	if(pArrayListPassenger!=NULL){
		len=ll_len(pArrayListPassenger);
		for(int i=0;i<len;i++){
			punteroUnPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(punteroUnPasajero, &auxId);
			if(auxId == idBuscado){
				retorno = ll_indexOf(pArrayListPassenger, punteroUnPasajero);
				break;
			}
		}
	}
	return retorno;
}

Passenger* Passenger_pedirDatosYCrearUnPasajero(char *idUnico) {
	char nombreStr[51];
	char apellidoStr[51];
	char precioStr[8];
	char flyCodeStr[8];
	char typePassengerStr[15];
	char statusFlightStr[11];
	Passenger *punteroAUnPasajero = NULL;
	if (getEspaciosYLetras(nombreStr, 51,
			"\nIntroduzca el nombre del pasajero: ",
			"\n-Ingrese un nombre valido-\n", 5) == 0
			&& getEspaciosYLetras(apellidoStr, 51,
					"\nIntroduzca el apellido del pasajero: ",
					"\n-Ingrese un apellido valido-\n", 5) == 0
			&& getValidFloatChar(precioStr,
					"\nIntroduzca el precio del pasaje del pasajero: ",
					"\n-Ingrese un precio valido-\n", 8) == 0
			&& getFlyCode(flyCodeStr, 8,
					"\nIntroduzca el codigo de vuelo del pasajero: ",
					"\n-Ingrese un codigo de vuelo valido-\n", 5) == 0
			&& getTypePassengerChar(typePassengerStr,//corregir
					"\nIntroduzca el tipo de pasajero: ",
					"\n-Ingrese un tipo de pasajero valido-\n", 5) == 0
			&& getStatusFlight(statusFlightStr,
					"\nIntroduzca el estado de vuelo del pasajero: ",
					"\n-Ingrese un estado de vuelo valido-\n", 5) == 0) {
		punteroAUnPasajero = Passenger_newParametros(idUnico, nombreStr,
				apellidoStr, precioStr, flyCodeStr, typePassengerStr,
				statusFlightStr);
	}

	return punteroAUnPasajero;
}

int Passenger_typePassengerToInt(char *typePassengerStr, int *typePassengerInt) {
	int retorno = 0;
	int auxTypePassengerInt;

	if (typePassengerStr != NULL) {

		if (strcmp(typePassengerStr, "EconomyClass") == 0) {
			auxTypePassengerInt = 1;
		} else if (strcmp(typePassengerStr, "ExecutiveClass") == 0) {
			auxTypePassengerInt = 2;
		} else if (strcmp(typePassengerStr, "FirstClass") == 0) {
			auxTypePassengerInt = 3;
		} else {
			retorno = -1;
		}
	}
	*typePassengerInt = auxTypePassengerInt;
	return retorno;
}

int Passenger_IntToTypePassenger(int typePassengerInt, char *typePassengerStr) {
	int retorno = -1;
	char auxTypePassengerChar[15];

	if (typePassengerInt > 0 && typePassengerStr != NULL) {

		switch (typePassengerInt) {
		case 1:
			strcpy(auxTypePassengerChar, "EconomyClass");
			retorno = 0;
			break;
		case 2:
			strcpy(auxTypePassengerChar, "ExecutiveClass");
			retorno = 0;
			break;
		case 3:
			strcpy(auxTypePassengerChar, "FirstClass");
			retorno = 0;
			break;
		}
		strcpy(typePassengerStr, auxTypePassengerChar);
	}
	return retorno;
}

int Passenger_charToNum(char *idStr, char *precioStr, char *typePassengerStr,
		int *id, float *precio, int *typePassenger) {
	int retorno = 0;
	int auxIdAtoi;
	float auxPrecioAtof;
	int auxTypePassengerInt;

	if (Passenger_typePassengerToInt(typePassengerStr, &auxTypePassengerInt)
			== 0) {
		if ((auxIdAtoi = atoi(idStr)) == 0
				|| (auxPrecioAtof = atof(precioStr)) == 0) {
			retorno = -1; //si algun conversor sale mal
		} else {
			*id = auxIdAtoi;
			*precio = auxPrecioAtof;
			*typePassenger = auxTypePassengerInt;
		}
	}
	return retorno;
}

int Passenger_setAllElements(Passenger *this, int id, char *nombre,
		char *apellido, float precio, char *flyCode, int typePassenger,
		char *statusFlight) {
	int retorno = -1;

	if (this != NULL && Passenger_setId(this, id) == 0
			&& Passenger_setNombre(this, nombre) == 0
			&& Passenger_setApellido(this, apellido)
			&& Passenger_setPrecio(this, precio) == 0
			&& Passenger_setFlyCode(this, flyCode) == 0
			&& Passenger_setTypePassenger(this, typePassenger) == 0
			&& Passenger_setStatusFlight(this, statusFlight) == 0) {

		retorno = 0;
	}

	return retorno;
}

int Passenger_getAllElements(Passenger *this, int *id, char *nombre,
		char *apellido, float *precio, char *flyCode, int *typePassenger,
		char *statusFlight) {
	int retorno = -1;

	int auxId;
	char auxNombre[51];
	char auxApellido[51];
	float auxPrecio;
	char auxFlyCode[8];
	int auxTypePassenger;
	char auxStatusFlight[11];
	if (this != NULL && Passenger_getId(this, &auxId) == 0
			&& Passenger_getNombre(this, auxNombre) == 0
			&& Passenger_getApellido(this, auxApellido) == 0
			&& Passenger_getPrecio(this, &auxPrecio) == 0
			&& Passenger_getFlyCode(this, auxFlyCode) == 0
			&& Passenger_getTypePassenger(this, &auxTypePassenger) == 0
			&& Passenger_getStatusFlight(this, auxStatusFlight) == 0) {
		retorno = 0;
	}
//	printf("%d %s %s %f %s %d %s\n", auxId, auxNombre, auxApellido, auxPrecio, auxFlyCode,
//			auxTypePassenger, auxStatusFlight);

	*id = auxId;
	strcpy(nombre, auxNombre);
	strcpy(apellido, auxApellido);
	*precio = auxPrecio;
	strcpy(flyCode, auxFlyCode);
	*typePassenger = auxTypePassenger;
	strcpy(statusFlight, auxStatusFlight);

	return retorno;
}

void Passenger_printOnePassenger(Passenger *this) {
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char flyCode[8];
	int typePassenger;
	char statusFlight[11];

	if (this != NULL
			&& Passenger_getAllElements(this, &id, nombre, apellido, &precio,
					flyCode, &typePassenger, statusFlight) == 0) {
		printf("%d %s %s %f %s %d %s\n", id, nombre, apellido, precio, flyCode,
				typePassenger, statusFlight);
	}
}

Passenger* Passenger_new() {

	Passenger *punteroAUnPasajero;
	punteroAUnPasajero = (Passenger*) malloc(sizeof(Passenger));

	Passenger_setId(punteroAUnPasajero, 0);
	Passenger_setNombre(punteroAUnPasajero, " ");
	Passenger_setApellido(punteroAUnPasajero, " ");
	Passenger_setPrecio(punteroAUnPasajero, 0);
	Passenger_setFlyCode(punteroAUnPasajero, " ");
	Passenger_setTypePassenger(punteroAUnPasajero, 0);
	Passenger_setStatusFlight(punteroAUnPasajero, " ");

	return punteroAUnPasajero;

}
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *precioStr, char *flyCodeStr,
		char *typePassengerStr, char *statusFlightStr) {
	Passenger *punteroAUnPasajero;
	int auxIdAtoi;
	float auxPrecioAtof;
	int auxTypePassengerAtoi;
	punteroAUnPasajero = Passenger_new();
	if (punteroAUnPasajero != NULL) {
		if (idStr != NULL && nombreStr != NULL && apellidoStr != NULL
				&& precioStr != NULL && flyCodeStr != NULL
				&& typePassengerStr != NULL && statusFlightStr != NULL) {
			if (Passenger_charToNum(idStr, precioStr, typePassengerStr,
					&auxIdAtoi, &auxPrecioAtof, &auxTypePassengerAtoi) == 0) {
				if (Passenger_setId(punteroAUnPasajero, auxIdAtoi) != 0
						|| Passenger_setNombre(punteroAUnPasajero, nombreStr)
								!= 0
						|| Passenger_setApellido(punteroAUnPasajero,
								apellidoStr) != 0
						|| Passenger_setPrecio(punteroAUnPasajero,
								auxPrecioAtof) != 0
						|| Passenger_setFlyCode(punteroAUnPasajero, flyCodeStr)
								!= 0
						|| Passenger_setTypePassenger(punteroAUnPasajero,
								auxTypePassengerAtoi) != 0
						|| Passenger_setStatusFlight(punteroAUnPasajero,
								statusFlightStr) != 0) {
					Passenger_delete(punteroAUnPasajero);
					punteroAUnPasajero = NULL;

				}
			} else {
				printf("No se pudieron convertir los datos");
			}
		}
	}
	return punteroAUnPasajero;
}
void Passenger_delete(Passenger *this) {
	if (this != NULL) {
		free(this);
	}
}

int Passenger_setId(Passenger *this, int id) {
	int retorno = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger *this, int *id) {
	int retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int Passenger_setApellido(Passenger *this, char *apellido) {
	int retorno = -1;
	if (this != NULL && apellido != NULL) {
		strncpy(this->apellido, apellido, sizeof(this->apellido));
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido) {
	int retorno = -1;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}
int Passenger_setPrecio(Passenger *this, float precio) {
	int retorno = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio) {
	int retorno = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setFlyCode(Passenger *this, char *flyCode) {
	int retorno = -1;
	if (this != NULL && flyCode != NULL && isFlycode(flyCode) == 1) {
		strncpy(this->flyCode, flyCode, sizeof(this->flyCode));
		retorno = 0;
	}
	return retorno;
}
int Passenger_getFlyCode(Passenger *this, char *flyCode) {
	int retorno = -1;
	if (this != NULL && flyCode != NULL) {
		strcpy(flyCode, this->flyCode);
		retorno = 0;
	}
	return retorno;
}
int Passenger_setTypePassenger(Passenger *this, int typePassenger) {
	int retorno = -1;
	if (this != NULL && typePassenger > 0) {
		this->typePassenger = typePassenger;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTypePassenger(Passenger *this, int *typePassenger) {
	int retorno = -1;
	if (this != NULL && typePassenger != NULL) {
		*typePassenger = this->typePassenger;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setStatusFlight(Passenger *this, char *statusFlight) {
	int retorno = -1;
	if (this != NULL && statusFlight != NULL) {
		strncpy(this->statusFlight, statusFlight, sizeof(this->statusFlight));
		retorno = 0;
	}
	return retorno;
}
int Passenger_getStatusFlight(Passenger *this, char *statusFlight) {
	int retorno = -1;
	if (this != NULL && statusFlight != NULL) {
		strcpy(statusFlight, this->statusFlight);
		retorno = 0;
	}
	return retorno;
}

	int Passenger_sortById(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno=-1;
	int idPrimerPasajero;
	int idSegundoPasajero;
	Passenger* primerPasajero;
	Passenger* segundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		primerPasajero=(Passenger*)pPrimerPasajero;
			segundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getId(primerPasajero, &idPrimerPasajero);
			Passenger_getId(segundoPasajero, &idSegundoPasajero);
			if(idPrimerPasajero>idSegundoPasajero){
				retorno=1;
			}
			else{
				if(idPrimerPasajero==idSegundoPasajero){
					retorno=0;
				}
			}
	}
	return retorno;
}
int Passenger_sortByNombre(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno;
	char nombrePrimerPasajero[51];
	char nombreSegundoPasajero[51];
	Passenger* PrimerPasajero;
	Passenger* SegundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		PrimerPasajero=(Passenger*)pPrimerPasajero;
			SegundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getNombre(PrimerPasajero, nombrePrimerPasajero);
			Passenger_getNombre(SegundoPasajero, nombreSegundoPasajero);
			retorno=strcmp(nombrePrimerPasajero,nombreSegundoPasajero);
	}
	return retorno;
}
int Passenger_sortByApellido(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno;
	char apellidoPrimerPasajero[51];
	char apellidoSegundoPasajero[51];
	Passenger* PrimerPasajero;
	Passenger* SegundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		PrimerPasajero=(Passenger*)pPrimerPasajero;
			SegundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getApellido(PrimerPasajero, apellidoPrimerPasajero);
			Passenger_getApellido(SegundoPasajero, apellidoSegundoPasajero);
			retorno=strcmp(apellidoPrimerPasajero,apellidoSegundoPasajero);
	}
	return retorno;
}
int Passenger_sortByPrecio(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno=-1;
	float precioPrimerPasajero;
	float precioSegundoPasajero;
	Passenger* primerPasajero;
	Passenger* segundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		primerPasajero=(Passenger*)pPrimerPasajero;
			segundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getPrecio(primerPasajero, &precioPrimerPasajero);
			Passenger_getPrecio(segundoPasajero, &precioSegundoPasajero);
			if(precioPrimerPasajero>precioSegundoPasajero){
				retorno=1;
			}
			else{
				if(precioPrimerPasajero==precioSegundoPasajero){
					retorno=0;
				}
			}
	}
	return retorno;
}
int Passenger_sortByFlycode(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno;
	char flycodePrimerPasajero[51];
	char flycodeSegundoPasajero[51];
	Passenger* PrimerPasajero;
	Passenger* SegundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		PrimerPasajero=(Passenger*)pPrimerPasajero;
			SegundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getFlyCode(PrimerPasajero, flycodePrimerPasajero);
			Passenger_getFlyCode(SegundoPasajero, flycodeSegundoPasajero);
			retorno=strcmp(flycodePrimerPasajero,flycodeSegundoPasajero);
	}
	return retorno;
}
int Passenger_sortByTypePassenger(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno=-1;
	int typePassengerPrimerPasajero;
	int typePassengerSegundoPasajero;
	Passenger* primerPasajero;
	Passenger* segundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		primerPasajero=(Passenger*)pPrimerPasajero;
			segundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getTypePassenger(primerPasajero, &typePassengerPrimerPasajero);
			Passenger_getTypePassenger(segundoPasajero, &typePassengerSegundoPasajero);
			if(typePassengerPrimerPasajero>typePassengerSegundoPasajero){
				retorno=1;
			}
			else{
				if(typePassengerPrimerPasajero==typePassengerSegundoPasajero){
					retorno=0;
				}
			}
	}
	return retorno;
}
int Passenger_sortByStatusFlight(void* pPrimerPasajero, void* pSegundoPasajero){
	int retorno;
	char statusFlightPrimerPasajero[51];
	char statusFlightSegundoPasajero[51];
	Passenger* PrimerPasajero;
	Passenger* SegundoPasajero;
	if (pPrimerPasajero != NULL && pSegundoPasajero != NULL) {
		PrimerPasajero=(Passenger*)pPrimerPasajero;
			SegundoPasajero=(Passenger*)pSegundoPasajero;
			Passenger_getStatusFlight(PrimerPasajero, statusFlightPrimerPasajero);
			Passenger_getStatusFlight(SegundoPasajero, statusFlightSegundoPasajero);
			retorno=strcmp(statusFlightPrimerPasajero,statusFlightSegundoPasajero);
	}
	return retorno;
}
