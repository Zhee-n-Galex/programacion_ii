#include <stdio.h>
#include <stdlib.h>

void potencia(int base[4], int exp, float pot[4]){
    float valor = 1.0;
    int i, j;
    
    for(i = 0; i < 4; i++){
        for(j = 1; j <= abs(exp); j++){
            valor = valor * base[i];
        }
        pot[i] = (exp < 0) ? 1/valor : valor;
        valor = 1.0;
    }
}

