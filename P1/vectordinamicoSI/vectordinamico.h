/* 
 * File:   vectordinamico.h
 * Author: alber
 *
 * Created on 4 de febrero de 2014, 18:05
 */


/*Tipo de datos de los elementos del vector*/
typedef float TELEMENTO;

/*tipo opaco, los detalles de implementaci�n est�n ocultos al usuario*/
typedef void * vectorP; 

/*Funci�n crear: asigna memoria y devuelve la asignaci�n al vector. Recibe v1 por referencia para devolver al programa principal la direcci�n de memoria reservada por este procedimiento*/
void crear(vectorP *v1,short tam1);

/*Funci�n asignar: Llena una posici�n del vector con un valor. Recibe una copia de la direcci�n de memoria reservada para el vector v1*/
void asignar(vectorP *v1,short posicion, TELEMENTO valor);

