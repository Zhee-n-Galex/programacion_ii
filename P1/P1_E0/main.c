/*
* File:   main.c
* Author: Alex
*
* Created on 19 February 2018, 18:52
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"

int main(int argc, char** argv) {

	vectorP v1 = NULL; // declaramos el vector
	short tam1, i; // variables para almacenar su tamaño y una variable para recorrerlo
	TELEMENTO valor; // valor a introducir en el vector
	char opcion; // variable del menú

	do {
		printf("\n--------------------\n");
		printf("\na) Crea vector v1");
		printf("\nk) Salir");
		printf("\n------------------------\n");

		printf("\nOpcion: ");
		fflush(stdin);
		scanf(" %c", &opcion);

		switch (opcion) {
		case 'a':
			// Compruebo que el vector v1 no existe y si existe lo destruyo
			liberar(&v1);

			// Creo vector v1
			printf("Introduce el tamamnho del vector v1: ");
			scanf("%hd", &tam1);
			crear(&v1, tam1);
			// Asigno valores a v1
			for (i = 0; i<tam1; i++) {
				printf("Elemento %d del vector v1: ", i);
				scanf("%f", &valor);
				asignar(&v1, i, valor);
			}
			break;
		case 'k':
			liberar(&v1);
			printf("Saliendo del programa\n");
			break;
		default: printf("Opcion incorrecta\n");
		}
	} while (opcion != 'k');

	return (EXIT_SUCCESS);
}

