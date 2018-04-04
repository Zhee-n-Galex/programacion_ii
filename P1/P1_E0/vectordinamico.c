#include <stdlib.h>

typedef float TELEMENTO;
/*Se vuelve a definir el tipo de datos que contiene el vector*/

typedef struct {
	TELEMENTO *datos;
	short tam;
}STVECTOR;

typedef STVECTOR *vectorP;

/*Función crear: asigna memoria y devuelve la asignación al vector*/

void crear(vectorP *v1, short tam1) {
	short i = 0;
	*v1 = (vectorP)malloc(sizeof(STVECTOR));
	(*v1)->datos = (TELEMENTO*)malloc(tam1 * sizeof(TELEMENTO));
	(*v1)->tam = tam1;
	for (i = 0; i < tam1; i++) {
		*((*v1)->datos + i) = 0; // Inicialización a 0 de las componentes del vector
	}
}

/*Función asignar: Asigna un valor a una posición del vector*/

void asignar(vectorP *v1, short posicion, TELEMENTO valor) {
	*((*v1)->datos + posicion) = valor;
}

void liberar(vectorP *v) {
	if (v != NULL) {
		if (*v != NULL) {
			free((*v)->datos);
			free((*v));
		}
	}
}