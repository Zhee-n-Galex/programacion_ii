 /*
 * PROGRAMA PARA CALCULAR O FACTORIAL E A POTENCIA DE DOUS NÚMEROS ENTEIROS
 * PEDIDOS AO/Á USUARIO/A POR TECLADO.
 *
 * OBXECTIVO: DEPURAR USANDO AS FERRAMENTAS DO NETBEANS. 
 * O PROGRAMA TEN COMO MÍNIMO SEIS ERROS. DOCUMENTAR AS CORRECCIÓNS 
 * INTRODUCIDAS, POÑENDO UN COMENTARIO COA SENTENCIA INCORRECTA AO
 * LADO DA SENTENCIA CORRIXIDA
 * 
 * PROBAS: USAR OS CASOS
 * 0 0
 * 10 2
 * 2 10
 * 5.5 6.5
 * -2.3 -1
 * -5 1
 */
#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
//int potencia(int n, int m);
float potencia(int n, int m);

int main(int argc, char** argv) {
    
    int a, b;
    int f;
    //int p;
    float p;
    
    printf("Introduce dos números enteros: ");
    //scanf("%f%d", a, &b); é necesario poñer o símbolo & na variable a
    scanf("%d%d", &a, &b);

    f = factorial(a);
    printf("Factorial(%d) = %d\n", a, f);
    
    p = potencia(a, b);
    //printf("Potencia(%d,%d) = %d\n", a, b, p);
    printf("Potencia(%d, %d) = %f\n", a, b, p);
    
    return (EXIT_SUCCESS);
}

