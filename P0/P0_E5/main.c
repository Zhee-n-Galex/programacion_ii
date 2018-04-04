#include <stdio.h>
#include <stdlib.h>

void potencia(int base[4], int exponente, float pot[4]);

int main(int argc, char** argv) {

    int a[4], b;
    int i;
    float c[4];
    
    printf("Indique o expoñente: ");
    scanf("%d", &b);
    
    for(i = 0; i < 4; i++){
        printf("Introduza o enteiro %d: ", i+1);
        scanf("%d", &a[i]);
    }
    
    potencia(a, b, c);
    
    for(i = 0; i < 4; i++){
        printf("%d -> %.3f\n", a[i], c[i]);
    }
    
    return (EXIT_SUCCESS);
}