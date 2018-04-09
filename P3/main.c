#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectordinamico.h"
#include "quicksort.h"
#include "burbuja.h"
#include "seleccion.h"

int main(int argc, char* args[]) {
    unsigned long i, tam_inicial, tam_final, pasos;
    int menu;
    char archivo[50];
    vectorP v1 = NULL;
    clock_t inicio = -1, fin = -1;
    FILE *fp;

    if (argc > 1) {
        tam_inicial = atoi(args[1]);
        tam_final = atoi(args[2]);
        pasos = atoi(args[3]);
    } else {
        printf("\nIntroduza o tamaño inicial do vector: ");
        fflush(stdin);
        scanf("%lu", &tam_inicial);
        printf("\nIntroduza o tamaño final do vector: ");
        fflush(stdin);
        scanf("%lu", &tam_final);
        printf("\nIntroduza o numero de elementos a incrementar: ");
        fflush(stdin);
        scanf("%lu", &pasos);
    }

    do {
        printf("Medicion experimental de programas\n");
        printf("1. Metodo quicksort.\n");
        printf("2. Metodo burbulla.\n");
        printf("3. Metodo seleccion.\n");
        printf("4. Cambiar o tamaño do vector e os pasos.\n");
        printf("5. Sair do programa.\n");
        printf("Seleccione unha opcion: ");
        fflush(stdin);
        scanf("%d", &menu);
        switch (menu) {
            case 1: // metodo quicksort
                printf("Introduza o nome do arquivo: ");
                fflush(stdin);
                scanf("%s", archivo);
                fp = fopen(archivo, "w");
                for (i = tam_inicial; i <= tam_final; i = i + pasos) {
                    crear(&v1, i);
                    inicializaVectorRand(&v1);
                    inicio = clock();
                    quicksort(&v1, 0, i);
                    fin = clock();
                    printf("quicksort: n:%lu\t\nini.:%lu\tfin:%lu\ttiempo:%.41f\n", i, inicio, fin,
                           (fin - inicio) / (double) CLOCKS_PER_SEC);
                    fprintf(fp, "%lu\t%.41f\n", i, (fin - inicio) / (double) CLOCKS_PER_SEC);
                    liberar(&v1);
                }
                fclose(fp);
                break;
            case 2: // metodo burbuja
                printf("Introduza o nome do arquivo: ");
                fflush(stdin);
                scanf("%s", archivo);
                fp = fopen(archivo, "w");
                for (i = tam_inicial; i <= tam_final; i = i + pasos) {
                    crear(&v1, i);
                    inicializaVectorRand(&v1);
                    inicio = clock();
                    Burb(&v1);
                    fin = clock();
                    printf("Burbuja: n:%lu\t\nini.:%lu\tfin:%lu\ttiempo:%.41f\n", i, inicio, fin,
                           (fin - inicio) / (double) CLOCKS_PER_SEC);
                    fprintf(fp, "%lu\t%.41f\n", i, (fin - inicio) / (double) CLOCKS_PER_SEC);
                    liberar(&v1);
                }
                fclose(fp);
                break;
            case 3: // metodo seleccion
                printf("Introduza o nome do arquivo: ");
                fflush(stdin);
                scanf("%s", archivo);
                fp = fopen(archivo, "w");
                for (i = tam_inicial; i <= tam_final; i = i + pasos) {
                    crear(&v1, i);
                    inicializaVectorRand(&v1);
                    inicio = clock();
                    Selec(&v1);
                    fin = clock();
                    printf("Seleccion: n:%lu\t\nini.:%lu\tfin:%lu\ttiempo:%.41f\n", i, inicio, fin,
                           (fin - inicio) / (double) CLOCKS_PER_SEC);
                    fprintf(fp, "%lu,%.41f\n", i, (fin - inicio) / (double) CLOCKS_PER_SEC);
                    liberar(&v1);
                }
                fclose(fp);
                break;
            case 4: // preguntamos os parametros
                printf("\nIntroduza o tamaño inicial do vector: ");
                fflush(stdin);
                scanf("%lu", &tam_inicial);
                printf("\nIntroduza o tamaño final do vector: ");
                fflush(stdin);
                scanf("%lu", &tam_final);
                printf("\nIntroduza o numero de elementos a incrementar: ");
                fflush(stdin);
                scanf("%lu", &pasos);
                break;
            case 5:
                printf("Saindo do programa...\n");
                liberar(&v1);
                break;
            default:
                printf("Introduce unha opcion valida.\n");
                break;
        }
    } while (menu != 5);

    liberar(&v1);

    return 0;
}