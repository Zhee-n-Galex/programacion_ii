#include <stdlib.h>
#include <stdio.h>

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
    *v1 = (vectorP) malloc(sizeof(STVECTOR));

    if (*v1 != NULL) { // Comprobamos que se haya reservado memoria correctamente
        (*v1)->tam = tam1;
        (*v1)->datos = (TELEMENTO *) malloc(tam1 * sizeof(TELEMENTO));
        if ((*v1)->datos) { // Comprobamos que se reservo memoria correctamente
            for (i = 0; i < tam1; i++) {
                *((*v1)->datos + i) = 0; // Inicialización a 0 de las componentes del vector
            }
        }
    }
}

/*Función asignar: Asigna un valor a una posición del vector. Comprobamos que exista o vector, o array de datos, que a posicion sexa >= 0 e <= tam*/

void asignar(vectorP *v1, short posicion, TELEMENTO valor) {
	if (*v1 != NULL && (*v1)->datos != NULL && posicion >= 0 && posicion < (*v1)->tam)
        *((*v1)->datos + posicion) = valor;
}

/*Funcion liberar: Comprueba que el vector existe y vacia la memoria correspondiente */
void liberar(vectorP *v1) {
    if (*v1 != NULL && (*v1)->datos != NULL) {
		free((*v1)->datos);
		free((*v1));
        *v1 = NULL;
	}
}

/*Funcion recuperar: Devuelve el valor de una posicion dada del vector*/
float recuperar(vectorP v1, int posicion){
    float valor = 0;

    if (v1 != NULL && v1->datos != NULL) {
        if (posicion >= 0 && posicion < v1->tam)
            valor = v1->datos[posicion]; // *(v1->datos + posicion)
        else
            printf("Esa posicion non existe.\n");
    }

    return valor;
}

/*Funcion tamanho: Devuelve el tamaño del vector */
short tamano(vectorP v1){
    short tm;

    if (v1 != NULL && v1->datos!=NULL) { // Comprobamos que o punteiro e datos non apuntan a NULL
        tm = v1->tam;
    }

    return tm;
}