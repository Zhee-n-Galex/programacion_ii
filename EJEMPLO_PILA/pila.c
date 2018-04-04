#include <stdlib.h>

#define MAX 100 /* num max de elementos que podra almacenar la pila */

typedef int TELEMENTO; /* tipo de datos correspondiente a los elementos de la pila */

typedef struct {
    TELEMENTO arrayelementos[MAX];
    int cima;
} STPILA;

typedef STPILA* TPILA;

void PilaVacia (TPILA *p) {
    *p = (TPILA) malloc (sizeof(STPILA));
    (*p)->cima = -1; /* valor asignado para indicar que la pila esta vacia */
}

int EsLlena (TPILA p) {
    return (p->cima == MAX - 1) ? 1 : 0;
}

int EsVacia (TPILA p) {
    return (p->cima == -1) ? 1 : 0;
}

void Push (TPILA *p, TELEMENTO e) {
    int resp = EsLlena(*p);
    if (resp == 1)
        printf("ERROR, la pila esta llena\n");
    else {
        (*p)->cima++;
        (*p)->arrayelementos[(*p)->cima] = e;
    }
}

void Cima(TPILA p, TELEMENTO *pe) {
    int respuesta = EsVacia(p);
    if (respuesta == 1)
        printf("ERROR, la pila no tiene elementos");
    else
        *pe = p->arrayelementos[p->cima];
}

void Pop (TPILA *p) {
    int respuesta = EsVacia(*p);
    if (respuesta == 1)
        printf("ERROR, la pila no tiene elementos\n");
    else
        (*p)->cima = (*p)->cima - 1;
}