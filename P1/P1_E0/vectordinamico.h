/*
* File:   vectordinamico.h
* Author: alber
*
* Created on 4 de febrero de 2014, 18:05
*/


/*Tipo de datos de los elementos del vector*/
typedef float TELEMENTO;

/*tipo opaco, los detalles de implementación están ocultos al usuario*/
typedef void * vectorP;

/*Función crear: asigna memoria y devuelve la asignación al vector. Recibe v1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(vectorP *v1, short tam1);

/*Función asignar: Llena una posición del vector con un valor. Recibe una copia de la dirección de memoria reservada para el vector v1*/
void asignar(vectorP *v1, short posicion, TELEMENTO valor);

/*Función liberar: Comprueba que el puntero no está vacío y libera la memoria a la que apunta*/
void liberar(vectorP *v);