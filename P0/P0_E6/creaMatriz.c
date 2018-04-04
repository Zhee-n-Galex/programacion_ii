#include "matriz.h"

matriz* creaMatriz(int filas, int columnas) {
    int i;
    matriz *mat = 0;

    if (filas <= 0 || columnas <= 0)
        return 0;

    mat = (matriz*) malloc(sizeof (matriz));

    if (mat != 0) {
        mat->filas = filas;
        mat->columnas = columnas;
        //mat->datos = (float*) malloc(filas * filas * sizeof (float)); está creando un array de filas * filas
        mat->datos = (float*) malloc(filas * columnas * sizeof (float));
        
        //for (i = 0; i < filas * filas; i++) { Idem
        for (i = 0; i < filas * columnas; i++) {
            *((mat->datos) + i) = 0;
        }
    } else
        printf("Erro na reserva de memoria para a matriz");

    return mat;
}
