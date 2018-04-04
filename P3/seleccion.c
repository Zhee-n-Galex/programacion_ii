//
// Created by Alex on 24/03/2018.
//

#include "seleccion.h"

void Selec(vectorP *v1) {
    unsigned long e, i, PosMenor;
    int aux;

    for (e = 0; e < tamano(*v1) - 1; e++) {
        PosMenor = e;
        for (i = e + 1; i < tamano(*v1); i++)
            if (recuperar(*v1, i) < recuperar(*v1, PosMenor))
                PosMenor = i;
        aux = recuperar(*v1, e);
        asignar(v1, e, recuperar(*v1, PosMenor));
        asignar(v1, PosMenor, aux);
    }
}