#include <stdio.h>

int factorial(int n) {    
    int valor = 1;
    if (n > 0) {    
        int i;
        //for (i=0; i <=n; i++) o bucle non pode comezar con i = 0, ten que ser por i = 1
        for(i = 1; i <= n; i++)    
            valor = valor * i;    
    } else {
        //printf("Error factorial: el parámetro (%f) no es un entero positivo\n");
        printf("Error factorial: el parámetro (%d) no es un entero positivo\n", n);
    }
    return valor;
}

