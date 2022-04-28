/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct
	{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	}typedef Passenger;

struct
	{
	char flycode[10];
	int statusFlight;
	}typedef Flight;

int tp_Dos_MenuPrincipal();
int initPassengers(Passenger* list, int len);

int main(void) {
	setbuf(stdout, NULL);

	//structs
	Passenger pasajeros[2000];
	Flight vuelos[2000];
	//opciones menús
	int opcionMenuPrincipal;
	int opcionMenuModificar;

	do {
		opcionMenuPrincipal = tp_Dos_MenuPrincipal();

		initPassengers(pasajeros, 2000);
		printf()

		switch (opcionMenuPrincipal) {
		case 1:
			printf("\nMENÚ DE ALTAS\n\n");
			printf("Ingrese el nombre del pasajero\n");
			scanf("%s", pasajeros[0].name);
			fflush(stdin);
			printf("Ingrese el apellido del pasajero\n");
			scanf("%s", pasajeros[0].lastName);
			printf("Ingrese el codigo de vuelo\n");
			scanf("%s", pasajeros[0].flycode);
			printf("Ingrese el estado del vuelo (\n");
			scanf("%d", &vuelos[0].statusFlight);
			printf("Ingrese el precio del vuelo\n");
			scanf("%f", &pasajeros[0].price);
			printf("Ingrese el tipo de pasajero (1, 2, 3\n");
			scanf("%d", &pasajeros[0].typePassenger);

			//asignar ID
			//levantar Flag empty
			printf("%s %s %s %f %d", pasajeros[0].name, pasajeros[0].lastName, pasajeros[0].flycode,
					pasajeros[0].price, pasajeros[0].typePassenger);

			break;
		case 2:
			printf("\nMENÚ DE MODIFICACIÓNES\n\n");
			printf("Por favor, ingrese el ID del pasajero a modificar:\n");
			//scanf
			//funcion findByID
			do {
				fflush(stdin);
				printf("\nOprima '1' para modificar el nombre del pasajero.\n"
						"Oprima '2' para modificar el nombre del pasajero.\n"
						"Oprima '3' para modificar el nombre del pasajero.\n"
						"Oprima '4' para modificar el nombre del pasajero.\n"
						"Oprima '5' para modificar el nombre del pasajero.\n\n"
						"Oprima '0' volver al menú principal.\n");
				scanf("%d", &opcionMenuModificar);

				switch(opcionMenuModificar){
				case 1:
					printf("1");
					initPassengers(pasajeros, 2000);
					break;
				case 2:
					printf("2");
					break;
				case 3:
					printf("3");
					break;
				case 4:
					printf("4");
					break;
				case 5:
					printf("5");
					break;
				}
				//Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
				//o Precio o Tipo de pasajero o Código de vuelo
			} while (opcionMenuModificar != 0);

			break;
		case 3:
			printf("\nMENÚ DE BAJAS\n\n");
			printf("Por favor, ingrese el ID del pasajero a dar de baja:\n");
			printf("3");
			break;
		case 4:
			printf("4");
			break;
		case 5:
			printf("Salió del programa");
			break;
		}
	} while (opcionMenuPrincipal != 5);

	return EXIT_SUCCESS;

}

int tp_Dos_MenuPrincipal() {
	int auxOpcionMenuPrincipal;
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJA");
	printf("\n4. INFORMAR");
	printf("\n5. EXIT");

	scanf("%d", &auxOpcionMenuPrincipal);

	return auxOpcionMenuPrincipal;
}

//arrays functions:

int initPassengers(Passenger* list, int len)
{
	int i;
	if (len > 0) {
		for (i = 0; i < len; i++) {
			 = -1;
		}
		}
return 0;
}














