#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main() {
    TPILA p = NULL;
    TELEMENTO e;
    short menu = 0;

    while (menu != 8) {
        printf("1.- Crear pila.\n");
        printf("2.- Comprobar pila vacia\n");
        printf("3.- Meter elemento en pila.\n");
        printf("4.- Ver elemento de la cima.\n");
        printf("5.- Sacar elemento de pila.\n");
        printf("8.- Salir.\n");
        printf("Seleccione una opcion: ");
        fflush(stdin);
        scanf("%hd", &menu);
        switch (menu) {
            case 1:
                PilaVacia(&p);
                break;
            case 2:
                if (EsVacia(p) == 1)
                    printf("La pila esta vacia.\n");
                else
                    printf("La pila no esta vacia.\n");
                break;
            case 3:
                printf("Indique el elemento que desea introducir en la pila: ");
                scanf("%d", &e);
                Push(&p, e);
                break;
            case 4:
                Cima(p, &e);
                printf("%d\n", e);
                break;
            case 5:
                Pop(&p);
                break;
            case 8:
                break;
            default:
                printf("Seleccione una opcion valida\n");
                break;
        }
    }
    return 0;
}