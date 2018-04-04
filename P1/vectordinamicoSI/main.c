/* 
 * File:   main.c
 * Author: alber
 *
 * Created on 4 de febrero de 2014, 18:05
 */

#include <stdio.h>
#include <stdlib.h>

#include "vectordinamico.h" 

/*
 * 
 */
int main(int argc, char** argv) {
vectorP v1 ;          /* declaramos el vector*/
short tam1, i;    /*variables para almacenar su tamaño y una variable para recorrerlo*/
TELEMENTO valor;        /*El valor a introducir en el vector*/
char opcion;            /*La variable del menú*/

do{
printf("\n--------------------\n");
	printf("\na) Crea vector v1");
	printf("\nk) Salir");
	printf("\n--------------------\n");

	printf("\nOpcion: ");
	scanf(" %c",&opcion);

	switch(opcion){
            case 'a':
			/*Creo vector v1*/
			printf("Introduce el tamanho del vector v1: ");
			scanf("%hd", &tam1);
			crear(&v1, tam1);
			/*Asigno valores a v1*/
			for (i=0; i<tam1; i++) {
				printf("Elemento %d del vector v1: ",i);
				scanf("%f",&valor);
				asignar(&v1, i, valor);
                        }
                break;

            case 'k': 
                 printf("Saliendo del programa");
                break;       
            default: printf("Opcion incorrecta\n");
        }
}while (opcion != 'k');
return (EXIT_SUCCESS);
}
    

