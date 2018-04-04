#include "matriz.h"

matriz* prodEscalar(float s, matriz *M) {
    matriz *aux = 0;
    int i;
    if (M != 0) {
        //aux = creaMatriz(M->columnas, M->filas); as filas e columnas están cambiadas de orde
        aux = creaMatriz(M->filas, M->columnas);

        for (i = 0; i < aux->filas * aux->columnas; i++) {
            *(aux->datos + i) = *(M->datos + i) * s;
        }

        return aux;
    } else {
        printf("A matriz non existe!!\n");
        // Retornamos a matriz para eliminar o aviso ao compilar
        return aux;
    }
}
