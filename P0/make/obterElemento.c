#include "matriz.h"

float obterElemento(int fila, int columna, matriz *M) {
    int x;

    if (M != 0) {
        if ((fila < 0 || fila > M->filas) || (columna < 0 || columna > M->columnas)) {
            printf("Ese elemento non existe.");
            return 0;
        }
        x = *((M->datos) + fila * M->columnas + columna);
        return x;
    } else
        printf("A matriz non existe!!\n");
}
