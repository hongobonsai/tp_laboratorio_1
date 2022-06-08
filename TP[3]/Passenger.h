/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char flyCode[8];
	int typePassenger;
	char statusFlight[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr,
		char *precioStr, char *flyCodeStr, char *typePassengerStr, char *statusFlightStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_setFlyCode(Passenger *this, char *flyCode);
int Passenger_getFlyCode(Passenger *this, char *flyCode);

int Passenger_setTypePassenger(Passenger *this, int typePassenger);
int Passenger_getTypePassenger(Passenger *this, int *typePassenger);

int Passenger_setStatusFlight(Passenger *this, char *nombre);
int Passenger_getStatusFlight(Passenger *this, char *nombre);



#endif /* PASSENGER_H_ */
