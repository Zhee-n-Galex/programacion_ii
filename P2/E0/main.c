#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "listas.h"

void liberaListaPluses(TLISTA *listaPluses); // libera la memoria de la lista
void liberaColaEspera(TCOLA *colaEspera); // libera la memoria de la cola
void imprimirCola(TCOLA colaEspera); // imprime el primer elemento de la cola
void imprimirListaPluses(TLISTA listaPluses); // imprime toda la lista de pluses
int comprobacionNumeroProductos(TIPOELEMENTOCOLA n); // comprueba si el numero de productos es valido (1) o no (0)
int comprobacionValorARecaudar(TIPOELEMENTOLISTA v); //comprueba si el valor del plus a cobrar es valido (1) o no (0)
TIPOELEMENTOLISTA totalPluses(TLISTA listaPluses); // deuvelve el total de pluses acumulados
void recaudarPluses(TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar); //permite al cajero cobrar el plus indicado en la variable dineroARecaudar si el saldo es suficiente, y actualiza la lista de pluses

int main(int argc, char** argv){
    TCOLA colaClientes = NULL;
    TLISTA listaPluses = NULL;
    TNODOLISTA plus = NULL;
    int menu = 0, conf = 0, i;
    float cplus = 0.5;
    TIPOELEMENTOCOLA nprod;
    TIPOELEMENTOLISTA nplus, total_plus, dineroARecaudar;

    crea(&listaPluses); // Creamos la lista de pluses
    ColaVacia(&colaClientes); // Creamos la cola de clientes


    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            nprod = atoi(argv[i]);
            if (comprobacionNumeroProductos(nprod))
                AnadirCola(&colaClientes, nprod);
        }
    }

    while (menu != 5) {
        printf("<<<< CAJERO >>>>>\n");
        printf("1. Anotar cliente.\n");
        printf("2. Atender cliente.\n");
        printf("3. Cobrar pluses.\n");
        printf("4. Calcular pluses.\n");
        printf("5. Salir.\n");
        printf("Seleccione una opcion: \n");
        fflush(stdin);
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Numero de productos del cliente: \n");
                fflush(stdin);
                scanf("%d", &nprod);
                if (comprobacionNumeroProductos(nprod))
                    AnadirCola(&colaClientes, nprod);
                imprimirCola(colaClientes);
                break;
            case 2:
                if (!(EsColaVacia(colaClientes))) {
                    PrimeroCola(colaClientes, &nprod);
                    nplus = cplus * nprod;
                    plus = primero(listaPluses);
                    inserta(&listaPluses, plus, nplus);
                    EliminarCola(&colaClientes);
                    printf("Clientes en espera: ");
                    imprimirCola(colaClientes);
                    imprimirListaPluses(listaPluses);
                    printf("\n");
                } else {
                    printf("ERROR. No hay clientes en espera.\n");
                    imprimirListaPluses(listaPluses);
                    printf("\n");
                }
                break;
            case 3:
                imprimirListaPluses(listaPluses);
                printf("\nIndique la cantidad a cobrar: ");
                fflush(stdin);
                scanf("%f", &dineroARecaudar);
                recaudarPluses(&listaPluses, dineroARecaudar);
                imprimirListaPluses(listaPluses);
                printf("\n");
                break;
            case 4:
                imprimirListaPluses(listaPluses);
                total_plus = totalPluses(listaPluses);
                printf("\nDispone de un total de: %.2f \n", total_plus);
                break;
            case 5:
                printf("Desea salir del programa? (1=si, 0=no)\n");
                fflush(stdin);
                scanf("%d", &conf);
                if (conf == 1)
                    menu = 5;
                else
                    menu = 0;
                break;
            default:
                printf("Seleccione una opcion correcta.\n");
                break;
        }
    }

    liberaColaEspera(&colaClientes);
    liberaListaPluses(&listaPluses);

    return 0;
}

void liberaListaPluses (TLISTA *listaPluses) {
    if (*listaPluses != NULL)
        destruye(listaPluses);
    *listaPluses = NULL;
}

void liberaColaEspera (TCOLA *colaEspera) {
    if (*colaEspera != NULL) {
        while (!EsColaVacia(*colaEspera))
            EliminarCola(colaEspera);
        free(*colaEspera);
        *colaEspera = NULL;
    }
}

void imprimirCola (TCOLA colaEspera) {
    TIPOELEMENTOCOLA num;

    PrimeroCola(colaEspera, &num);

    printf("El primero de la cola tiene %d elementos.\n", num);
}

void imprimirListaPluses (TLISTA listaPluses) {
    int i;
    TIPOELEMENTOLISTA precio;
    TNODOLISTA plus = NULL;

    plus = primero(listaPluses);
    printf("Lista de pluses:\n");

    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(listaPluses, plus, &precio);
        printf("%.2f ", precio);
        plus = siguiente(listaPluses, plus);
    }
}

int comprobacionNumeroProductos (TIPOELEMENTOCOLA n) {
    if (n > 0)
        return 1;
    else
        return 0;
}

int comprobacionValorARecaudar (TIPOELEMENTOLISTA v) {
    if (v > 0)
        return 1;
    else
        return 0;
}

TIPOELEMENTOLISTA totalPluses (TLISTA listaPluses) {
    int i;
    TIPOELEMENTOLISTA precio, total = 0.0;
    TNODOLISTA plus = NULL;

    plus = primero(listaPluses);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(listaPluses, plus, &precio);
        total += precio;
        plus = siguiente(listaPluses, plus);
    }

    return total;
}

void recaudarPluses (TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar) {
    int i;
    TIPOELEMENTOLISTA precio, total, max = 0.5; // o plus minimo existente e de 0.5
    TNODOLISTA plus = NULL;
    if (!esVacia(*listaPluses)) {
        if (comprobacionValorARecaudar(dineroARecaudar)) {
            total = totalPluses(*listaPluses);

            if (total < dineroARecaudar) {
                printf("No dispone de suficientes pluses.\n");
            } else {
                while (comprobacionValorARecaudar(dineroARecaudar)) {
                    plus = primero(*listaPluses);
                    for (i = 0; i < longitud(*listaPluses); i++) {
                        recupera(*listaPluses, plus, &precio);
                        if (precio > max)
                            max = precio;
                    }
                    plus = primero(*listaPluses);
                    for (i = 0; i < longitud(*listaPluses); i++) {
                        recupera(*listaPluses, plus, &precio);
                        if (precio == max) {
                            if (precio <= dineroARecaudar) {
                                suprime(listaPluses, plus);
                                dineroARecaudar = dineroARecaudar - precio;
                            } else {
                                dineroARecaudar = dineroARecaudar - precio;
                                modifica(listaPluses, plus, dineroARecaudar * (-1));
                            }
                        }
                    }
                    max = 0.5; // reiniciamos o maximo
                }
                printf("Plus cobrado.\n");
            }
        } else {
            printf("Valor no valido.\n");
        }
    } else {
        printf("La lista de pluses esta vacia.\n");
    }
}