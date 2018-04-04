//
// Created by Alex on 21/03/2018.
//

#include "burbuja.h"

void Burb (vectorP *vectorP1) {
    unsigned long e, i, tam = tamano(*vectorP1);
    int aux;

    for (e = 0; e < tam - 1; e++) {
        for (i = 0; i < tam - e - 1; i++) {
            if (recuperar(*vectorP1, i) > recuperar(*vectorP1, i + 1)) {
                aux = recuperar(*vectorP1, i);
                asignar(vectorP1, i, recuperar(*vectorP1, i + 1));
                asignar(vectorP1, i + 1, aux);
            }
        }
    }
}