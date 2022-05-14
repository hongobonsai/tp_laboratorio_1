/*
 * ArrayFlight.h
 *
 *  Created on: 13 may. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
struct{
	char flycode[10];
	int statusFlight;
	int isEmpty;
}typedef Flight;

#ifndef ARRAYFLIGHT_H_
#define ARRAYFLIGHT_H_

int initFlights(Flight list[], int len);
int addFlight(Flight *list, char auxFlycode[], int len);
int findEmptyFlight(Flight list[], int len);
int findFlightByCode(Flight *list, int len, char flycode[]);

#endif /* ARRAYFLIGHT_H_ */
