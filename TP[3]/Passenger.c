/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

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

			auxIdAtoi = atoi(idStr);
			auxPrecioAtof = atof(precioStr);
			auxTypePassengerAtoi = atoi(typePassengerStr);

			if (Passenger_setId(punteroAUnPasajero, auxIdAtoi) != 0
					|| Passenger_setNombre(punteroAUnPasajero, nombreStr) != 0
					|| Passenger_setApellido(punteroAUnPasajero, apellidoStr) != 0
					|| Passenger_setPrecio(punteroAUnPasajero, auxPrecioAtof) != 0
					|| Passenger_setFlyCode(punteroAUnPasajero, flyCodeStr) != 0
					|| Passenger_setTypePassenger(punteroAUnPasajero, auxTypePassengerAtoi) != 0
					|| Passenger_setStatusFlight(punteroAUnPasajero, statusFlightStr) != 0) {

				Passenger_delete(punteroAUnPasajero);
				punteroAUnPasajero = NULL;

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
int Passenger_setStatusFlight(Passenger *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
int Passenger_getStatusFlight(Passenger *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
