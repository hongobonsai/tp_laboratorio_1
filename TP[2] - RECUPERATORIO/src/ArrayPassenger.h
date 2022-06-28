/*
 * ArrayPassenger.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Hongo
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN_PASAJEROS 1000

struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
} typedef Passenger;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

int initPassengers(Passenger *list, int lenght);
int findEmptySpace(Passenger list[], int len);
int addPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);
int isThereAnyPassenger(Passenger *list, int len);
int findPassengerById(Passenger *list, int len, int id);
int removePassenger(Passenger *list, int len, int id);
int sortPassengers(Passenger *list, int len, int order);
int sortPassengersByCode(Passenger *list, int len, int order);
int printPassenger(Passenger list[], int len);
#endif /* ARRAYPASSENGER_H_ */
