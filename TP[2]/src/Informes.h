/*
 * Informes.h
 *
 *  Created on: 14 may. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "Arraypassenger.h"
#include "ArrayFlight.h"
#include "tp_2_library.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int sortPassengersByCode(Passenger *pasajeros, Flight *vuelos, int len, int order);
int printPassengerByCode(Passenger *pasajeros, Flight *vuelos, int len);

#endif /* INFORMES_H_ */
