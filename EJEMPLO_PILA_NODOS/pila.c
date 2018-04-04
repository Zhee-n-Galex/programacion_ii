//
// Created by Alex on 22/02/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void PilaVacia (TPILA *p) {
    *p = NULL; /* Valor NULL en puntero TPILA */
}

int EsVacia (TPILA p) {
    return (p == NULL) ? 1 : 0;
}

void Push (TPILA *p, TELEMENTO e) {
    TPILA q;
    q = (TPILA) malloc(sizeof(TNodo));
    q->dato = e;
    q->sig = *p;
    *p = q;
}

void Cima (TPILA p, TELEMENTO *pe) {
    int respuesta = EsVacia(p);
    if (respuesta == 1)
        printf("ERROR, la pila no tiene elementos.\n");
    else
        *pe = p->dato;
}

void Pop (TPILA *p) {
    TPILA q;
    int respuesta = EsVacia(*p);

    if (respuesta == 1)
        printf("ERROR, la pila esta vacia.\n");
    else {
        q = *p;
        *p = (*p)->sig;
        free(q);
    }
}

void DestruyePila (TPILA *p) {
    TPILA q;
    int respuesta = EsVacia(*p);

    if (respuesta == 1) {
        free(*p);
        free(p);
    } else {
        while (EsVacia(*p) == 0) {
            q = *p;
            *p = (*p)->sig;
            free(q);
        }
        printf("Pila destruida correctamente.\n");
    }
}