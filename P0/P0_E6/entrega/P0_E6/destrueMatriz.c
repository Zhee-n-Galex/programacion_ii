#include "matriz.h"

void destrueMatriz(matriz *M) {
    if (M != 0) {
        free(M->datos);
        free(M);
    }
}
