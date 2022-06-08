#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"
#define DATA_BIN "data.bin"
#define DATA_CSV "data.csv"

#define ECONOMY_CLASS 1
#define EXECUTIVE_CLASS 2
#define FIRST_CLASS 3

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    char hola[5] = {"o3la"};
    int retorno;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	retorno = isName(hola);
    	    	printf("%d", retorno);

    	option = printMenuPrincipal();
        switch(option)
        {
            case 1:
                controller_loadFromText("DATA_CSV",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("DATA_BIN",listaPasajeros);
				break;
            case 3:
            	controller_addPassenger(listaPasajeros);
				break;
            case 4:
            	controller_editPassenger(listaPasajeros);
				break;
            case 5:
            	controller_removePassenger(listaPasajeros);
				break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
				break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
				break;
            case 8:
            	controller_saveAsText("DATA_CSV",listaPasajeros);
				break;
            case 9:
            	controller_saveAsBinary("DATA_BIN",listaPasajeros);
				break;
            case 10:
            	printf("CHAU");
            	break;

        }
    }while(option != 10);
    return 0;
}




