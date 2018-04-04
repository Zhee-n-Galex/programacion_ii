/*
* File:   main.c
* Author: Alex
*
* Created on 19 February 2018, 18:52
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"

void imprimir(vectorP v1);


int main(int argc, char** argv) {

	vectorP v1 = NULL; // declaramos el vector
	short tam1, i; // variables para almacenar su tamaño y una variable para recorrerlo
	int posicion;  // variable para guardar la posicion para pasar a la funcion recuperar
    TELEMENTO valor; // valor a introducir en el vector
	char opcion; // variable del menú

    if (argc > 1) {
        crear(&v1, (short)argc - 1);

        for (i = 1; i < argc; i++)
            asignar(&v1, i - 1, atof(argv[i]));

        imprimir(v1);
    }

	do {
		printf("\n--------------------\n");
		printf("\na) Crea vector v1.");
        printf("\nb) Recuperar valor de v1.");
        printf("\nc) Imprimir v1.");
        printf("\nl) Liberar v1.");
		printf("\nk) Salir.");
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
            imprimir(v1);
			break;
        case 'b':
            printf("Indica la posicion del valor que quieres: ");
            scanf("%d", &posicion);
            printf("O valor da posicion %d e: %f", posicion, recuperar(v1, posicion - 1));
            break;
        case 'l':
            liberar(&v1);
            printf("Liberando el vector...\n");
            break;
        case 'c':
            imprimir(v1);
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

void imprimir(vectorP v1) {
    short tm;
    int i;

    if (v1 != NULL){
        tm = tamano(v1);
        printf("Elementos del vector:\n");
        for (i = 0; i < tm; i++) {
            printf("%d -> %f\n", i + 1, recuperar(v1, i));
        }
    } else {
        printf("ERROR. El vector no existe.\n");
    }
}