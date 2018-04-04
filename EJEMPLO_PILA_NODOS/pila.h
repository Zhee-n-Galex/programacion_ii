//
// Created by Alex on 22/02/2018.
//

typedef int TELEMENTO;

typedef struct nodo {
    TELEMENTO dato;
    struct nodo * sig;
} TNodo;

typedef TNodo * TPILA;

void PilaVacia (TPILA *p);

int EsVacia (TPILA p);

void Push (TPILA *p, TELEMENTO e);

void Cima (TPILA p, TELEMENTO *e);

void Pop (TPILA *p);

void DestruyePila (TPILA *p);
