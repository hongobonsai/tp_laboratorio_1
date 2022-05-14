/*
 * ArrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef Passenger;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

int initPassengers(Passenger list[], int len);
int addPassenger(Passenger list[], int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[]);
int findEmptySpace(Passenger list[], int len);
int isThereAnyPassenger(Passenger *list, int len);
int findPassengerById(Passenger *list, int len, int id);
int removePassenger(Passenger *list, int len, int id);
int sortPassengers(Passenger *list, int len, int order);
int printPassenger(Passenger *list, int len);
int averageAndTotalPricePassenger(Passenger *list, int len, float *precioTotal, float * promedio, int *superanPromedio);

#endif /* ARRAYPASSENGER_H_ */
