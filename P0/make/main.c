/*
 * PROGRAMA PARA REALIZAR OPERACIÓNS BÁSICAS CUNHA MATRIZ DINÁMICA
 *
 * OBXECTIVO: DEPURAR USANDO AS FERRAMENTAS DO NETBEANS. O PROGRAMA TEN COMO MÍNIMO SEIS ERROS
 * DOCUMENTAR AS CORRECCIÓNS INTRODUCIDAS, POÑENDO UN COMENTARIO COA SENTENCIA INCORRECTA AO
 * LADO DA SENTENCIA CORRIXIDA
 *
 * PROBAS:
 * - número de filas ou columnas: 0
 * - acceder a un dato con índices negativos
 * - verificar todas as operacións, para matrices pequenas (2,3 filas/cols)
 *      - número de filas e columnas distintos nas dúas matrices
 *      - número de filas igual e de columnas distinto
 *      - número de columnas igual e de filas distinto
 */


#include "matriz.h"

int main(int argc, char** argv) {
    int i, k, f, c;
    float valor;
    matriz *a = 0, *b = 0, *aux = 0;
    char opcion[1], resp[1];


    do {
        do {
            printf("---------------------Libreria matrices---------------------\n\n");
            printf("1-Crear matriz\n");
            printf("2-Asignar elementos\n");
            printf("3-Obter elemento\n");
            printf("4-Imprime matriz\n");
            printf("5-Sumar matrices\n");
            printf("6-Produto por un escalar\n");
            printf("7-Produto de matrices\n");
            printf("8-Eliminar matriz\n");
            printf("0-Sair\n");
            scanf("%s", opcion);
        } while (opcion[0] < '0' || opcion[0] > '8');

        switch (opcion[0]) {
            case '1':
                printf("Introduza o numero de filas da matriz 'a': ");
                scanf("%f", &f);
                printf("Introduza o numero de columnas da matriz 'a': ");
                scanf("%d", &c);
                a = creaMatriz(f, c);

                printf("Introduza o numero de filas da matriz 'b': ");
                scanf("%f", &f);
                printf("Introduza o numero de columnas da matriz 'b': ");
                scanf("%d", &c);
                b = creaMatriz(f, c);

                break;
            case '2':
                printf("Matriz A\n");
                for (f = 0; f < a->filas; f++)
                    for (c = 0; c < a->columnas; c++) {
                        printf("Introduza o valor da posicion %dx%d: ", f + 1, c + 1);
                        scanf("%f", &valor);
                        asignarElemento(f, c, valor, a);
                    }
                printf("Matriz B\n");
                for (f = 0; f < b->filas; f++)
                    for (c = 0; c < b->columnas; c++) {
                        printf("Introduza o valor da posicion %dx%d: ", f + 1, c + 1);
                        scanf("%f", &valor);
                        asignarElemento(f, c, valor, a);
                    }

                break;
            case '3':
                do {
                    printf("De que matriz queres ver o elemento? (a/b): ");
                    fflush(stdin);
                    scanf("%s", &resp);
                } while (resp[0] != 'a' && resp[0] != 'b');
                printf("Introducir fila e columna (fila columna): ");
                scanf("%d %d", &f, &c);            
                if (resp[0] == 'a') {
                    valor = obterElemento(f, c, b);
                    printf("O valor da fila e columna seleccioada e: %f\n", valor);
                } else if (resp[0] == 'b') {
                    valor = obterElemento(f, c, a);
                    printf("O valor da fila e columna seleccioada e: %f\n", valor);
                }
                break;
            case '4':
                printf("Matriz A\n");
                imprimeMatriz(a);
                printf("Matriz B\n");
                imprimeMatriz(b);
                break;
            case '5':
                aux = suma(a, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '6':
                printf("Escalar polo que sera multiplicada a matriz: ");
                scanf("%f", &valor);
                aux = prodEscalar(valor, a);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                aux = prodEscalar(valor, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '7':
                aux = produto(a, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '8':
                destrueMatriz(a);
                destrueMatriz(b);
                printf("Matrices eliminadas...\n");
                break;
        }
    } while (opcion[0] != '0');

    return (EXIT_SUCCESS);
}
